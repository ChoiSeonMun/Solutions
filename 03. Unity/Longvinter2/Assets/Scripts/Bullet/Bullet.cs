using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public float MoveSpeed = 5f;

    void Start()
    {
        Destroy(gameObject, 5f);       
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(0f, 0f, MoveSpeed * Time.deltaTime);
    }
}
