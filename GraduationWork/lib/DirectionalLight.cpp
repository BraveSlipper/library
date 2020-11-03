#include "DirectionalLight.h"
#include "Transform.h"

DirectionalLight::DirectionalLight()
{
	handle = CreateDirLightHandle(transform->GetForward());
}

void DirectionalLight::SetDerived()
{
}
