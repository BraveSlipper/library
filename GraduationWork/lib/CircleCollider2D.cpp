#include "CircleCollider2D.h"
#include "UrLib.h"
#include "BoxCollider2D.h"

CircleCollider2D::CircleCollider2D() :
	radius(1.0f)
{
}

CircleCollider2D::~CircleCollider2D()
{
}

bool CircleCollider2D::IsCollide(Collider2D* _collider)
{
	CircleCollider2D* col_c = dynamic_cast<CircleCollider2D*>(_collider);
	BoxCollider2D* col_b = dynamic_cast<BoxCollider2D*>(_collider);
	if (col_c != nullptr) {	// ‘ÎÛ‚ªCircleCollider‚Ì
		return IsCollideCircle(col_c);
	}
	else if (col_b != nullptr) { // ‘ÎÛ‚ªBoxCollider‚Ì
		return IsCollideBox(col_b);
	}
	return false;
}

bool CircleCollider2D::IsCollideCircle(CircleCollider2D* _collider)
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

bool CircleCollider2D::IsCollideBox(BoxCollider2D* _collider)
{
	return false;
	//// ‹éŒ`‚O“x‚Ì‚ÌÀ•W‚É‰~‚ÌŠp“x‚ğ’¼‚·
	//VECTOR origin_c = transform->position;
	//float radian = ToRadian(transform->rotate.z);
	//VECTOR rect = _collider->transform->position;
	//VECTOR c;

	//c.x = cos(radian) * (origin_c.x - rect.x) - sin(radian) * (origin_c.y - rect.y) + rect.x;
	//c.y = sin(radian) * (origin_c.x - rect.x) + cos(radian) * (origin_c.y - rect.y) + rect.y;

	//// ã‚Ì‰~‚Ì’†S“_‚©‚ç‹éŒ`‚Ì‚P”Ô‹ß‚¢À•W
	//VECTOR ver;

	//// ’ZŒa‚Ì’¸“_À•W
	//float height = _collider->GetHeight();
	//float width = _collider->GetWidth();
	//float left = rect.x - width * 0.5f;
	//float right = rect.x + width * 0.5f;
	//float up = rect.y - height * 0.5f;
	//float down = rect.y + height * 0.5f;

	//// ‚P”Ô‹ß‚¢xÀ•W‚ğ‹‚ß‚é
	//if (c.x < rect.x)
	//	ver.x = left;
	//else if (c.x > rect.x)
	//	ver.x = right;
	//else
	//	ver.x = c.x;

	//// ‚P”Ô‹ß‚¢yÀ•W‚ğ‹‚ß‚é
	//if (c.y < rect.y)
	//	ver.y = up;
	//else if (c.y > rect.y)
	//	ver.y = down;
	//else
	//	ver.y = c.y;

	//// ˆê”Ô‹ß‚¢ŠpŠÛ‚Æ‚ÌÕ“Ë”»’è
	//float distance = VSize(c - ver);
	//if (distance < radius)
	//	return true; // Õ“Ë

	//// ‰~‚Ì’†S“_‚Æ’·•ûŒ`‚Ì‚ ‚½‚è”»’è
	//bool a = c.x > left && c.x < right&& c.y > up - radius && c.y < down + radius;
	//bool b = c.x > left - radius && c.x < right + radius && c.y > up && c.y < down;
	//if (a || b)  return true;
	//else return false;
}
