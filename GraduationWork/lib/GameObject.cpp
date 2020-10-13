#include "GameObject.h"
#include "Transform.h"

GameObject::GameObject() :
	parent(nullptr), scene(nullptr), name("")
{
	transform = new Transform();
	compList.clear();
	children.clear();
}

GameObject::~GameObject()
{
	delete transform;
	for (auto it = compList.begin(); it != compList.end();) {
		delete (*it);
		it = compList.erase(it);
	}
}

void GameObject::Update()
{	
	// 更新処理
	for (auto comp : compList) {
		if (comp->IsActive()) {
			comp->Update();
		}
	}
}

GameObject* GameObject::GetParent() const
{
	return parent;
}

void GameObject::SetParent(GameObject* _obj)
{
	// 引数がnullptrなら終了
	if (_obj == nullptr) return;

	parent = _obj;
	_obj->SetChild(this);
}

GameObject* GameObject::GetChild(std::string _name) const
{
	// 対応した名前の子GameObject抽出
	for (auto child : children) {
		if (child->name == _name) {
			return child;
		}
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
	_obj->parent = this;

	return true;
}

bool GameObject::RemoveChild(std::string _name)
{
	// 対応した名前の子GameObjectの破壊フラグを立てる
	for (auto child : children) {
		if (child->name == _name) {
			child->Destroy();
			return true;
		}
	}
	return false;
}

void GameObject::RemoveChildren()
{
	// 全ての子GameObjectの破壊フラグを立てる
	for (auto child : children) {
		child->Destroy();
	}
}

void GameObject::DestroyComponents()
{
	for (auto it = compList.begin(); it != compList.end();) {
		if ((*it)->IsDestroy()) {
			delete (*it);
			it = compList.erase(it);
		}
		else {
			++it;
		}
	}
}

Scene* GameObject::GetScene() const
{
	return scene;
}

GameObject* GameObject::func(GameObject* _p)
{
	scene->AddGameObject(_p);

	_p->scene = scene;

	return _p;
}