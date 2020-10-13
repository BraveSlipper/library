#pragma once

namespace UrLib {
	typedef struct tagVECTOR2 {
		float x, y;
		tagVECTOR2() : x(0.0f), y(0.0f) {}
		tagVECTOR2(const float& _x, const float& _y) : x(_x), y(_y) {}
	} VECTOR2;
}
using namespace UrLib;