#include "GameObject.h"
#include "Transform.h"

GameObject::GameObject() :
	parent(nullptr), scene(nullptr)
{
	transform = new Transform(this);
	compList.clear();
	children.clear();
}

GameObject::GameObject(Scene* _scene) :
	parent(nullptr), scene(_scene)
{
	transform = new Transform(this);
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

void GameObject::Start()
{
}

void GameObject::Update()
{	
	// �X�V����
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
	parent = _obj;
	_obj->SetChild(this);
}

GameObject* GameObject::GetChild(std::string _name) const
{
	// �Ή��������O�̎qGameObject���o
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
	// ���Ɏq�ɑ��݂�����I��
	for (auto child : children) {
		if (child == _obj)
			return false;
	}

	// �q�̃��X�g�ɒǉ�
	children.push_back(_obj);

	return true;
}

bool GameObject::RemoveChild(std::string _name)
{
	// �Ή��������O�̎qGameObject�̔j��t���O�𗧂Ă�
	for (auto child : children) {
		if (child->GetName() == _name) {
			child->Destroy();
			return true;
		}
	}
	return false;
}

void GameObject::RemoveChildren()
{
	// �S�Ă̎qGameObject�̔j��t���O�𗧂Ă�
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
