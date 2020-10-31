#include "Collider2D.h"
#include "CollideManager.h"
#include "typedef.h"
#include "Function.h"
#include "Transform.h"

Collider2D::Collider2D() : 
	rotation(0.0f)
{
	CollideManager::Get()->PushCollider2D(this);
}

Collider2D::~Collider2D()
{
	CollideManager::Get()->RemoveCollider2D(this);
}

void Collider2D::ExecuteAllCollisionEnter(Collider2D* _collider)
{
	std::list<Component*> obj_1 = GetComponentAll();
	std::list<Component*> obj_2 = GetComponentAll();
	for (auto it : obj_1) {
		it->OnCollisionEnter2D(_collider);
	}
	for (auto it : obj_2) {
		it->OnCollisionEnter2D(_collider);
	}
}

void Collider2D::ExecuteAllCollisionStay(Collider2D* _collider)
{
	std::list<Component*> obj_1 = GetComponentAll();
	std::list<Component*> obj_2 = GetComponentAll();
	for (auto it : obj_1) {
		it->OnCollisionStay2D(_collider);
	}
	for (auto it : obj_2) {
		it->OnCollisionStay2D(_collider);
	}
}

void Collider2D::ExecuteAllCollisionExit(Collider2D* _collider)
{
	std::list<Component*> obj_1 = GetComponentAll();
	std::list<Component*> obj_2 = GetComponentAll();
	for (auto it : obj_1) {
		it->OnCollisionExit2D(_collider);
	}
	for (auto it : obj_2) {
		it->OnCollisionExit2D(_collider);
	}
}

VECTOR2 Collider2D::GetLocalPosition()
{
	return position;
}

VECTOR2 Collider2D::GetWorldPosition()
{
	VECTOR2 pos = position;
	pos.x += transform->position.x;
	pos.y += transform->position.y;
	return pos;
}

void Collider2D::SetPosition(VECTOR2 _pos)
{
	position = _pos;
}

float Collider2D::GetRotate()
{
	// ToDo
	return rotation;
}

void Collider2D::Rotate(float _deg)
{
	// ToDo
	rotation += _deg;
	LoopClamp(rotation, 0.0f, 360.0f);
}
