#include "Player.h"
#include "PlayerComponent.h"
#include "PlayerChild.h"

Player::Player() :
	testChild(nullptr)
{
}

Player::~Player()
{
}

void Player::Start()
{
	testChild = Instantiate<PlayerChild>();
	testChild->SetParent(this);
	testChild->SetChild(Instantiate<PlayerChild>());
	testChild->transform->position.x = 100.0f;
}
