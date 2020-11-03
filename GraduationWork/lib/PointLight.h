#pragma once

#include "Light.h"

class PointLight :public Light
{
public:
	PointLight() :
		radius(1.f), attenuation(0.1f) {}

	~PointLight()
	{
	}

private:
	void Start()override;

private:
	void SetDerived()override;

public:
	float radius;		//���a

	float attenuation;	//������2�恖attenuation

};
