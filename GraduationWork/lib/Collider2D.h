#pragma once
#include "Collider.h"
#include "typedef.h"
#include <list>

class Collider2D : public Collider {
public:
	Collider2D();
	virtual ~Collider2D();

	virtual bool IsCollide(Collider2D* _collider) = 0;

	/// <summary>
	/// �Փˎ��ɌĂ΂��֐���S�Ď��s����
	/// </summary>
	/// <param name="_collider">�Փ˂����I�u�W�F�N�g�̃R���C�_�[</param>
	void ExecuteAllCollisionEnter(Collider2D* _collider);

	/// <summary>
	/// �Փ˒��ɌĂ΂��֐���S�Ď��s����
	/// </summary>
	/// <param name="_collider">�Փ˒��̃I�u�W�F�N�g�̃R���C�_�[</param>
	void ExecuteAllCollisionStay(Collider2D* _collider);

	/// <summary>
	/// �ՓˏI�����ɌĂ΂��֐���S�Ď��s����
	/// </summary>
	/// <param name="_collider">�ՓˏI�������I�u�W�F�N�g�̃R���C�_�[</param>
	void ExecuteAllCollisionExit(Collider2D* _collider);

	/// <summary>
	/// ���W�̎擾
	/// </summary>
	/// <returns>���L�҂����_�Ƃ����R���C�_�[�̍��W</returns>
	VECTOR2 GetLocalPosition();

	/// <summary>
	/// ���[���h���W��̃R���C�_�[���W�̎擾
	/// </summary>
	/// <returns>���[���h���W��̃R���C�_�[���W</returns>
	VECTOR2 GetWorldPosition();

	/// <summary>
	/// �R���C�_�[�̍��W��ݒ�
	/// </summary>
	/// <param name="_pos">���L�҂����_�Ƃ����ړ���̍��W</param>
	void SetPosition(VECTOR2 _pos);

	/// <summary>
	/// Z����]�l�̎擾
	/// </summary>
	/// <returns>��]�p�x(�x)</returns>
	float GetRotate();

	/// <summary>
	/// �R���C�_�[����]
	/// </summary>
	/// <param name="_deg">��]�p�x</param>
	void Rotate(float _deg);
protected:
	VECTOR2 position;
	float rotation;
};