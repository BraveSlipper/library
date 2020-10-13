#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager* SceneManager::Get()
{
	if (instance == nullptr)
	{
		instance = new SceneManager();
	}
	return instance;
}

bool SceneManager::Destroy()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
		return true;
	}
	return false;
}

void SceneManager::Start()
{
}

void SceneManager::Update()
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
			if (mainScene->IsReload())
			{
				Scene* (*f)() = mainScene->reloadScene;
				std::string name = mainScene->GetTypeName();
				delete mainScene;
				mainScene = f();
				mainScene->SetName(name);
				mainScene->reloadScene = f;
			}

			if (mainScene->IsActive())
			{
				mainScene->SceneUpdate();
			}
		}
	}
}

Scene* SceneManager::GetCurrentScene()
{
	if (mainScene != nullptr)
		return mainScene->GetCurrentScene();
	return nullptr;
}

void SceneManager::ChangeScene()
{
	if (mainScene != nullptr)
		delete mainScene;

	mainScene = createScene();
	
	mainScene->SetName(sceneName);

	mainScene->reloadScene = createScene;

	mainScene->SceneStart();

	createScene = nullptr;
}
