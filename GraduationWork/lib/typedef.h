#pragma once

#include "Function.h"

namespace UrLib {
	typedef struct tagVECTOR2 {
		float x, y;
		tagVECTOR2() : x(0.0f), y(0.0f) {}
		tagVECTOR2(float _x, float _y) : x(_x), y(_y) {}
	} VECTOR2;

	struct Quaternion {
		float x, y, z, w;
		Quaternion(VECTOR _axis, float _deg) 
		{
			x = _axis.x * sin(ToRadian(_deg / 2.0f));
			y = _axis.y * sin(ToRadian(_deg / 2.0f));
			z = _axis.z * sin(ToRadian(_deg / 2.0f));
			w = cos(ToRadian(_deg / 2.0f));
		}
	};
}
using namespace UrLib;