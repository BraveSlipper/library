#include "Player.h"
#include "PlayerRotate.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	AddComponent<ImageRenderer>()->SetImage("..\\Media\\testImage.png");
	AddComponent<PlayerRotate>();
}
