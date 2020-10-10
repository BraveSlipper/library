#include "Transform.h"

Transform::Transform(GameObject* _actor) :
    Component(_actor), 
    position(VGet(0.0f,0.0f,0.0f)), rotation(VGet(0.0f, 0.0f, 0.0f)), scale(VGet(1.0f, 1.0f, 1.0f)),
    forward(VGet(0.0f, 0.0f, 1.0f)), up(VGet(0.0f, 1.0f, 0.0f))
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
    return forward;
}

VECTOR Transform::GetUp() const
{
    return up;
}
