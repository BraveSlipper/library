#pragma once
#include "Object.h"
#include "GameObject.h"

class Transform;

class Component : public Object {
public:
	Component();
	Component(GameObject* _actor);
	~Component();

	virtual void Start();
	virtual void Update();

	/// <summary>
	/// Component��ǉ�����
	/// </summary>
	/// <typeparam name="C">�ǉ�������Component�̃N���X</typeparam>
	/// <returns>�ǉ�����Component�̃|�C���^�[</returns>
	template<class C>
	inline C* AddComponent();

	/// <summary>
	/// �w�肵��Component���擾����
	/// </summary>
	/// <typeparam name="C">�擾������Component�̃N���X</typeparam>
	/// <returns>�����Ŏw�肵��Component�̃|�C���^�[�A���s��nullptr</returns>
	template<class C>
	C* GetComponent();

	/// <summary>
	/// �w�肵��Component��j������
	/// </summary>
	/// <typeparam name="C">�j��������Component�̃N���X</typeparam>
	/// <returns>������true�A�w�肵���N���X��Component��������Ȃ����false</returns>
	template<class C>
	bool RemoveComponent();

	Transform* transform;			// ���L�҂̃g�����X�t�H�[��

protected:
	GameObject* gameObject;			// ���L�҂̃|�C���^�[

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
