#include "Light.h"
#include "DrawManager.h"

namespace
{
	COLOR_F ToColorF(Light::COLOR& _color)
	{
		return GetColorF(_color.r, _color.g, _color.b, 1.f);
	}
}

Light::Light() :
	handle(-1)
{
	DrawManager::Get()->AddRight(this);
}

Light::~Light()
{
	DrawManager::Get()->EraseLight(this);
	if (handle != -1)
		DeleteLightHandle(handle);

}

void Light::Set()
{
	if (handle == -1)return;

	if (IsActive())
	{
		SetLightEnableHandle(handle, TRUE);
		SetLightDifColorHandle(handle, ToColorF(diffuse));
		SetLightSpcColorHandle(handle, ToColorF(specular));
		SetLightAmbColorHandle(handle, ToColorF(ambient));
		SetDerived();
	}
	else
		SetLightEnableHandle(handle, FALSE);

}
