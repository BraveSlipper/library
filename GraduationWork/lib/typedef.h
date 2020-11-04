#pragma once
#include "dxlib/DxLib.h"

namespace UrLib {
	typedef struct tagFLOAT3 {
		tagFLOAT3(): x(0.0f), y(0.0f), z(0.0f) {}
		tagFLOAT3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
		~tagFLOAT3() {}
		float x, y, z;
	} Float3, Point;

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

	typedef struct tagVECTOR3 : public VECTOR {
		tagVECTOR3() { x = 0.0f, y = 0.0f, z = 0.0f; }
		tagVECTOR3(float _x, float _y, float _z) {x = _x, y = _y, z = _z;}
		tagVECTOR3(VECTOR _v) { *this = _v; }
		static tagVECTOR3 zero() { return tagVECTOR3(); }
		static tagVECTOR3 one() { return tagVECTOR3(1.0f, 1.0f, 1.0f); }
		static tagVECTOR3 up() { return tagVECTOR3(0.0f, 1.0f, 0.0f); }
		static tagVECTOR3 right() { return tagVECTOR3(1.0f, 0.0f, 0.0f); }
		void clear() { x = 0.0f, y = 0.0f, z = 0.0f; }
		tagVECTOR3& operator =(const VECTOR& _v) { x = _v.x, y = _v.y, z = _v.z; return *this; }
	} VECTOR3;

	struct Line {
		Line() {}
		Line(const Point& p, const VECTOR3& v) : p(p), vec(v) {}
		Point p;
		VECTOR3 vec;

		// �_��̍��W���擾
		//  t: �x�N�g���Ɋ|���Z����W��
		Float3 GetPoint(float t) const;
	};

	class Quaternion {
	public:
		Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Quaternion(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
		float x, y, z, w;
		static Quaternion Create(VECTOR3 _axis, float _deg);
		static VECTOR3 RotatePosition(VECTOR3 _axis, VECTOR3 _pos, float _deg);
		static Quaternion RotatePosition(VECTOR3 _axis, Quaternion _pos, float _deg);
		static void RotatePosition(VECTOR3 _axis, VECTOR3* _pos, float _deg);
		static void RotatePosition(VECTOR3 _axis, Quaternion* _pos, float _deg);

		MATRIX GetMatrix()const;

		/// <summary>
		/// �x�N�g�����擾
		/// </summary>
		/// <returns>�p�����������x�N�g��</returns>
		VECTOR3 GetVec() const { return VGet(x, y, z); }
	};

	class OBB {
	public:
		OBB();
		~OBB();
		VECTOR3 GetDirect(int elem);	// �w�莲�ԍ��̕����x�N�g�����擾
		float GetLen_W(int elem);		// �w�莲�����̒������擾
		VECTOR3 GetPos_W();				// �ʒu���擾
		void SetPos(VECTOR3 pos);		// �ʒu��ݒ�
		void Rotate(VECTOR3 _axis, float _deg);	// OBB����]������
		void SetLength(int elem, float len);	// �w�莲�̒�����ݒ�

	protected:
		VECTOR3 Pos;              // �ʒu
		VECTOR3 NormaDirect[3];   // �����x�N�g��
		float Length[3];         // �e�������̒���
	};

	/// <summary>
	/// OBB���m�̏Փ˃`�F�b�N
	/// </summary>
	/// <returns>true:�Փ˂��Ă���, false:�Փ˂��Ă��Ȃ�</returns>
	bool ColOBBs(OBB& obb1, OBB& obb2);

	// �������ɓ��e���ꂽ���������瓊�e���������Z�o
	float LenSegOnSeparateAxis(VECTOR3 Sep, VECTOR3 e1, VECTOR3 e2, VECTOR3 e3 = VGet(0.0f, 0.0f, 0.0f));
}
using namespace UrLib;
