#include "DrawManager.h"
#include "Renderer.h"

DrawManager* DrawManager::instance = nullptr;

DrawManager::~DrawManager() 
{
	rendererList.clear(); 
}

DrawManager* DrawManager::Get()
{
	if (instance == nullptr)
	{
		instance = new DrawManager();
	}
	return instance;
}

bool DrawManager::Destroy()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
		return true;
	}
	return false;
}

void DrawManager::Draw()
{
	for (std::list<Renderer*>::iterator it = rendererList.begin(), end = rendererList.end(); it != end; ++it)
		(*it)->Draw();
}

void DrawManager::Add(Renderer* _p)
{
	rendererList.emplace_back(_p);
}

bool DrawManager::Erase(Renderer* _p)
{
	for (std::list<Renderer*>::iterator it = rendererList.begin(), end = rendererList.end(); it != end; ++it) 
	{ 
		if ((*it) == _p)
			rendererList.erase(it);
		return true; 
	}
	return false; 
}
