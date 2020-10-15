#include "TestTransformScene.h"
#include "TestTransformChara.h"
#include "TestTransformComponent.h"

TestTransformScene::TestTransformScene()
{
	obj = Instantiate<TestTransformChara>();
	obj2 = Instantiate<TestTransformChara>();
	obj->SetChild(obj2);
	obj->AddComponent<TestTransformComponent>();
}

TestTransformScene::~TestTransformScene()
{
}

void TestTransformScene::Start()
{
	VECTOR center = { Screen::x / 2, Screen::y / 2, 0.0f };
	obj->transform->SetPosition(center);
	VECTOR dif = { 200.0f, 0.0f, 0.0f };
	obj2->transform->AddPosition(dif);
}

void TestTransformScene::Update()
{
}
