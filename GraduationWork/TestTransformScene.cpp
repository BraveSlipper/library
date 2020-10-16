#include "TestTransformScene.h"
#include "TestTransformChara.h"
#include "TestTransformComponent.h"

TestTransformScene::TestTransformScene()
{
	obj = Instantiate<TestTransformChara>();
	obj2 = Instantiate<TestTransformChara>();
	obj3 = Instantiate<TestTransformChara>();
	obj->SetChild(obj2);
	obj2->SetChild(obj3);
}

TestTransformScene::~TestTransformScene()
{
}

void TestTransformScene::Start()
{
	obj->GetComponent<TestTransformComponent>()->UseControl(true);
	VECTOR center = { Screen::x / 2, Screen::y / 2, 0.0f };
	obj->transform->SetPosition(center);
	VECTOR dif = { 200.0f, 0.0f, 0.0f };
	obj2->transform->AddPosition(dif);
	obj3->transform->AddPosition(dif);
}

void TestTransformScene::Update()
{
}
