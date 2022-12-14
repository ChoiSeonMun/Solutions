using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    public Transform Target;

    private Vector3 _distance;
    // Start is called before the first frame update
    void Start()
    {
        _distance = Target.position - transform.position;
    }

    void LateUpdate()
    {
        transform.position = Target.position - _distance;    
    }
}
