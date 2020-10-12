#pragma once
#include "SceneManager.h"

class Transform;

class Component : public Object {
public:
	Component();
	~Component();

	virtual void Start();
	virtual void Update();

	/// <summary>
	/// Componentを追加する
	/// </summary>
	/// <typeparam name="C">追加したいComponentのクラス</typeparam>
	/// <returns>追加したComponentのポインター</returns>
	template<class C>
	inline C* AddComponent();

	/// <summary>
	/// 指定したComponentを取得する
	/// </summary>
	/// <typeparam name="C">取得したいComponentのクラス</typeparam>
	/// <returns>成功で指定したComponentのポインター、失敗でnullptr</returns>
	template<class C>
	C* GetComponent();

	/// <summary>
	/// 指定したComponentを破棄する
	/// </summary>
	/// <typeparam name="C">破棄したいComponentのクラス</typeparam>
	/// <returns>成功でtrue、指定したクラスのComponentが見つからなければfalse</returns>
	template<class C>
	bool RemoveComponent();

	/// <summary>
	/// GameObjectを生成する
	/// </summary>
	/// <typeparam name="C">生成したいGameObjectのクラス</typeparam>
	/// <returns>生成したGameObjectのポインター</returns>
	template<class C>
	inline GameObject* Instantiate();

	Transform* transform;			// 所有者のトランスフォーム

protected:
	GameObject* gameObject;			// 所有者のポインター

private:

};

template<class C>
inline C* Component::AddComponent()
{
	return gameObject->AddComponent<C>();
}

template<class C>
inline C* Component::GetComponent()
{
	return gameObject->GetComponent<C>();
}

template<class C>
inline bool Component::RemoveComponent()
{
	return gameObject->RemoveComponent<C>();
}

template<class C>
inline GameObject* Component::Instantiate()
{
	return SceneManager::Get()->GetMainScene<Scene>()->GetCurrentScene()->Instantiate<C>();
}
