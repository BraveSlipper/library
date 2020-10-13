#include "PlayerChanger.h"

namespace {
	int count = 0;
	ImageRenderer* imageRenderer;
}

void PlayerChanger::Start()
{
	imageRenderer = AddComponent<ImageRenderer>();
	imageRenderer->SetImage("..\\Media\\testImage.png");
}

void PlayerChanger::Update()
{
	if (++count == 240) {
		if (imageRenderer != nullptr)
			imageRenderer->SetImage("..\\Media\\testImage2.png");
	}
	if (count == 480) {
		RemoveComponent<ImageRenderer>();
		imageRenderer = nullptr;
	}
}
