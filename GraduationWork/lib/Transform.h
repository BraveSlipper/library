#pragma once
#include "Component.h"
#include "dxlib/DxLib.h"
#include "typedef.h"

class Transform : public Component {
public:
	Transform();
	~Transform();

	void Start() override;
	void Update() override;

	/// <summary>
	/// ���W����
	/// </summary>
	/// <param name="_pos">������������W</param>
	void SetPosition(VECTOR _pos);

	/// <summary>
	/// ���W�����Z����
	/// </summary>
	/// <param name="_add"></param>
	void AddPosition(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
	void AddPosition(VECTOR _add);

	/// <summary>
	/// X���ŉ�]����
	/// </summary>
	/// <param name="_deg">��]�p�x</param>
	void AxisRotateX(float _deg);

	/// <summary>
	/// Y���ŉ�]����
	/// </summary>
	/// <param name="_deg">��]�p�x</param>
	void AxisRotateY(float _deg);

	/// <summary>
	/// Z���ŉ�]����
	/// </summary>
	/// <param name="_deg">��]�p�x</param>
	void AxisRotateZ(float _deg);

	/// <summary>
	/// �C�ӎ��ŉ�]����
	/// </summary>
	/// <param name="_axis">��]��</param>
	/// <param name="_deg">��]�p�x</param>
	void Rotate(VECTOR _axis, float _deg);

	/// <summary>
	/// ���ʃx�N�g�����擾
	/// </summary>
	/// <returns>���ʃx�N�g��</returns>
	VECTOR GetForward() const;

	/// <summary>
	/// �E�x�N�g�����擾
	/// </summary>
	/// <returns>�E�x�N�g��</returns>
	VECTOR GetRight() const;

	/// <summary>
	/// �A�b�v�x�N�g�����擾
	/// </summary>
	/// <returns>�A�b�v�x�N�g��</returns>
	VECTOR GetUp() const;

	VECTOR position;
	VECTOR scale;

private:
	Quaternion foward;
	Quaternion right;
	Quaternion up;
};