using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;

public enum QNodeIndex
{
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight,
    Borderline, // 경계선
    OutOfBounds
}

public class QNode
{
    private QuadTree _tree;
    private int _depth = 0;
    private List<QNode> _children;
    private List<BoxCollider> _colliders = new();
    public Bounds Bounds { get; private set; }

    public QNode(QuadTree tree, int depth, Bounds bounds)
    {
        _tree = tree;
        _depth = depth;
        Bounds = bounds;
    }

    public void Insert(BoxCollider collider)
    {
        Bounds newBounds = collider.bounds;

        QNodeIndex region = TestRegion(newBounds);
        if (region == QNodeIndex.OutOfBounds)
        {
            return;
        }
        
        if (region == QNodeIndex.Borderline)
        {
            _colliders.Add(collider);
            return;
        }

        Split();
        _children[(int)region].Insert(collider);
    }

    public void Query(BoxCollider collider, List<QNode> possibleNodes)
    {
        possibleNodes.Add(this);

        if (IsSplitted == false)
        {
            return;
        }

        List<QNodeIndex> quads = GetQuads(collider.bounds);
        foreach (QNodeIndex index in quads)
        {
            _children[(int)index].Query(collider, possibleNodes);
        }
    }

    public List<BoxCollider> GetIntersections(BoxCollider collider)
    {
        List<BoxCollider> intersects = new();
        foreach (var item in _colliders)
        {
            if (collider.bounds.Intersects(item.bounds))
            {
                intersects.Add(item);
            }
        }

        return intersects;
    }

    private void Split()
    {
        if (IsSplitted)
        {
            return;
        }

        Vector3 halfExtents = Bounds.extents / 2f;
        _children = new List<QNode>
        {
            new QNode(_tree, _depth + 1, new Bounds(Bounds.center + new Vector3(-halfExtents.x, halfExtents.y), Bounds.extents)),
            new QNode(_tree, _depth + 1, new Bounds(Bounds.center + new Vector3(halfExtents.x, halfExtents.y), Bounds.extents)),
            new QNode(_tree, _depth + 1, new Bounds(Bounds.center + new Vector3(-halfExtents.x, -halfExtents.y), Bounds.extents)),
            new QNode(_tree, _depth + 1, new Bounds(Bounds.center + new Vector3(halfExtents.x, -halfExtents.y), Bounds.extents))
        };
    }

    private QNodeIndex TestRegion(Bounds newBounds)
    {
        List<QNodeIndex> quads = GetQuads(newBounds);

        if (quads.Count == 0)
        {
            return QNodeIndex.OutOfBounds;
        }
        else if (quads.Count == 1)
        {
            return quads[0];
        }
        else
        {
            return QNodeIndex.Borderline;
        }
    }

    private List<QNodeIndex> GetQuads(Bounds newBounds)
    {
        List<QNodeIndex> quads = new List<QNodeIndex>();

        bool isNegativeX = newBounds.min.x <= Bounds.center.x;
        bool isNegativeY = newBounds.min.y <= Bounds.center.y;
        bool isPositiveX = newBounds.max.x >= Bounds.center.x;
        bool isPositiveY = newBounds.max.y >= Bounds.center.y;
        
        if (isNegativeX && isPositiveY)
        {
            quads.Add(QNodeIndex.TopLeft);
        }

        if (isPositiveX && isPositiveY)
        {
            quads.Add(QNodeIndex.TopRight);
        }

        if (isNegativeX && isNegativeY)
        {
            quads.Add(QNodeIndex.BottomLeft);
        }

        if (isPositiveX && isNegativeY)
        {
            quads.Add(QNodeIndex.BottomRight);
        }

        return quads;
    }

    public void DrawBounds()
    {
        Gizmos.DrawWireCube(Bounds.center, Bounds.size);
    }

    public void DrawNode()
    {
        DrawBounds();
        Handles.Label(Bounds.center, _colliders.Count.ToString());

        if (_children != null)
        {
            foreach (var child in _children)
            {
                child.DrawNode();
            }
        }

    }

    private bool IsSplitted => _children != null && _children.Count > 0;
}