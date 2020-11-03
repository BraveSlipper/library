#pragma once

#include "Light.h"

class SpotLight :public Light
{
public:
	SpotLight();

	~SpotLight()
	{
	}

	void SetDerived()override;

public:
	float inRadian;//’†‘¤Šp“x
	float outRadian;//ŠO‘¤Šp“x

	float attenuation;//‹——£‚Ì2æ–attenuation

	float radius;//”¼Œa

};
