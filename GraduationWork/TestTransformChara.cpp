#include "TestTransformChara.h"
#include "TestTransformComponent.h"

TestTransformChara::TestTransformChara()
{
}

TestTransformChara::~TestTransformChara()
{
}

void TestTransformChara::Start()
{
	AddComponent<ImageRenderer>();
	AddComponent<TestTransformComponent>();
}
