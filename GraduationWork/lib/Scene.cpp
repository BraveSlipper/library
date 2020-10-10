#include "Scene.h"

void UrLib::Scene::Start()
{
}

void UrLib::Scene::Update()
{
	//サブシーンの追加
	for (std::list<NODE>::iterator it = addSceneList.begin(); it != addSceneList.end();)
	{
		Scene* p = it->createScene(it->name);
		subSceneList.emplace_back(p);
		it = addSceneList.erase(it);
	}

	//サブシーンの更新
	for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end(); ++it)
	{
		(*it)->Update();
	}

	//自身のオブジェクト更新
	for (std::list<Object*>::iterator it = objectList.begin(); it != objectList.end();)
	{
		if ((*it)->IsDestroy())
		{
			delete* it;
			it = objectList.erase(it);
		}
		else
		{
			if ((*it)->IsActive())
			{
				(*it)->Update();
			}
		}
	}
}

bool UrLib::Scene::AddGameObject(Object* _object)
{
	if (_object == nullptr)return false;

	for (std::list<Object*>::iterator it = objectList.begin(), end = objectList.end(); it != end; ++it)
		if (_object == (*it))return false;

	objectList.emplace_back(_object);

	return true;
}
