#include "SceneManager.h"

UrLib::SceneManager* UrLib::SceneManager::instance = nullptr;

UrLib::SceneManager* UrLib::SceneManager::Get()
{
	if (instance == nullptr)
	{
		instance = new SceneManager();
	}
	return instance;
}

bool UrLib::SceneManager::Destroy()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
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
		ChangeScene();

	if (mainScene != nullptr)
	{
		if (mainScene->IsDestroy())
		{
			delete mainScene;
			mainScene = nullptr;
		}
		else
		{
			if (mainScene->IsActive())
				mainScene->SceneUpdate();
		}
	}
}

void UrLib::SceneManager::ChangeScene()
{
	if (mainScene != nullptr)
		delete mainScene;

	mainScene = createScene();
	
//	mainScene->SetName(sceneName);//TODO

	mainScene->SceneStart();
	createScene = nullptr;
}
