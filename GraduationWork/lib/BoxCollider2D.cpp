#include "BoxCollider2D.h"
#include "UrLib.h"
#include "CircleCollider2D.h"

BoxCollider2D::BoxCollider2D() :
	height(1.0f), width(1.0f)
{
}

BoxCollider2D::~BoxCollider2D()
{
}

bool BoxCollider2D::IsCollide(Collider2D* _collider)
{
	CircleCollider2D* col_c = dynamic_cast<CircleCollider2D*>(_collider);
	BoxCollider2D* col_b = dynamic_cast<BoxCollider2D*>(_collider);
	if (col_c != nullptr) {	// 対象がCircleColliderの時
		return IsCollideCircle(col_c);
	}
	else if (col_b != nullptr) { // 対象がBoxColliderの時
		return IsCollideBox(col_b);
	}
	return false;
}

float BoxCollider2D::GetHeight() const
{
	return height;
}

float BoxCollider2D::GetWidth() const
{
	return width;
}

void BoxCollider2D::SetSize(float _hight, float _width)
{
	height = _hight;
	width = _width;
}

bool BoxCollider2D::IsCollideCircle(CircleCollider2D* _collider)
{
	return false;
	//// 矩形０度の時の座標に円の角度を直す
	//VECTOR circle = _collider->transform->position;
	//float radian = ToRadian(_collider->transform->rotate.z);
	//VECTOR rect = transform->position;
	//VECTOR c;

	//c.x = static_cast<float>(cos(radian) * ((double)circle.x - (double)rect.x) - sin(radian) * ((double)circle.y - (double)rect.y) + rect.x);
	//c.y = static_cast<float>(sin(radian) * ((double)circle.x - (double)rect.x) + cos(radian) * ((double)circle.y - (double)rect.y) + rect.y);

	//// 上の円の中心点から矩形の１番近い座標
	//VECTOR ver;

	//// 短径の頂点座標
	//float left = rect.x - width * 0.5f;
	//float right = rect.x + width * 0.5f;
	//float up = rect.y - height * 0.5f;
	//float down = rect.y + height * 0.5f;

	//// １番近いx座標を求める
	//if (c.x < rect.x)
	//	ver.x = rect.x - width * 0.5f;
	//else if (c.x > rect.x)
	//	ver.x = rect.x + width * 0.5f;
	//else
	//	ver.x = c.x;

	//// １番近いy座標を求める
	//if (c.y < rect.y)
	//	ver.y = rect.y - height * 0.5f;
	//else if (c.y > rect.y)
	//	ver.y = rect.y + height * 0.5f;
	//else
	//	ver.y = c.y;

	//// 一番近い角丸との衝突判定
	//float radius = _collider->GetRadius();
	//float distance = VSize(c - ver);
	//if (distance < radius)
	//	return true; // 衝突

	//// 円の中心点と長方形のあたり判定
	//bool a = c.x > left && c.x < right&& c.y > up - radius && c.y < down + radius;
	//bool b = c.x > left - radius && c.x < right + radius && c.y > up && c.y < down;
	//if (a || b)  return true;
	//else return false;
}

bool BoxCollider2D::IsCollideBox(BoxCollider2D* _collider)
{
	// 自分の短径の頂点座標
	VECTOR myPos = transform->position;
	float left = myPos.x - width * 0.5f;
	float right = myPos.x + width * 0.5f;
	float up = myPos.y - height * 0.5f;
	float down = myPos.y + height * 0.5f;

	// 相手の短径の頂点座標
	VECTOR pairPos = _collider->transform->position;
	float pairHeight = _collider->GetHeight();
	float pairWidth = _collider->GetWidth();
	float pairLeft = pairPos.x - pairWidth * 0.5f;
	float pairRight = pairPos.x + pairWidth * 0.5f;
	float pairUp = pairPos.y - pairHeight * 0.5f;
	float pairDown = pairPos.y + pairHeight * 0.5f;

	// 短径と短径の衝突判定
	if (left < pairRight &&
		right > pairLeft &&
		up < pairDown &&
		down > pairUp)
		return true; // 衝突

	return false;
}
