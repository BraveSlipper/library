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
		Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(0.0f), up(VGet(0.0f, 1.0f, 0.0f)) {}
		float x, y, z, w;
		static Quaternion Create(VECTOR _axis, float _deg);
		static Quaternion RotatePosition(VECTOR _axis, VECTOR _pos, float _deg);

		/// <summary>
		/// ベクトルを取得
		/// </summary>
		/// <returns>姿勢を除いたベクトル</returns>
		VECTOR GetVec() const { return VGet(x, y, z); }

		/// <summary>
		/// 正面ベクトルを取得
		/// </summary>
		/// <returns>正面ベクトル</returns>
		VECTOR GetForword() const { return VNorm(VGet(x,y,z)); }

		/// <summary>
		/// アップベクトルを取得
		/// </summary>
		/// <returns>アップベクトル</returns>
		VECTOR GetUp() const { return up; }

	private:
		VECTOR up;
	};
}
using namespace UrLib;