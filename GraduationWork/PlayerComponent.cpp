#include "PlayerComponent.h"

PlayerComponent::PlayerComponent() : 
	isStarted(false)
{
}

PlayerComponent::~PlayerComponent()
{
}

void PlayerComponent::Start()
{
	printfDx("component Start!");
}

void PlayerComponent::Update()
{
	printfDx("%f", transform->position.x);
}
