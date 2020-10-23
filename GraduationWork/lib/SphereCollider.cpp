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
	Transform* tr1 = _collider->transform;
	Transform* tr2 = transform;
	VECTOR diff = tr1->position - tr2->position;
	float dist = VSize(diff);
	if (dist <= _collider->GetRadius() + this->radius) {
		return true;
	}

	return false;
}

bool SphereCollider::IsCollideBox(BoxCollider* _collider)
{
	return false;
	//// 矩形０度の時の座標に円の角度を直す
	//VECTOR origin_c = transform->position;
	//float radian = ToRadian(transform->rotate.z);
	//VECTOR rect = _collider->transform->position;
	//VECTOR c;

	//c.x = cos(radian) * (origin_c.x - rect.x) - sin(radian) * (origin_c.y - rect.y) + rect.x;
	//c.y = sin(radian) * (origin_c.x - rect.x) + cos(radian) * (origin_c.y - rect.y) + rect.y;

	//// 上の円の中心点から矩形の１番近い座標
	//VECTOR ver;

	//// 短径の頂点座標
	//float height = _collider->GetHeight();
	//float width = _collider->GetWidth();
	//float left = rect.x - width * 0.5f;
	//float right = rect.x + width * 0.5f;
	//float up = rect.y - height * 0.5f;
	//float down = rect.y + height * 0.5f;

	//// １番近いx座標を求める
	//if (c.x < rect.x)
	//	ver.x = left;
	//else if (c.x > rect.x)
	//	ver.x = right;
	//else
	//	ver.x = c.x;

	//// １番近いy座標を求める
	//if (c.y < rect.y)
	//	ver.y = up;
	//else if (c.y > rect.y)
	//	ver.y = down;
	//else
	//	ver.y = c.y;

	//// 一番近い角丸との衝突判定
	//float distance = VSize(c - ver);
	//if (distance < radius)
	//	return true; // 衝突

	//// 円の中心点と長方形のあたり判定
	//bool a = c.x > left && c.x < right&& c.y > up - radius && c.y < down + radius;
	//bool b = c.x > left - radius && c.x < right + radius && c.y > up && c.y < down;
	//if (a || b)  return true;
	//else return false;
}
