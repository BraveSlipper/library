#pragma once
#include "dxlib/DxLib.h"

namespace UrLib {
	inline float ToRadian(float _deg) { return  _deg / 180.0f * DX_PI_F; }
	inline float ToDegree(float _rad) { return _rad * 180.0f / DX_PI_F; }
}
using namespace UrLib;