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

    return affter;
}

Quaternion UrLib::Quaternion::RotatePosition(VECTOR _axis, Quaternion& _pos, float _deg)
{
    // �p�x��Radian�ɒ���
    float rad = ToRadian(_deg);

    // ��]���Ɠ����x�N�g���́A�Ђ˂邾��
    if (_axis == _pos.GetVec()) {
        _pos.w += rad;
        LoopClamp(_pos.w, 0.0f, 360.0f);
    }

    // ��]���𐶐����A�ړ���̍��W���Z�o
    Quaternion q = Quaternion::Create(_axis, _deg);
    Quaternion r = Quaternion::Create(_axis * -1.0f, _deg);
    Quaternion p;
    p.x = _pos.x;
    p.y = _pos.y;
    p.z = _pos.z;
    p.w = 0.0f;

    _pos = r * p * q;

    return _pos;
}
