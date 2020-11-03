#include "PointLight.h"
#include "Transform.h"

void PointLight::Start()
{
	handle = CreatePointLightHandle(transform->position, radius, 0.f, 0.f, attenuation);
}

void PointLight::SetDerived()
{
	SetLightPositionHandle(handle, transform->GetForward());
	SetLightRangeAttenHandle(handle, radius, 0.f, 0.f, attenuation);
}
