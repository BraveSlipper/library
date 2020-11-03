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
	float radius;		//”¼Œa

	float attenuation;	//‹——£‚Ì2æ–attenuation

};
