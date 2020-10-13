#include "TitleSubScene.h"
#include "Player.h"

namespace {
	int count = 0;
	GameObject* player;
	GameObject* child;
}

TitleSubScene::TitleSubScene()
{
	player = Instantiate<Player>();
	child = Instantiate<Player>();
}

TitleSubScene::~TitleSubScene()
{
}

void TitleSubScene::Start()
{
	child->SetParent(player);
	child->transform->position.x = -100.0f;
}

void TitleSubScene::Update()
{
	if (++count > 120)
		SceneManager::Get()->DestroySubScene<TitleSubScene>();
}
