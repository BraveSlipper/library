#pragma once

#include <list>
#include <string>
#include <typeinfo>
#include "GameObject.h"

class SceneManager;

class Scene :public Object
{
	friend SceneManager;

private:
	/// <summary>
	/// シーン生成
	/// </summary>
	/// <typeparam name="C">シーン型</typeparam>
	/// <param name="_name">シーン名</param>
	/// <returns>生成したシーンのアドレス</returns>
	template<class C>
	static Scene* CreateScene() { return new C; }

private:
	struct NODE
	{
		Scene* (*createScene)();//生成するシーンの関数
		std::string name;//生成するシーン名
	};

public:
	Scene() :
		currentScene(nullptr)
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
	/// 初期化
	/// </summary>
	void SceneStart();

	/// <summary>
	/// 更新
	/// </summary>
	void SceneUpdate();

	/// <summary>
	/// ゲームオブジェクト追加
	/// </summary>
	/// <param name="_object">追加するオブジェクト</param>
	/// <returns>true：成功、false：追加済み</returns>
	bool AddGameObject(GameObject* _object);

	/// <summary>
	/// サブシーン追加
	/// </summary>
	/// <typeparam name="C">追加するサブシーン</typeparam>
	/// <returns>true：成功、false：既に存在している</returns>
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
	/// サブシーン破棄
	/// </summary>
	/// <typeparam name="C">破棄するサブシーン</typeparam>
	/// <returns>true：成功、false：存在しない</returns>
	template<class C>
	bool DestroySubScene()
	{
		std::string name = typeid(C).name;

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
	/// サブシーン取得
	/// </summary>
	/// <typeparam name="C">取得するサブシーン</typeparam>
	/// <returns>null以外：サブシーンのアドレス、null：存在しない</returns>
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
	/// ゲームオブジェクト生成
	/// </summary>
	/// <typeparam name="C">生成するオブジェクト</typeparam>
	/// <returns>生成したオブジェクト</returns>
	template<class C>
	GameObject* Instantiate()
	{
		GameObject* obj = new C;
		obj->scene = this;

		Object* p = obj;
		p->className = typeid(C).name;

		obj->name = p->className;

		objectList.emplace_back(obj);

		return obj;
	}

private://SceneManagerで使用
	void SetName(const std::string& _name) { className = _name; }

	/// <summary>
	/// 現在のシーンを再帰的に検索
	/// </summary>
	/// <returns>現在のシーン</returns>
	Scene* GetCurrentScene();

private:
	/// <summary>
	/// 志望フラグが立っているオブジェクトを破棄
	/// </summary>
	void DestroyGameObjects();

private:
	std::list<GameObject*> objectList;//オブジェクトリスト

	std::list<Scene*> subSceneList;//サブシーンリスト

	std::list<NODE> addSceneList;//次フレームで追加するサブシーンリスト

	Scene* currentScene;//現在のシーン

};
