#pragma once
#include "Component.h"
#include "dxlib/DxLib.h"

class Transform : public Component {
public:
	Transform();
	~Transform();

	void Start() override;
	void Update() override;

	/// <summary>
	/// ���ʃx�N�g�����擾
	/// </summary>
	/// <returns>���ʃx�N�g��</returns>
	VECTOR GetForward() const;

	/// <summary>
	/// �A�b�v�x�N�g�����擾
	/// </summary>
	/// <returns>�A�b�v�x�N�g��</returns>
	VECTOR GetUp() const;

	/// <summary>
	/// ���[���h�ɂ�����Transform���擾
	/// </summary>
	/// <returns>���[���h�g�����X�t�H�[��</returns>
	Transform GetWorldTransform();

	VECTOR position;
	VECTOR rotation;
	VECTOR scale;



private:
	/// <summary>
	/// ���[�J�����W���烏�[���h���W�֕ϊ����A�������
	/// </summary>
	/// <param name="_parent">�e�̃|�C���^�[</param>
	/// <param name="_pos">�ϊ����������[�J���|�W�V����</param>
	void SetWorldPosition(GameObject* _parent, VECTOR& _pos);

private:
	VECTOR foward;
	VECTOR right;
};