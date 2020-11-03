#pragma once
#include "dxlib/DxLib.h"

namespace UrLib {
	typedef struct tagVECTOR2 {
		float x, y;
		tagVECTOR2() : x(0.0f), y(0.0f) {}
		tagVECTOR2(float _x, float _y) : x(_x), y(_y) {}
		static tagVECTOR2 zero() { return tagVECTOR2(); }
		static tagVECTOR2 one() { return tagVECTOR2(1.0f, 1.0f); }
		static tagVECTOR2 up() { return tagVECTOR2(0.0f, 1.0f); }
		static tagVECTOR2 right() { return tagVECTOR2(1.0f, 0.0f); }
		void clear() { x = 0.0f, y = 0.0f; }

	} VECTOR2;

	class Quaternion {
	public:
		Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Quaternion(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
		float x, y, z, w;
		static Quaternion Create(VECTOR _axis, float _deg);
		static VECTOR RotatePosition(VECTOR _axis, VECTOR& _pos, float _deg);
		static Quaternion RotatePosition(VECTOR _axis, Quaternion& _pos, float _deg);

		MATRIX GetMatrix()const;

		/// <summary>
		/// �x�N�g�����擾
		/// </summary>
		/// <returns>�p�����������x�N�g��</returns>
		VECTOR GetVec() const { return VGet(x, y, z); }
	};

	class OBB {
	public:
		OBB();
		~OBB();
		VECTOR GetDirect(int elem);	// �w�莲�ԍ��̕����x�N�g�����擾
		float GetLen_W(int elem);		// �w�莲�����̒������擾
		VECTOR GetPos_W();				// �ʒu���擾
		void SetPos(VECTOR pos);		// �ʒu��ݒ�
		void Rotate(VECTOR _axis, float _deg);	// OBB����]������
		void SetLength(int elem, float len);	// �w�莲�̒�����ݒ�

	protected:
		VECTOR Pos;              // �ʒu
		VECTOR NormaDirect[3];   // �����x�N�g��
		float Length[3];         // �e�������̒���
	};

	/// <summary>
	/// OBB���m�̏Փ˃`�F�b�N
	/// </summary>
	/// <returns>true:�Փ˂��Ă���, false:�Փ˂��Ă��Ȃ�</returns>
	bool ColOBBs(OBB& obb1, OBB& obb2);

	// �������ɓ��e���ꂽ���������瓊�e���������Z�o
	float LenSegOnSeparateAxis(VECTOR Sep, VECTOR e1, VECTOR e2, VECTOR e3 = VGet(0.0f, 0.0f, 0.0f));
}
using namespace UrLib;