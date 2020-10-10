#pragma once
#include "Component.h"
#include "dxlib/DxLib.h"

class Transform : public Component {
public:
	Transform(GameObject* _actor);
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

	VECTOR position;
	VECTOR rotation;
	VECTOR scale;
	
private:
	VECTOR forward;
	VECTOR up;
};