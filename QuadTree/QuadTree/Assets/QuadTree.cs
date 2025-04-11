using System.Collections.Generic;
using UnityEngine;

public class QuadTree
{
    private QNode _root;

    public QuadTree(Vector2 size)
    {
        _root = new QNode(this, 0, new Bounds(Vector3.zero, size));
    }

    public void Insert(BoxCollider newItem)
    {
        _root.Insert(newItem);
    }

    public List<BoxCollider> Query(BoxCollider queryItem, List<QNode> possibleNodes)
    {
        _root.Query(queryItem, possibleNodes);

        List<BoxCollider> intersects = new();
        foreach (var node in possibleNodes)
        {
            intersects.AddRange(node.GetIntersections(queryItem));
        }

        return intersects;
    }

    public void DrawBounds()
    {
        _root.DrawNode();
    }

   
}