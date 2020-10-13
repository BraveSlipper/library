#include "Player.h"
#include "PlayerComponent.h"
#include "PlayerChild.h"
#include "PlayerChanger.h"
#include "PlayerRotate.h"

Player::Player() :
	testChild(nullptr)
{
}

Player::~Player()
{
}

void Player::Start()
{
	transform->position.x = Screen::x / 2;
	transform->position.y = Screen::y / 2;
	testChild = Instantiate<PlayerChild>();
	testChild->SetParent(this);
	AddComponent<PlayerChanger>();
	AddComponent<PlayerRotate>();
}
