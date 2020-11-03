#pragma once

#include "dxlib/DxLib.h"
#include "Component.h"

class Light :public Component
{
public:
	struct COLOR
	{
		COLOR() :r(0.f), g(0.f), b(0.f) {}
		COLOR(float _r, float _g, float _b) :r(_r), g(_g), b(_b) {}
		float r, g, b;
	};
	static COLOR GetCOLOR(float _r, float _g, float _b) { return COLOR(_r, _g, _b); }
	static const COLOR red, green, blue;

public:
	Light();

	virtual ~Light();

	void Set();

	static int GetEnableCount();

private:
	virtual void SetDerived() = 0;

public:
	COLOR diffuse, specular, ambient;//0Å`1

protected:
	int handle;//ÉnÉìÉhÉã

};
