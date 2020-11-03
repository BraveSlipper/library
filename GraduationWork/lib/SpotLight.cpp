#include "SpotLight.h"
#include "Function.h"
#include "Transform.h"

SpotLight::SpotLight() :
	inRadian(ToRadian(45.f)), outRadian(ToRadian(15.f)), attenuation(0.1f)
{
	handle = CreateSpotLightHandle(
		transform->position, transform->GetForward(), outRadian, inRadian, radius, 0.f, 0.f, attenuation);
}

void SpotLight::SetDerived()
{
}
