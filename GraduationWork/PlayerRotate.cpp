#include "PlayerRotate.h"

namespace {
	ImageRenderer* imageRenderer;
}

void PlayerRotate::Start()
{
	imageRenderer = GetComponent<ImageRenderer>();
}

void PlayerRotate::Update()
{
	imageRenderer->rotate += 1.0f;
}
