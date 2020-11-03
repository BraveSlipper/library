#include "SpotLight.h"
#include "Transform.h"

void SpotLight::Start()
{
	handle = CreateSpotLightHandle(
		transform->position, transform->GetForward(), outRadian, inRadian, radius, 0.f, 0.f, attenuation);
}

void SpotLight::SetDerived()
{
	float out = inRadian + outRadian;

	Clamp(out, 0.f, DX_PI_F);
	Clamp(inRadian, 0.f, out);
	outRadian = out - inRadian;

	SetLightDirectionHandle(handle, transform->GetForward());
	SetLightPositionHandle(handle, transform->position);
	SetLightRangeAttenHandle(handle, radius, 0.f, 0.f, attenuation);
	SetLightAngleHandle(handle, out, inRadian);
}
