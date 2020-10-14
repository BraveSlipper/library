#include "TitleScene.h"
#include "TitleSubScene.h"
#include "Player.h"
#include "GameMain.h"
#include "PlayerRotate.h"
#include "PlayerChanger.h"

TitleScene::TitleScene() :
	count(0), nextSceneCount(6)
{
	player1 = Instantiate<Player>();
	player2 = Instantiate<Player>();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Start()
{
	count = 0;
	nextSceneCount = 6;
	player1->AddComponent<PlayerChanger>();
	player2->AddComponent<PlayerChanger>();
	player2->transform->position.x = static_cast<float>(Screen::x);
	player2->transform->position.y = static_cast<float>(Screen::y);
	player2->GetComponent<PlayerRotate>()->SetRotate(180.0f);
}

void TitleScene::Update()
{
	printfDx("TitleScene\n");
	if (++count == 60) {
		SceneManager::Get()->AddSubScene<TitleSubScene>();
		--nextSceneCount;
		if (nextSceneCount == 0)
			SceneManager::Get()->LoadScene<GameMain>();
	}
}
