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

	//�T�u�V�[���ēǂݍ���
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

	//�T�u�V�[���̒ǉ�
	for (std::list<NODE>::iterator it = addSceneList.begin(); it != addSceneList.end();)
	{
		Scene* p = it->createScene();
		p->SetName(it->name);
		p->reloadScene = it->createScene;
		p->SceneStart();
		subSceneList.emplace_back(p);
		it = addSceneList.erase(it);
	}

	//�T�u�V�[���̍X�V
	for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end(); ++it)
	{
		if ((*it)->IsActive())
		{
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

void Scene::DestroyGameObjects()
{
	//�e�̎��S�t���O�������Ă���ꍇ�A�q�̎��S�t���O�𗧂Ă�
	for (std::list<GameObject*>::iterator it = objectList.begin(), end = objectList.end(); it != end; ++it)
	{
		if (!(*it)->IsDestroy())continue;

		std::list<GameObject*> children = (*it)->GetChildren();
		for (std::list<GameObject*>::iterator cit = children.begin(), cend = children.end(); cit != cend; ++cit)
		{
			(*it)->Destroy();
		}
	}
	
	//�T�u�V�[���`�F�b�N
	for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
		(*it)->DestroyGameObjects();

	//���g�̃I�u�W�F�N�g�j��
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
