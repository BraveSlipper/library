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
		/// ベクトルを取得
		/// </summary>
		/// <returns>姿勢を除いたベクトル</returns>
		VECTOR GetVec() const { return VGet(x, y, z); }
	};

	class OBB {
	public:
		OBB();
		~OBB();
		VECTOR GetDirect(int elem);	// 指定軸番号の方向ベクトルを取得
		float GetLen_W(int elem);		// 指定軸方向の長さを取得
		VECTOR GetPos_W();				// 位置を取得
		void SetPos(VECTOR pos);		// 位置を設定
		void Rotate(VECTOR _axis, float _deg);	// OBBを回転させる
		void SetLength(int elem, float len);	// 指定軸の長さを設定

	protected:
		VECTOR Pos;              // 位置
		VECTOR NormaDirect[3];   // 方向ベクトル
		float Length[3];         // 各軸方向の長さ
	};

	/// <summary>
	/// OBB同士の衝突チェック
	/// </summary>
	/// <returns>true:衝突している, false:衝突していない</returns>
	bool ColOBBs(OBB& obb1, OBB& obb2);

	// 分離軸に投影された軸成分から投影線分長を算出
	float LenSegOnSeparateAxis(VECTOR Sep, VECTOR e1, VECTOR e2, VECTOR e3 = VGet(0.0f, 0.0f, 0.0f));
}
using namespace UrLib;