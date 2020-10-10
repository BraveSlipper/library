#include "SceneManager.h"

UrLib::SceneManager* UrLib::SceneManager::singleton = nullptr;

UrLib::SceneManager* UrLib::SceneManager::Get()
{
	if (singleton == nullptr)
	{
		singleton = new SceneManager();
	}
	return singleton;
}

bool UrLib::SceneManager::Destroy()
{
	if (singleton != nullptr)
	{
		delete singleton;
		singleton = nullptr;
		return true;
	}
	return false;
}

void UrLib::SceneManager::Start()
{
}

void UrLib::SceneManager::Update()
{
	if (createScene != nullptr)
		CreateScene();

	if (mainScene != nullptr)mainScene->Update();
}

void UrLib::SceneManager::CreateScene()
{
	if (mainScene != nullptr)
		delete mainScene;

	mainScene = createScene(sceneName);
}
