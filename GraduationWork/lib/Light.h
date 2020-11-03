#pragma once

#include "dxlib/DxLib.h"
#include "Component.h"

class Light :public Component
{
public:
	struct COLOR
	{
		float r, g, b;
	};

public:
	Light();

	virtual ~Light();

	void Set();

private:
	virtual void SetDerived() = 0;

public:
	COLOR diffuse, specular, ambient;

protected:
	int handle;

};
