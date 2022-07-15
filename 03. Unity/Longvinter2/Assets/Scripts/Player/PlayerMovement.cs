using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float MoveSpeed = 2f;

    private Rigidbody _rigidbody;
    private PlayerController _playerController;

    void Awake()
    {
        _rigidbody = GetComponent<Rigidbody>();
        _playerController = GetComponent<PlayerController>();
    }

    void FixedUpdate()
    {
        float xSpeed = _playerController.X * MoveSpeed;
        float zSpeed = _playerController.Z * MoveSpeed;

        _rigidbody.velocity = new Vector3(xSpeed, 0f, zSpeed);        
    }
}
