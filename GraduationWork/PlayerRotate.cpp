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
	if (imageRenderer != nullptr) {
		imageRenderer->rotate += 1.0f;
	}
	else {
		RemoveComponent<PlayerRotate>();
	}
}
