#pragma once

#include "Light.h"

class PointLight :public Light
{
public:
	PointLight();

	~PointLight()
	{
	}

	void SetDerived()override;

public:
	float radius;//”¼Œa

	float attenuation;//‹——£‚Ì2æ–attenuation

};
