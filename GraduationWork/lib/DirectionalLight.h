#pragma once

#include "Light.h"

class DirectionalLight :public Light
{
public:
	DirectionalLight();

	~DirectionalLight()
	{
	}

	void SetDerived()override;

public:

};
