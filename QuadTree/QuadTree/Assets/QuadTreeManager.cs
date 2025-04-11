using System.Collections.Generic;
using UnityEngine;

public class QuadTreeManager : MonoBehaviour
{
    [SerializeField] private Vector2 _totalArea = new Vector2(64f, 64f);

    private QuadTree _quadTree;
    private GameObject[] _insertItems;
    private GameObject[] _queryItems;

    private void Awake()
    {
        _quadTree = new QuadTree(_totalArea);
        _insertItems = GameObject.FindGameObjectsWithTag("Insert");
        _queryItems = GameObject.FindGameObjectsWithTag("Query");
    }

    private int _insertIndex = 0;
    public void Insert()
    {
        if (_insertIndex >= _insertItems.Length)
        {
            return;
        }

        _quadTree.Insert(_insertItems[_insertIndex].GetComponent<BoxCollider>());
        ++_insertIndex;
    }

    private int _queryIndex = 0;
    private List<BoxCollider> _intersectObjects;
    private List<QNode> _possibleNodes;
    public void Query()
    {
        if (_queryIndex >= _queryItems.Length)
        {
            return;
        }

        _possibleNodes = new List<QNode>();
        _intersectObjects = _quadTree.Query(_queryItems[_queryIndex++].GetComponent<BoxCollider>(), _possibleNodes);
    }

    private void OnDrawGizmos()
    {
        Gizmos.color = Color.gray;
        Gizmos.DrawWireCube(Vector3.zero, _totalArea);
        
        _quadTree?.DrawBounds();

        Gizmos.color = Color.cyan;
        for (int i = 0; i < _insertIndex; ++i)
        {
            Bounds bounds = _insertItems[i].GetComponent<BoxCollider>().bounds;            
            Gizmos.DrawCube(bounds.center, bounds.size);
        }

        if (HasCandidateToInsert)
        {
            Bounds bounds = _insertItems[_insertIndex].GetComponent<BoxCollider>().bounds;
            Gizmos.color = Color.red;
            Gizmos.DrawCube(bounds.center, bounds.size);
        }

            if (HasCandidateToQuery)
            {
                Gizmos.color = Color.blue;
                Bounds bounds = _queryItems[_queryIndex].GetComponent<BoxCollider>().bounds;
                Gizmos.DrawWireCube(bounds.center, bounds.size);
            }

            if (_queryIndex > 0)
            {
                Gizmos.color = Color.yellow;
                Bounds bounds = _queryItems[_queryIndex - 1].GetComponent<BoxCollider>().bounds;
                Gizmos.DrawWireCube(bounds.center, bounds.size);
            }

            Gizmos.color = Color.magenta;
            if (_possibleNodes != null)
            {
                foreach (var node in _possibleNodes)
                {
                    node.DrawBounds();
                }
            }

            if (_intersectObjects != null)
            {
                foreach (var obj in _intersectObjects)
                {
                    Gizmos.DrawCube(obj.bounds.center, obj.bounds.size);
                }
            }
    }

    private bool HasCandidateToInsert => _insertItems != null && _insertIndex < _insertItems.Length;
    private bool HasCandidateToQuery => _queryItems != null && _queryIndex < _queryItems.Length;
}
