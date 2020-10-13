#include "TitleScene.h"
#include "TitleSubScene.h"
#include "Player.h"
#include "GameMain.h"

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
	count = 0;
	nextSceneCount = 10;
	child->SetParent(player);
	child->transform->position.x = 200.0f;
}

void TitleScene::Update()
{
	printfDx("TitleScene\n");
	if (++count > 60) {
		SceneManager::Get()->AddSubScene<TitleSubScene>();
		count = 0;
		--nextSceneCount;
		if (nextSceneCount == 0)
			SceneManager::Get()->LoadScene<GameMain>();
	}
}
