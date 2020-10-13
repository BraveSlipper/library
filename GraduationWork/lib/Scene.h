#pragma once

#include <list>
#include <string>
#include <typeinfo>
#include <new>
#include "GameObject.h"

class SceneManager;

class Scene :public Object
{
	friend SceneManager;

private:
	/// <summary>
	/// �V�[������
	/// </summary>
	/// <typeparam name="C">�V�[���^</typeparam>
	/// <param name="_name">�V�[����</param>
	/// <returns>���������V�[���̃A�h���X</returns>
	template<class C>
	static Scene* CreateScene() { return new C; }

private:
	struct NODE
	{
		Scene* (*createScene)();//��������V�[���̊֐�
		std::string name;//��������V�[����
	};

public:
	Scene() :
		isReload(false), reloadScene(nullptr)
	{
	}

	virtual~Scene();

	/// <summary>
	/// ������
	/// </summary>
	void SceneStart();

	/// <summary>
	/// �X�V
	/// </summary>
	void SceneUpdate();

	/// <summary>
	/// �Q�[���I�u�W�F�N�g�ǉ�
	/// </summary>
	/// <param name="_object">�ǉ�����I�u�W�F�N�g</param>
	/// <returns>true�F�����Afalse�F�ǉ��ς�</returns>
	bool AddGameObject(GameObject* _object);

	/// <summary>
	/// �T�u�V�[���ǉ�
	/// </summary>
	/// <typeparam name="C">�ǉ�����T�u�V�[��</typeparam>
	/// <returns>true�F�����Afalse�F���ɑ��݂��Ă���</returns>
	template<class C>
	bool AddSubScene()
	{
		std::string name = typeid(C).name();

		for (std::list<NODE>::iterator it = addSceneList.begin(), end = addSceneList.end(); it != end; ++it)
			if (name == it->name)return false;
		for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
			if (name == (*it)->GetTypeName())return false;

		NODE node;
		node.name = name;
		node.createScene = CreateScene<C>;

		addSceneList.emplace_back(node);

		return true;
	}

	/// <summary>
	/// �T�u�V�[���j��
	/// </summary>
	/// <typeparam name="C">�j������T�u�V�[��</typeparam>
	/// <returns>true�F�����Afalse�F���݂��Ȃ�</returns>
	template<class C>
	bool DestroySubScene()
	{
		std::string name = typeid(C).name();

		for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
		{
			if (name == (*it)->GetTypeName())
			{
				(*it)->Destroy();
				return true;
			}
		}
		for (std::list<NODE>::iterator it = addSceneList.begin(), end = addSceneList.end(); it != end; ++it)
		{
			if (name == it->name)
			{
				addSceneList.erase(it);
				return true;
			}
		}
		return false;
	}

	/// <summary>
	/// �T�u�V�[���擾
	/// </summary>
	/// <typeparam name="C">�擾����T�u�V�[��</typeparam>
	/// <returns>null�ȊO�F�T�u�V�[���̃A�h���X�Anull�F���݂��Ȃ�</returns>
	template<class C>
	C* GetSubScene()
	{
		C* p = nullptr;
		for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
		{
			p = dynamic_cast<C*>(*it);
			if (p != nullptr)
				return p;
		}
		return nullptr;
	}

	/// <summary>
	/// �Q�[���I�u�W�F�N�g����
	/// </summary>
	/// <typeparam name="C">��������I�u�W�F�N�g</typeparam>
	/// <returns>���������I�u�W�F�N�g</returns>
	template<class C>
	C* Instantiate(std::string _name = "")
	{
		GameObject* obj = new C;
		obj->scene = this;

		Object* p = obj;
		p->className = typeid(C).name();

		if (_name == "") {
			obj->name = p->className.substr(6ull);
		}
		else
			obj->name = _name;

		objectList.emplace_back(obj);

		obj->Start();

		return reinterpret_cast<C*>(obj);
	}

	/// <summary>
	/// �ēǂݍ���
	/// </summary>
	void Reload() { isReload = true; }

	/// <summary>
	/// ���݂̃V�[�����ċA�I�Ɍ���
	/// </summary>
	/// <returns>���݂̃V�[��</returns>
	static Scene* GetCurrentScene() { return currentScene; }

private://SceneManager�Ŏg�p
	void SetName(const std::string& _name) { className = _name; }

	/// <summary>
	/// �ēǂݍ��݃t���O���擾
	/// </summary>
	/// <returns>true�F�t���O�������Ă���Afalse�F�t���O�������ĂȂ�</returns>
	bool IsReload()const { return isReload; }

private:
	/// <summary>
	/// ���S�t���O�������Ă���I�u�W�F�N�g��j��
	/// </summary>
	void DestroyGameObjects();

private:
	std::list<GameObject*> objectList;//�I�u�W�F�N�g���X�g

	std::list<Scene*> subSceneList;//�T�u�V�[�����X�g

	std::list<NODE> addSceneList;//���t���[���Œǉ�����T�u�V�[�����X�g

	static Scene* currentScene;//���݂̃V�[��

	bool isReload;//�����[�h�t���O

	Scene* (*reloadScene)();//�V�[���̍ēǂݍ���

};
