#include "PlayerComponent.h"

PlayerComponent::PlayerComponent()
{
}

PlayerComponent::~PlayerComponent()
{
}

void PlayerComponent::Start()
{
	printfDx("��ăt���p���[�I�I�I\n");
}

void PlayerComponent::Update()
{
	transform->AddPosition(VGet(-1.0f, 0.0f, 0.0f));
}
