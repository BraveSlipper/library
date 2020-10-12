#include "Player.h"
#include "PlayerComponent.h"
#include "PlayerChild.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	GameObject* obj = Instantiate<PlayerChild>();
	obj->SetParent(this);
	obj->transform->position.x = 100.0f;
}
