#include "Transform.h"
#include "Function.h"

Transform::Transform() : 
    position(VGet(0.0f,0.0f,0.0f)), scale(VGet(1.0f, 1.0f, 1.0f)),
    foward(0.0f, 0.0f, 1.0f, 0.0f), right(1.0f, 0.0f, 0.0f, 0.0f), up(0.0f, 1.0f, 0.0f, 0.0f)
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

void Transform::AddPosition(float _x, float _y, float _z)
{
    // 自分の座標を加算
    VECTOR add = VGet(_x, _y, _z);
    position += add;

    // 子の座標を加算
    for (auto child : gameObject->GetChildren()) {
        child->transform->AddPosition(add);
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

    // 自分の向きを更新
    Quaternion::RotatePosition(_axis, foward, _deg);
    Quaternion::RotatePosition(_axis, right, _deg);
    Quaternion::RotatePosition(_axis, up, _deg);

    // 子の座標を更新
    for (auto child : gameObject->GetChildren()) {
        Quaternion quaChild;
        VECTOR dif = child->transform->position - position;
        quaChild = Quaternion::RotatePosition(_axis, dif, _deg);
        child->transform->SetPosition(quaChild.GetVec() + position);
        child->transform->Rotate(_axis, _deg);
    }
}

VECTOR Transform::GetForward() const
{
    return foward.GetVec();
}

VECTOR Transform::GetRight() const
{
    return right.GetVec();
}

VECTOR Transform::GetUp() const
{
    return up.GetVec();
}
