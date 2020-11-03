#include "Renderer.h"
#include "DrawManager.h"

Renderer::Renderer()
{
	DrawManager::Get()->AddRenderer(this);
}

Renderer::~Renderer()
{
	DrawManager::Get()->EraseRenderer(this);
}
