#pragma once

#include <cmath>
#include "dxlib/DxLib.h"
#include "typedef.h"

namespace UrLib {
	inline bool IntToBool(int val) { return val != 0; }
	inline float ToRadian(float _deg) { return  _deg / 180.0f * DX_PI_F; }
	inline float ToDegree(float _rad) { return _rad * 180.0f / DX_PI_F; }
	
	inline VECTOR operator +(const VECTOR& v1, const VECTOR& v2) { return VAdd(v1, v2); }
	inline VECTOR& operator +=(VECTOR& v1, const VECTOR& v2) { return v1 = VAdd(v1, v2); }
	inline VECTOR operator -(const VECTOR& v1, const VECTOR& v2) { return VSub(v1, v2); }
	inline VECTOR& operator -=(VECTOR& v1, const VECTOR& v2) { return v1 = VSub(v1, v2); }
	inline VECTOR operator *(const VECTOR& v1, float scale) { return VScale(v1, scale); }
	inline VECTOR& operator *=(VECTOR& v1, float scale) { return v1 = VScale(v1, scale); }

	inline VECTOR operator *(const VECTOR& v, const MATRIX& m) { return VTransform(v, m); }

	inline VECTOR& operator *=(VECTOR& v, const MATRIX& m) { return v = VTransform(v, m); }

	inline MATRIX operator *(const MATRIX& m1, const MATRIX& m2) { return MMult(m1, m2); }
	inline MATRIX& operator *=(MATRIX& m1, const MATRIX& m2) { return m1 = MMult(m1, m2); }

	inline bool operator ==(const VECTOR& v1, const VECTOR& v2) { return VSize(v1 - v2) == 0; }
	inline bool operator !=(const VECTOR& v1, const VECTOR& v2) { return VSize(v1 - v2) > 0; }

	inline float Remainder(const float& f1, const float& f2) { return f1 - (f2 * (int)(f1 / f2)); }

	inline Quaternion operator *(const Quaternion& q1, const Quaternion& q2) 
	{
		Quaternion q;
		q.x = q1.w * q2.x - q1.z * q2.y + q1.y * q2.z + q1.x * q2.w;
		q.y = q1.z * q2.x + q1.w * q2.y - q1.x * q2.z + q1.y * q2.w;
		q.z = -q1.y * q2.x + q1.x * q2.y + q1.w * q2.z + q1.z * q2.w;
		q.w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;

		return q;
	}

	template<typename T>
	inline bool Clamp(T& val, T min, T max)
	{
		if (min > max) return false;
		else if (val < min) val = min;
		else if (val > max) val = max;
		return true;
	}

	template<typename T>
	inline bool LoopClamp(T& val, T min, T max)
	{
		if (min > max) return false;
		while (val < min) {
			T temp = val - min;
			val = max + temp;
		}
		while (val > max) {
			T temp = val - max;
			val = min + temp;
		}
		return true;
	}
}
using namespace UrLib;