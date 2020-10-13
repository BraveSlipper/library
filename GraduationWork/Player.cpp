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
	AddComponent<ImageRenderer>()->SetImage("..\\Media\\testImage.png");
	AddComponent<PlayerChanger>();
	AddComponent<PlayerRotate>();
}
