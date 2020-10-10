#include "Object.h"

Object::Object() :
    name(""), active(true), isDestroy(false)
{
}

Object::Object(std::string _name) :
    name(_name), active(true), isDestroy(false)
{
}

Object::~Object()
{
}

void Object::Start()
{
}

void Object::Update()
{
}

std::string Object::GetName() const
{
    return name;
}

bool Object::IsActive() const
{
    return active;
}

void Object::SetActive(bool _active)
{
    active = _active;
}

bool Object::IsDestroy() const
{
    return isDestroy;
}

void Object::Destroy()
{
    isDestroy = true;
}
