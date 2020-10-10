#pragma once

#include <list>
#include <string>
#include <typeinfo>
#include "Object.h"

namespace UrLib {

	class Scene :public Object
	{
	private:
		template<class C>
		static Scene* CreateScene(const std::string& _name) { return new C; }

	private:
		struct NODE
		{
			Scene* (*createScene)(const std::string& _name);
			std::string name;
		};

	public:
		Scene(const std::string& _name) :
			Object(_name)
		{
		}

		~Scene()
		{
			for (std::list<Object*>::iterator it = objectList.begin(); it != objectList.end();)
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

		void Start();

		void Update();

		bool AddGameObject(Object* _object);

		template<class C>
		bool AddSubScene()
		{
			std::string name = typeid(C).name();
			name = name.substr(6ull);

			for (std::list<NODE*>::iterator it = addSceneList.begin(), end = addSceneList.end(); it != end; ++it)
				if (name == (*it)->name)return false;
			for (std::list<Scene*>::iterator it = subSceneList.begin(), end = subSceneList.end(); it != end; ++it)
				if (name == (*it)->GetName())return false;

			NODE node;
			node.name = name;
			node.createScene = CreateScene<C>;

			addSceneList.emplace_back(node);

			return true;
		}

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
			return false;
		}

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
//		void DestroyGameObject();

	private:
		std::list<Object*> objectList;//オブジェクトリスト TODO GameObject

		std::list<Scene*> subSceneList;//サブシーンリスト

		std::list<NODE> addSceneList;//次フレームで追加するサブシーンリスト

	};


}