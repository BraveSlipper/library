#include "Transform.h"
#include "Function.h"

Transform::Transform() : 
    position(VGet(0.0f,0.0f,0.0f)), rotation(VGet(0.0f, 0.0f, 0.0f)), scale(VGet(1.0f, 1.0f, 1.0f)),
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

VECTOR Transform::GetForward() const
{
    return VECTOR();//localAxis.z;
}

VECTOR Transform::GetUp() const
{
    return VECTOR();//localAxis.y;
}

Transform Transform::GetWorldTransform()
{
    Transform tr = *this;
    SetWorldPosition(tr.gameObject->GetParent(), tr.position);

    return tr;
}

void Transform::SetWorldPosition(GameObject* _parent, VECTOR& _pos)
{
    if (_parent == nullptr) return;

    // 親のワールド座標を加算
    _pos += _parent->transform->GetWorldTransform().position;

    // 親からの距離ベクトルを、親の回転値を見て回転させる
    VECTOR dif = _pos - _parent->transform->position;

//    SetWorldPosition(_parent->GetParent(), _pos);
}
