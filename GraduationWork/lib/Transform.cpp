#include "Transform.h"
#include "Function.h"

Transform::Transform() : 
    position(VGet(0.0f,0.0f,0.0f)), quaternion(), scale(VGet(1.0f, 1.0f, 1.0f)),
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
    // 移動量を算出
    VECTOR dif = _pos - position;

    // 自分の座標を代入
    position = _pos;

    // 移動した量だけ子の座標を加算
    for (auto child : gameObject->GetChildren()) {
        child->transform->AddPosition(dif);
    }
}

void Transform::AddPosition(VECTOR _add)
{
    // 自分の座標を加算
    position += _add;

    // 子の座標を加算
    for (auto child : gameObject->GetChildren()) {
        child->transform->AddPosition(_add);
    }
}

void Transform::AxisRotateX(float _deg)
{
    VECTOR vec = { 1.0f, 0.0f, 0.0f };
    Rotate(vec, _deg);
}

void Transform::AxisRotateY(float _deg)
{
    VECTOR vec = { 0.0f, 1.0f, 0.0f };
    Rotate(vec, _deg);
}

void Transform::AxisRotateZ(float _deg)
{
    VECTOR vec = { 0.0f, 0.0f, 1.0f };
    Rotate(vec, _deg);
}

void Transform::Rotate(VECTOR _axis, float _deg)
{
    VECTOR vec = VNorm(_axis);
    Quaternion affter = Quaternion::CreateRotatedQuaternion(_axis, position, _deg);
    VECTOR affterPos = { affter.x, affter.y, affter.z };

    SetPosition(affterPos);
}

VECTOR Transform::GetForward() const
{
    return quaternion.GetForword();
}

VECTOR Transform::GetUp() const
{
    return quaternion.GetUp();
}
