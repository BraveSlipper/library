#pragma once

#include <list>
#include <string>
#include <typeinfo>
#include "GameObject.h"

namespace UrLib {

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
		Scene()
		{
		}

		~Scene()
		{
			for (std::list<GameObject*>::iterator it = objectList.begin(); it != objectList.end();)
			{
				delete* it;
				it = objectList.erase(it);
			}
			for (std::list<Scene*>::iterator it = subSceneList.begin(); it != subSceneList.end();)
			{
				delete* it;
				it = subSceneList.erase(it);
			}
			addSceneList.clear();
		}

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
			name = name.substr(6ull);

			for (std::list<NODE>::iterator it = addSceneList.begin(), end = addSceneList.end(); it != end; ++it)
				if (name == it->name)return false;
			for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
				if (name == (*it)->GetName())return false;

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
			std::string name = typeid(C).name;
			name = name.substr(6ull);

			for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
			{
				if (name == (*it)->GetName())
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

	private:
//		void DestroyGameObject(Object* _object);

	private://SceneManager�Ŏg�p
//		void SetName(const std::string& _name) { name = _name; }//TODO

	private:
		std::list<GameObject*> objectList;//�I�u�W�F�N�g���X�g

		std::list<Scene*> subSceneList;//�T�u�V�[�����X�g

		std::list<NODE> addSceneList;//���t���[���Œǉ�����T�u�V�[�����X�g

	};

}