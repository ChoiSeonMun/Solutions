using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HelicopterMovement : MonoBehaviour
{
    public float GoUpSpeed = 1.2f;
    public float RotationSpeed = 1.5f;
    public float MaxPropellerSpeed = 10f;
    public GameObject Propeller;
    public GameObject TailPropeller;

    private HelicopterInput _input;
    private Rigidbody _rigidbody;
    private bool _isTurnOn = false;

    void Awake()
    {
        _input = GetComponent<HelicopterInput>();
        _rigidbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        if (_input.HasPushedEngineStart)
        {
            _isTurnOn = !_isTurnOn;
        }

        if (_isTurnOn)
        {
            onTurnOn();
        }
        else
        {
            onTurnOff();
        }
    }

    private float _propellerSpeed = 0f;
    private void onTurnOn()
    {
        _propellerSpeed = Mathf.Lerp(_propellerSpeed, MaxPropellerSpeed, Time.deltaTime);
        rotatePropellers();

        if (MaxPropellerSpeed - _propellerSpeed > 0.5f)
        {
            return;
        }

        if (_rigidbody.useGravity)
        {
            _rigidbody.useGravity = false;
        }

        if (_input.Y == 0)
        {
            _rigidbody.velocity = Vector3.zero;
        }
        else
        {
            _rigidbody.AddForce(0f, _input.Y * GoUpSpeed, 0f);
        }

        transform.Rotate(0f, _input.X * RotationSpeed, 0f);
    }

    

    private void onTurnOff()
    {
        _propellerSpeed = Mathf.Lerp(_propellerSpeed, 0f, Time.deltaTime);
        rotatePropellers();

        if (_rigidbody.useGravity == false)
        {
            _rigidbody.useGravity = true;
        }
    }

    private void rotatePropellers()
    {
        Propeller.transform.Rotate(0f, _propellerSpeed, 0f);
        TailPropeller.transform.Rotate(_propellerSpeed, 0f, 0f);
    }
}
