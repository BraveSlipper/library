#include "GameObject.h"

GameObject::GameObject() :
	transform(this), parent(nullptr)
{
	compList.clear();
	children.clear();
}

GameObject::~GameObject()
{
}

void GameObject::Start()
{
}

void GameObject::Update()
{
}

GameObject* GameObject::GetParent() const
{
	return parent;
}

void GameObject::SetParent(GameObject* _obj)
{
	parent = _obj;
	_obj->SetChild(this);
}

GameObject* GameObject::GetChild(std::string _name) const
{
	for (auto child : children) {
		if (child->GetName() == _name)
			return child;
	}
	return nullptr;
}

std::list<GameObject*> GameObject::GetChildren() const
{
	return children;
}

bool GameObject::SetChild(GameObject* _obj)
{
	// 既に子に存在したら終了
	for (auto child : children) {
		if (child == _obj)
			return false;
	}

	// 子のリストに追加
	children.push_back(_obj);

	return true;
}

bool GameObject::RemoveChild(std::string _name)
{
	return false;
}

void GameObject::RemoveChildren()
{
}
