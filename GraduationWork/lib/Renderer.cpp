#include "Renderer.h"
#include "DrawManager.h"

Renderer::Renderer()
{
	DrawManager::Get()->Add(this);
}

Renderer::~Renderer()
{
	DrawManager::Get()->Erase(this);
}
