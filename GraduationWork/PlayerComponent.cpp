#include "PlayerComponent.h"

PlayerComponent::PlayerComponent()
{
}

PlayerComponent::~PlayerComponent()
{
}

void PlayerComponent::Start()
{
	printfDx("component Start!\n");
}

void PlayerComponent::Update()
{
	printfDx("position.x = %f\n", transform->position.x);
}
