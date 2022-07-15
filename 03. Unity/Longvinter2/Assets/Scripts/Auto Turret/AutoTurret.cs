using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoTurret : MonoBehaviour
{
    public float RotationSpeed = 5f;
    public float AttackCooltime = 0.5f;
    public GameObject BulletPrefab;
    public Transform BulletSpawnSpot;
    public Transform Body;

    private AutoTargetting _autoTargetting;
    private float _elapsedTime;

    void Start()
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
        Body.Rotate(0f, RotationSpeed * Time.deltaTime, 0f);
    }

    void onTargetOn()
    {
        Body.LookAt(_autoTargetting.Target.transform);

        _elapsedTime += Time.deltaTime;
        if (_elapsedTime >= AttackCooltime)
        {
            _elapsedTime = 0f;
            Instantiate(BulletPrefab, BulletSpawnSpot.position, BulletSpawnSpot.rotation);
        }
    }
}
