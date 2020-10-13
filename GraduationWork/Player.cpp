#include "Player.h"
#include "PlayerChanger.h"
#include "PlayerRotate.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	AddComponent<ImageRenderer>();
	AddComponent<PlayerChanger>();
	AddComponent<PlayerRotate>();
}
