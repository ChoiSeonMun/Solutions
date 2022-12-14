using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class AutoTargetting : MonoBehaviour
{
    public bool IsTargetOn { get; private set; }
    public GameObject Target { get; private set; }

    void OnTriggerStay(Collider other)
    {
        IsTargetOn = false;
        Target = null;

        if (other.tag == "Player")
        {
            if (canShot(other.transform.position))
            {
                IsTargetOn = true;
                Target = other.gameObject;
            }
        }
    }

    void OnTriggerExit(Collider other)
    {
        IsTargetOn = false;
        Target = null;
    }

    private bool canShot(Vector3 targetPosition)
    {
        Vector3 distanceVector = targetPosition - transform.position;
        
        Vector3 normalVector = Vector3.Cross(transform.forward, distanceVector);
        if (normalVector.y > 0)
        {
            return false;
        }

        // 아래의 코드도 사용할 수 있다.
        // float angle = Vector3.Angle(transform.forward, distanceVector);
        // if (30f <= angle && angle <= 90f)
        // {
        //     return true;
        // }

        float dotResult = Vector3.Dot(transform.forward, distanceVector.normalized);
        if (dotResult < 0f || dotResult > 0.866f)
        {
            return false;
        }

        return true;
    }

    private Vector3 _arcStartVector;
    void Start()
    {
        float angle = 150f - transform.eulerAngles.y;
        float x = Mathf.Cos(angle * Mathf.Deg2Rad);
        float z = Mathf.Sin(angle * Mathf.Deg2Rad);
        
        _arcStartVector = new Vector3(x, 0f, z);   
    }

    private Color _red = new Color(1f, 0f, 0f, 0.1f);
    private Color _blue = new Color(0f, 0f, 1f, 0.1f);
    void OnDrawGizmos()
    {
        
        Handles.color = IsTargetOn ? _red : _blue;
        Handles.DrawSolidArc(transform.position, transform.up, _arcStartVector, -30f, 20f);
        Handles.DrawSolidArc(transform.position, transform.up, _arcStartVector, 30f, 20f);
    }
}
