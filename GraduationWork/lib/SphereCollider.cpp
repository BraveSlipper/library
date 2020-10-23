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
	if (col_c != nullptr) {	// �Ώۂ�CircleCollider�̎�
		return IsCollideCircle(col_c);
	}
	else if (col_b != nullptr) { // �Ώۂ�BoxCollider�̎�
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
	//// ��`�O�x�̎��̍��W�ɉ~�̊p�x�𒼂�
	//VECTOR origin_c = transform->position;
	//float radian = ToRadian(transform->rotate.z);
	//VECTOR rect = _collider->transform->position;
	//VECTOR c;

	//c.x = cos(radian) * (origin_c.x - rect.x) - sin(radian) * (origin_c.y - rect.y) + rect.x;
	//c.y = sin(radian) * (origin_c.x - rect.x) + cos(radian) * (origin_c.y - rect.y) + rect.y;

	//// ��̉~�̒��S�_�����`�̂P�ԋ߂����W
	//VECTOR ver;

	//// �Z�a�̒��_���W
	//float height = _collider->GetHeight();
	//float width = _collider->GetWidth();
	//float left = rect.x - width * 0.5f;
	//float right = rect.x + width * 0.5f;
	//float up = rect.y - height * 0.5f;
	//float down = rect.y + height * 0.5f;

	//// �P�ԋ߂�x���W�����߂�
	//if (c.x < rect.x)
	//	ver.x = left;
	//else if (c.x > rect.x)
	//	ver.x = right;
	//else
	//	ver.x = c.x;

	//// �P�ԋ߂�y���W�����߂�
	//if (c.y < rect.y)
	//	ver.y = up;
	//else if (c.y > rect.y)
	//	ver.y = down;
	//else
	//	ver.y = c.y;

	//// ��ԋ߂��p�ۂƂ̏Փ˔���
	//float distance = VSize(c - ver);
	//if (distance < radius)
	//	return true; // �Փ�

	//// �~�̒��S�_�ƒ����`�̂����蔻��
	//bool a = c.x > left && c.x < right&& c.y > up - radius && c.y < down + radius;
	//bool b = c.x > left - radius && c.x < right + radius && c.y > up && c.y < down;
	//if (a || b)  return true;
	//else return false;
}
