#pragma once
#include "dxlib/DxLib.h"

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

	inline bool operator ==(VECTOR& v1, VECTOR& v2) { return VSize(v1 - v2) == 0; }
	inline bool operator !=(VECTOR& v1, VECTOR& v2) { return VSize(v1 - v2) > 0; }

	inline float Remainder(const float& f1, const float& f2) { return f1 - (f2 * (int)(f1 / f2)); }
}
using namespace UrLib;