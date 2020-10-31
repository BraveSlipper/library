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

void BoxCollider2D::Disp()
{
	VECTOR2 center = GetWorldPosition();
	VECTOR2 leftTop(center.x - width * 0.5f, center.y - height * 0.5f);
	VECTOR2 rightBottom(center.x + width * 0.5f, center.y + height * 0.5f);
	DrawBox(leftTop.x, leftTop.y, rightBottom.x, rightBottom.y, GetColor(255, 255, 255), FALSE);
}

bool BoxCollider2D::IsCollide(Collider2D* _collider)
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
	//// ‹éŒ`‚O“x‚Ì‚ÌÀ•W‚É‰~‚ÌŠp“x‚ğ’¼‚·
	//VECTOR circle = _collider->transform->position;
	//float radian = ToRadian(_collider->transform->rotate.z);
	//VECTOR rect = transform->position;
	//VECTOR c;

	//c.x = static_cast<float>(cos(radian) * ((double)circle.x - (double)rect.x) - sin(radian) * ((double)circle.y - (double)rect.y) + rect.x);
	//c.y = static_cast<float>(sin(radian) * ((double)circle.x - (double)rect.x) + cos(radian) * ((double)circle.y - (double)rect.y) + rect.y);

	//// ã‚Ì‰~‚Ì’†S“_‚©‚ç‹éŒ`‚Ì‚P”Ô‹ß‚¢À•W
	//VECTOR ver;

	//// ’ZŒa‚Ì’¸“_À•W
	//float left = rect.x - width * 0.5f;
	//float right = rect.x + width * 0.5f;
	//float up = rect.y - height * 0.5f;
	//float down = rect.y + height * 0.5f;

	//// ‚P”Ô‹ß‚¢xÀ•W‚ğ‹‚ß‚é
	//if (c.x < rect.x)
	//	ver.x = rect.x - width * 0.5f;
	//else if (c.x > rect.x)
	//	ver.x = rect.x + width * 0.5f;
	//else
	//	ver.x = c.x;

	//// ‚P”Ô‹ß‚¢yÀ•W‚ğ‹‚ß‚é
	//if (c.y < rect.y)
	//	ver.y = rect.y - height * 0.5f;
	//else if (c.y > rect.y)
	//	ver.y = rect.y + height * 0.5f;
	//else
	//	ver.y = c.y;

	//// ˆê”Ô‹ß‚¢ŠpŠÛ‚Æ‚ÌÕ“Ë”»’è
	//float radius = _collider->GetRadius();
	//float distance = VSize(c - ver);
	//if (distance < radius)
	//	return true; // Õ“Ë

	//// ‰~‚Ì’†S“_‚Æ’·•ûŒ`‚Ì‚ ‚½‚è”»’è
	//bool a = c.x > left && c.x < right&& c.y > up - radius && c.y < down + radius;
	//bool b = c.x > left - radius && c.x < right + radius && c.y > up && c.y < down;
	//if (a || b)  return true;
	//else return false;
}

bool BoxCollider2D::IsCollideBox(BoxCollider2D* _collider)
{
	// ©•ª‚Ì’ZŒa‚Ì’¸“_À•W
	VECTOR myPos = transform->position + position;
	float left = myPos.x - width * 0.5f;
	float right = myPos.x + width * 0.5f;
	float up = myPos.y - height * 0.5f;
	float down = myPos.y + height * 0.5f;

	// ‘Šè‚Ì’ZŒa‚Ì’¸“_À•W
	VECTOR pairPos = _collider->transform->position;
	float pairHeight = _collider->GetHeight();
	float pairWidth = _collider->GetWidth();
	float pairLeft = pairPos.x - pairWidth * 0.5f;
	float pairRight = pairPos.x + pairWidth * 0.5f;
	float pairUp = pairPos.y - pairHeight * 0.5f;
	float pairDown = pairPos.y + pairHeight * 0.5f;

	// ’ZŒa‚Æ’ZŒa‚ÌÕ“Ë”»’è
	if (left < pairRight &&
		right > pairLeft &&
		up < pairDown &&
		down > pairUp)
		return true; // Õ“Ë

	return false;
}
