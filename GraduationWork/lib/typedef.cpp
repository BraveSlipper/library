#include "typedef.h"
#include "Function.h"
#include <cmath>

Quaternion UrLib::Quaternion::Create(VECTOR _axis, float _deg)
{
    VECTOR vec = VNorm(_axis);
    float rad = ToRadian(_deg);
    Quaternion q;
    q.w = cos(rad / 2.0f);
    q.x = vec.x * sin(rad / 2.0f);
    q.y = vec.y * sin(rad / 2.0f);
    q.z = vec.z * sin(rad / 2.0f);
    q.up = { q.x, q.y, q.z };
    q.up = VNorm(q.up);

    return q;
}

Quaternion UrLib::Quaternion::RotatePosition(VECTOR _axis, VECTOR _pos, float _deg)
{
    Quaternion q = Quaternion::Create(_axis, _deg);
    Quaternion r = Quaternion::Create(_axis * -1.0f, _deg);
    Quaternion p;
    p.x = _pos.x;
    p.y = _pos.y;
    p.z = _pos.z;
    p.w = 0.0f;

    Quaternion affter = r * p * q;
    VECTOR newPos = { affter.x, affter.y, affter.z };
    affter.up = VNorm(newPos);

    return affter;
}
