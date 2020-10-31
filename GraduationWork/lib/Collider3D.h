#pragma once
#include "Collider.h"
#include "dxlib/DxLib.h"

class Collider3D : public Collider {
public:
	Collider3D();
	virtual ~Collider3D();

	virtual bool IsCollide(Collider3D* _collider) = 0;

	/// <summary>
	/// �Փˎ��ɌĂ΂��֐���S�Ď��s����
	/// </summary>
	/// <param name="_collider">�Փ˂����I�u�W�F�N�g�̃R���C�_�[</param>
	void ExecuteAllCollisionEnter(Collider3D* _collider);

	/// <summary>
	/// �Փ˒��ɌĂ΂��֐���S�Ď��s����
	/// </summary>
	/// <param name="_collider">�Փ˒��̃I�u�W�F�N�g�̃R���C�_�[</param>
	void ExecuteAllCollisionStay(Collider3D* _collider);

	/// <summary>
	/// �ՓˏI�����ɌĂ΂��֐���S�Ď��s����
	/// </summary>
	/// <param name="_collider">�ՓˏI�������I�u�W�F�N�g�̃R���C�_�[</param>
	void ExecuteAllCollisionExit(Collider3D* _collider);

	/// <summary>
	/// ���W�̎擾
	/// </summary>
	/// <returns>���L�҂����_�Ƃ����R���C�_�[�̍��W</returns>
	VECTOR GetLocalPosition();

	/// <summary>
	/// ���[���h���W��̃R���C�_�[�̍��W���擾
	/// </summary>
	/// <returns>���[���h���W��̃R���C�_�[�̍��W</returns>
	VECTOR GetWorldPosition();

	/// <summary>
	/// �R���C�_�[�̍��W��ݒ�
	/// </summary>
	/// <param name="_pos">���L�҂����_�Ƃ����ړ���̍��W</param>
	virtual void SetPosition(VECTOR _pos);

protected:
	VECTOR position;
};