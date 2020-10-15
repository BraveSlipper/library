#include "TestTransformScene.h"
#include "TestTransformChara.h"

TestTransformScene::TestTransformScene()
{
	obj = Instantiate<TestTransformChara>();
}

TestTransformScene::~TestTransformScene()
{
}

void TestTransformScene::Start()
{
	VECTOR pos = { Screen::x / 2, Screen::y / 2, 0.0f };
	obj->transform->SetPosition(pos);
}

void TestTransformScene::Update()
{
}
