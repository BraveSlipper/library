#pragma once

#include "Scene.h"

namespace UrLib {

	class SceneManager
	{
	public:
		static SceneManager* Get();

	private:
		SceneManager():
			mainScene(nullptr), createScene(nullptr)
		{
		}

		~SceneManager()
		{
			if (mainScene != nullptr)
			{
				delete mainScene;
				mainScene = nullptr;
			}
		}

	public:
		bool Destroy();

		void Start();

		void Update();

		template<class C>
		bool LoadScene()
		{
			sceneName = typeid(C).name;
			createScene = Scene::CreateScene<C>;
		}

		template<class C>
		bool AddSubScene()
		{
			if (mainScene == nullptr)return false;

			return mainScene->AddSubScene<C>();
		}

		template<class C>
		bool DestroySubScene()
		{
			if (mainScene == nullptr)return false;

			return mainScene->DestroySubScene<C>();
		}

		template<class C>
		C* GetScene() { return dynamic_cast<C*>(mainScene); }

	private:
		void CreateScene();

	private:
		Scene* mainScene;

		Scene* (*createScene)(std::string& _name);

		std::string sceneName;

		static SceneManager* singleton;

	};



}