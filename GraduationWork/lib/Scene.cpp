#include "Scene.h"

void UrLib::Scene::SceneStart()
{
	Start();
}

void UrLib::Scene::SceneUpdate()
{
	//自身のオブジェクト破棄
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end();)
	{
		if ((*it)->IsDestroy())
		{
			std::list<GameObject*> children = (*it)->GetChildren();
			for (std::list<GameObject*>::iterator cit = children.begin(); cit != children.end();)
			{
				bool isfind = false;
				/*for (std::list<GameObject*>::iterator find = objectList.begin(), end = objectList.end(); it != end; ++it)
				{
					if (cit == find)
					{
						delete* cit;
						cit = children.erase(cit);
						isfind = true;
						break;
					}
				}*///TODO
				if (!isfind)
					++cit;
			}
			delete* it;
			it = objectList.erase(it);
		}
		else
			++it;
	}

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

	//サブシーンの追加
	for (std::list<NODE>::iterator it = addSceneList.begin(); it != addSceneList.end();)
	{
		Scene* p = it->createScene();
//		p->SetName(it->name);//TODO
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

	//自身のオブジェクト更新
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{

		(*it)->DestroyComponents();
		if ((*it)->IsActive())
		{
			(*it)->Update();
		}
	}
	
	Update();
}

bool UrLib::Scene::AddGameObject(GameObject* _object)
{
	if (_object == nullptr)return false;

	for (std::list<GameObject*>::iterator it = objectList.begin(), end = objectList.end(); it != end; ++it)
		if (_object == (*it))return false;

	objectList.emplace_back(_object);

	return true;
}
