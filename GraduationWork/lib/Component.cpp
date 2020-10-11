#include "Component.h"

Component::Component() :
	gameObject(nullptr)
{
}

Component::Component(GameObject* _actor) :
	gameObject(_actor)
{
}

Component::~Component()
{
}

void Component::Start()
{
}

void Component::Update()
{
}
