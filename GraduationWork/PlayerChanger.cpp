#include "PlayerChanger.h"

namespace {
	int count = 0;
	ImageRenderer* imageRenderer;
}

void PlayerChanger::Start()
{
	imageRenderer = GetComponent<ImageRenderer>();
}

void PlayerChanger::Update()
{
	if (++count == 120) {
		imageRenderer->SetImage("..\\Media\\testImage2.png");
	}
	else if (count > 240) {
		count = 0;
		imageRenderer->SetImage("..\\Media\\testImage.png");
	}
}
