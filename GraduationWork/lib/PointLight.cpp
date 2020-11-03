#include "PointLight.h"
#include "Transform.h"

PointLight::PointLight() :
	radius(1.f), attenuation(0.1f)
{
	handle = CreatePointLightHandle(transform->position, radius, 0.f, 0.f, attenuation);
}

void PointLight::SetDerived()
{
}
