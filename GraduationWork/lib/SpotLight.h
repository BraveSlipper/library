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
	float inRadian;//�����p�x
	float outRadian;//�O���p�x

	float attenuation;//������2�恖attenuation

	float radius;//���a

};
