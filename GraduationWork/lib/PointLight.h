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
	float radius;//���a

	float attenuation;//������2�恖attenuation

};
