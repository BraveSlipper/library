#pragma once
#include "dxlib/DxLib.h"

namespace UrLib {
	typedef struct tagVECTOR2 {
		float x, y;
		tagVECTOR2() : x(0.0f), y(0.0f) {}
		tagVECTOR2(float _x, float _y) : x(_x), y(_y) {}
	} VECTOR2;

	class Quaternion {
	public:
		Quaternion() : x(0.0f), y(0.0f), z(1.0f), w(0.0f), up(VGet(0.0f, 1.0f, 0.0f)) {}
		float x, y, z, w;
		static Quaternion Create(VECTOR _axis, float _deg);
		static Quaternion CreateRotatedQuaternion(VECTOR _axis, VECTOR _pos, float _deg);
		/// <summary>
		/// アップベクトルを取得
		/// </summary>
		/// <returns>アップベクトル</returns>
		VECTOR GetForword() const { return VECTOR{x,y,z}; }

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