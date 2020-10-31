#include "SphereCollider.h"
#include "UrLib.h"
#include "BoxCollider.h"

SphereCollider::SphereCollider() :
	radius(1.0f)
{
}

SphereCollider::~SphereCollider()
{
}

void SphereCollider::Disp()
{
	// ToDo
	VECTOR pos = GetWorldPosition();
	DrawCircle(pos.x, pos.y, radius, GetColor(255, 255, 255));
}

bool SphereCollider::IsCollide(Collider3D* _collider)
{
	SphereCollider* col_c = dynamic_cast<SphereCollider*>(_collider);
	BoxCollider* col_b = dynamic_cast<BoxCollider*>(_collider);
	if (col_c != nullptr) {	// 対象がCircleColliderの時
		return IsCollideCircle(col_c);
	}
	else if (col_b != nullptr) { // 対象がBoxColliderの時
		return IsCollideBox(col_b);
	}
	return false;
}

bool SphereCollider::IsCollideCircle(SphereCollider* _collider)
{
	VECTOR pos1 = _collider->GetWorldPosition();
	VECTOR pos2 = GetWorldPosition();
	VECTOR diff = pos1 - pos2;
	float dist = VSize(diff);
	if (dist <= _collider->GetRadius() + this->radius) {
		return true;
	}

	return false;
}

bool SphereCollider::IsCollideBox(BoxCollider* _collider)
{
	return false;
}
