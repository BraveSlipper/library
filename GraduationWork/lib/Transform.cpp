#include "Transform.h"
#include "Function.h"

Transform::Transform() : 
    position(VGet(0.0f,0.0f,0.0f)), rotation(), scale(VGet(1.0f, 1.0f, 1.0f)),
    foward(VGet(0.0f, 0.0f, 1.0f)), right(VGet(1.0f, 0.0f, 0.0f))
{
}

Transform::~Transform()
{
}

void Transform::Start()
{
}

void Transform::Update()
{
}

void Transform::SetPosition(VECTOR _pos)
{
    // �ړ��ʂ��Z�o
    VECTOR dif = _pos - position;

    // �����̍��W����
    position = _pos;

    // �ړ������ʂ����q�̍��W�����Z
    for (auto child : gameObject->GetChildren()) {
        child->transform->AddPosition(dif);
    }
}

void Transform::AddPosition(float _x, float _y, float _z)
{
    // �����̍��W�����Z
    VECTOR add = VGet(_x, _y, _z);
    position += add;

    // �q�̍��W�����Z
    for (auto child : gameObject->GetChildren()) {
        child->transform->AddPosition(add);
    }
}

void Transform::AddPosition(VECTOR _add)
{
    // �����̍��W�����Z
    position += _add;

    // �q�̍��W�����Z
    for (auto child : gameObject->GetChildren()) {
        child->transform->AddPosition(_add);
    }
}

void Transform::AxisRotateX(float _deg)
{
    VECTOR vec = { 1.0f, 0.0f, 0.0f };
    rotation.x -= _deg;
    LoopClamp(rotation.x, 0.0f, 360.0f);
    Rotate(vec, _deg);
}

void Transform::AxisRotateY(float _deg)
{
    VECTOR vec = { 0.0f, 1.0f, 0.0f };
    rotation.y -= _deg;
    LoopClamp(rotation.y, 0.0f, 360.0f);
    Rotate(vec, _deg);
}

void Transform::AxisRotateZ(float _deg)
{
    VECTOR vec = { 0.0f, 0.0f, 1.0f };
    rotation.z -= _deg;
    LoopClamp(rotation.z, 0.0f, 360.0f);
    Rotate(vec, _deg);
}

void Transform::Rotate(VECTOR _axis, float _deg)
{
    VECTOR vec = VNorm(_axis);
    Quaternion affter;

    // �q�̍��W���X�V
    for (auto child : gameObject->GetChildren()) {
        VECTOR dif = child->transform->position - position;
        affter = Quaternion::RotatePosition(_axis, dif, _deg);
        child->transform->position = affter.GetVec() + position;
        child->transform->Rotate(_axis, _deg);
    }
}

VECTOR Transform::GetForward() const
{
    return rotation.GetForword();
}

VECTOR Transform::GetUp() const
{
    return rotation.GetUp();
}
