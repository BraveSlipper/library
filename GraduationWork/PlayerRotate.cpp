#include "PlayerRotate.h"

void PlayerRotate::Start()
{
	imageRenderer = GetComponent<ImageRenderer>();
}

void PlayerRotate::Update()
{
	imageRenderer->rotate += 1.0f;
}
