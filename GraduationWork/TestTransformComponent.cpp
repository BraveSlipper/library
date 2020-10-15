#include "TestTransformComponent.h"

TestTransformComponent::TestTransformComponent()
{
}

TestTransformComponent::~TestTransformComponent()
{
}

void TestTransformComponent::Start()
{
}

void TestTransformComponent::Update()
{
	transform->AxisRotateY(1.0f);
}
