using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoTargetting : MonoBehaviour
{
    public bool IsTargetOn { get; private set; }
    public GameObject Target { get; private set; }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
        {
            IsTargetOn = true;
            Target = other.gameObject;
        }
    }

    void OnTriggerExit(Collider other)
    {
        IsTargetOn = false;
        Target = null;
    }
}
