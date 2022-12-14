using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoTurret : MonoBehaviour
{
    public float RotationSpeed = 5f;
    public float AttackCooltime = 0.5f;
    public GameObject BulletPrefab;
    public Transform BulletSpawnSpot;

    private AutoTargetting _autoTargetting;
    private float _elapsedTime;

    void Awake()
    {
        _autoTargetting = GetComponentInChildren<AutoTargetting>();
    }

    // Update is called once per frame
    void Update()
    {
        if (_autoTargetting.IsTargetOn)
        {
            onTargetOn();
        }
        else
        {
            onIdle();
        }
    }

    void onIdle()
    {
        _elapsedTime = AttackCooltime;
        transform.Rotate(0f, RotationSpeed * Time.deltaTime, 0f);
    }

    void onTargetOn()
    {
        transform.LookAt(_autoTargetting.Target.transform);

        _elapsedTime += Time.deltaTime;
        if (_elapsedTime >= AttackCooltime)
        {
            _elapsedTime = 0f;
            Instantiate(BulletPrefab, BulletSpawnSpot.position, BulletSpawnSpot.rotation);
        }
    }
}
