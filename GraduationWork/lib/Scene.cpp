#include "Scene.h"

Scene* Scene::currentScene = nullptr;

Scene::~Scene()
{
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end();)
	{
		(*it)->Destroy();
	}
	DestroyGameObjects();

	for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end();)
	{
		delete* it;
		it = subSceneList.erase(it);
	}
	addSceneList.clear();

}

void Scene::SceneStart()
{
	Start();
}

void Scene::SceneUpdate()
{
	DestroyGameObjects();

	//サブシーン破棄
	for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end();)
	{
		if ((*it)->IsDestroy())
		{
			delete* it;
			it = subSceneList.erase(it);
		}
		else
			++it;
	}

	//サブシーン再読み込み
	for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
	{
		if ((*it)->IsReload())
		{
			std::string name = (*it)->GetTypeName();
			Scene* (*f)() = (*it)->reloadScene;
			delete* it;
			*it = f();
			(*it)->SetName(name);
			(*it)->reloadScene = f;
		}
	}

	//サブシーンの追加
	for (std::list<NODE>::iterator it = addSceneList.begin(); it != addSceneList.end();)
	{
		Scene* p = it->createScene();
		p->SetName(it->name);
		p->reloadScene = it->createScene;
		p->SceneStart();
		subSceneList.emplace_back(p);
		it = addSceneList.erase(it);
	}

	//サブシーンの更新
	for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end(); ++it)
	{
		if ((*it)->IsActive())
		{
			(*it)->SceneUpdate();
		}
	}

	currentScene = this;
	//自身のオブジェクトのコンポーネント破棄
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->DestroyComponents();
	}

	//自身のオブジェクト更新
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		if ((*it)->IsActive())
		{
			(*it)->Update();
		}
	}
	
	Update();

	currentScene = nullptr;
}

bool Scene::AddGameObject(GameObject* _object)
{
	if (_object == nullptr)return false;

	for (std::list<GameObject*>::iterator it = objectList.begin(), end = objectList.end(); it != end; ++it)
		if (_object == (*it))return false;

	objectList.emplace_back(_object);

	return true;
}

void Scene::DestroyGameObjects()
{
	//親の死亡フラグが立っている場合、子の死亡フラグを立てる
	for (std::list<GameObject*>::iterator it = objectList.begin(), end = objectList.end(); it != end; ++it)
	{
		if (!(*it)->IsDestroy())continue;

		std::list<GameObject*> children = (*it)->GetChildren();
		for (std::list<GameObject*>::iterator cit = children.begin(), cend = children.end(); cit != cend; ++cit)
		{
			(*it)->Destroy();
		}
	}
	
	//サブシーンチェック
	for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
		(*it)->DestroyGameObjects();

	//自身のオブジェクト破棄
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end();)
	{
		if ((*it)->IsDestroy())
		{
			delete* it;
			it = objectList.erase(it);
		}
		else
			++it;
	}
}
