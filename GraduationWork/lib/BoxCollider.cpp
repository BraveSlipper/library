#include "BoxCollider.h"
#include "UrLib.h"
#include "SphereCollider.h"

BoxCollider::BoxCollider() :
	height(1.0f), width(1.0f)
{
}

BoxCollider::~BoxCollider()
{
}

bool BoxCollider::IsCollide(Collider3D* _collider)
{
	SphereCollider* col_c = dynamic_cast<SphereCollider*>(_collider);
	BoxCollider* col_b = dynamic_cast<BoxCollider*>(_collider);
	if (col_c != nullptr) {	// �Ώۂ�CircleCollider�̎�
		return IsCollideCircle(col_c);
	}
	else if (col_b != nullptr) { // �Ώۂ�BoxCollider�̎�
		return IsCollideBox(col_b);
	}
	return false;
}

float BoxCollider::GetHeight() const
{
	return height;
}

float BoxCollider::GetWidth() const
{
	return width;
}

void BoxCollider::SetSize(float _hight, float _width)
{
	height = _hight;
	width = _width;
}

bool BoxCollider::IsCollideCircle(SphereCollider* _collider)
{
	return false;
	//// ��`�O�x�̎��̍��W�ɉ~�̊p�x�𒼂�
	//VECTOR circle = _collider->transform->position;
	//float radian = ToRadian(_collider->transform->rotate.z);
	//VECTOR rect = transform->position;
	//VECTOR c;

	//c.x = static_cast<float>(cos(radian) * ((double)circle.x - (double)rect.x) - sin(radian) * ((double)circle.y - (double)rect.y) + rect.x);
	//c.y = static_cast<float>(sin(radian) * ((double)circle.x - (double)rect.x) + cos(radian) * ((double)circle.y - (double)rect.y) + rect.y);

	//// ��̉~�̒��S�_�����`�̂P�ԋ߂����W
	//VECTOR ver;

	//// �Z�a�̒��_���W
	//float left = rect.x - width * 0.5f;
	//float right = rect.x + width * 0.5f;
	//float up = rect.y - height * 0.5f;
	//float down = rect.y + height * 0.5f;

	//// �P�ԋ߂�x���W�����߂�
	//if (c.x < rect.x)
	//	ver.x = rect.x - width * 0.5f;
	//else if (c.x > rect.x)
	//	ver.x = rect.x + width * 0.5f;
	//else
	//	ver.x = c.x;

	//// �P�ԋ߂�y���W�����߂�
	//if (c.y < rect.y)
	//	ver.y = rect.y - height * 0.5f;
	//else if (c.y > rect.y)
	//	ver.y = rect.y + height * 0.5f;
	//else
	//	ver.y = c.y;

	//// ��ԋ߂��p�ۂƂ̏Փ˔���
	//float radius = _collider->GetRadius();
	//float distance = VSize(c - ver);
	//if (distance < radius)
	//	return true; // �Փ�

	//// �~�̒��S�_�ƒ����`�̂����蔻��
	//bool a = c.x > left && c.x < right&& c.y > up - radius && c.y < down + radius;
	//bool b = c.x > left - radius && c.x < right + radius && c.y > up && c.y < down;
	//if (a || b)  return true;
	//else return false;
}

bool BoxCollider::IsCollideBox(BoxCollider* _collider)
{
	// �����̒Z�a�̒��_���W
	VECTOR myPos = transform->position;
	float left = myPos.x - width * 0.5f;
	float right = myPos.x + width * 0.5f;
	float up = myPos.y - height * 0.5f;
	float down = myPos.y + height * 0.5f;

	// ����̒Z�a�̒��_���W
	VECTOR pairPos = _collider->transform->position;
	float pairHeight = _collider->GetHeight();
	float pairWidth = _collider->GetWidth();
	float pairLeft = pairPos.x - pairWidth * 0.5f;
	float pairRight = pairPos.x + pairWidth * 0.5f;
	float pairUp = pairPos.y - pairHeight * 0.5f;
	float pairDown = pairPos.y + pairHeight * 0.5f;

	// �Z�a�ƒZ�a�̏Փ˔���
	if (left < pairRight &&
		right > pairLeft &&
		up < pairDown &&
		down > pairUp)
		return true; // �Փ�

	return false;
}
