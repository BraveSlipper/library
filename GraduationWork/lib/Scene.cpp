#include "Scene.h"

void Scene::SceneStart()
{
	Start();
}

void Scene::SceneUpdate()
{
	//���g�̃I�u�W�F�N�g�j��
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

	//�T�u�V�[���j��
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

	//�T�u�V�[���̒ǉ�
	for (std::list<NODE>::iterator it = addSceneList.begin(); it != addSceneList.end();)
	{
		Scene* p = it->createScene();
		p->SetName(it->name);
		p->SceneStart();
		subSceneList.emplace_back(p);
		it = addSceneList.erase(it);
	}

	//�T�u�V�[���̍X�V
	for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end(); ++it)
	{
		if ((*it)->IsActive())
		{
			currentScene = *it;
			(*it)->SceneUpdate();
		}
	}

	currentScene = this;
	//���g�̃I�u�W�F�N�g�̃R���|�[�l���g�j��
	for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->DestroyComponents();
	}

	//���g�̃I�u�W�F�N�g�X�V
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

Scene* Scene::GetCurrentScene()
{
	if (currentScene == nullptr)
		return nullptr;
	Scene* p = currentScene->GetCurrentScene();
	if (p == nullptr)
		return this;
	if (p == this)
		return this;
	return p;
}
