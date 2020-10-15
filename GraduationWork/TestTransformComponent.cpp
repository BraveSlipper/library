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
	if (Input::IsKeyPush(KEY::KEY_LEFT))	transform->AddPosition(-2.0f);
	if (Input::IsKeyPush(KEY::KEY_RIGHT))	transform->AddPosition(2.0f);
	if (Input::IsKeyPush(KEY::KEY_UP))		transform->AddPosition(0.0f, 2.0f);
	if (Input::IsKeyPush(KEY::KEY_DOWN))	transform->AddPosition(0.0f, -2.0f);

	if (Input::IsKeyPush(KEY::KEY_X))		transform->AxisRotateX(2.0f);
	if (Input::IsKeyPush(KEY::KEY_Y))		transform->AxisRotateY(2.0f);
	if (Input::IsKeyPush(KEY::KEY_Z))		transform->AxisRotateZ(2.0f);

	printfDx("pos.x = %f\n", transform->position.x);
	printfDx("pos.y = %f\n", transform->position.y);
	printfDx("pos.z = %f\n", transform->position.z);
	printfDx("\n");
	printfDx("rot.x = %f\n", transform->rotation.x);
	printfDx("rot.y = %f\n", transform->rotation.y);
	printfDx("rot.z = %f\n", transform->rotation.z);
}
