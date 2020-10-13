#include "TitleScene.h"
#include "TitleSubScene.h"
#include "Player.h"

namespace {
	int count = 0;
	GameObject* player;
	GameObject* child;
}

TitleScene::TitleScene()
{
	player = Instantiate<Player>();
	child = Instantiate<Player>();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Start()
{
	child->SetParent(player);
	child->transform->position.x = 100.0f;
}

void TitleScene::Update()
{
	if (++count > 240) {
		SceneManager::Get()->AddSubScene<TitleSubScene>();
		count = 0;
	}
}
