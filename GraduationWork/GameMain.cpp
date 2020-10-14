#include "GameMain.h"
#include "Player.h"
#include "PlayerChild.h"
#include "TitleScene.h"
#include "PlayerChanger.h"

void GameMain::Start()
{
	player = Instantiate<Player>();
	player->SetChild(Instantiate<PlayerChild>());
	player->transform->position.x = 800;
	player->AddComponent<PlayerChanger>();
	ImageRenderer* renderer = player->GetComponent<ImageRenderer>();
	renderer->SetImage("..\\Media\\testImage.png");
	renderer->scale.x = renderer->scale.y = 0.3f;
}

void GameMain::Update()
{
	player->transform->position.x -= 1.f;
	static int count;

	if (++count > 300)
	{
		SceneManager::Get()->LoadScene<TitleScene>();
		count = 0;
	}
	if (Input::IsKeyDown(KEY::KEY_ENTER))SceneManager::Get()->LoadScene<TitleScene>();
	if(Input::IsMouseDown(MOUSE::MOUSE_LEFT))SceneManager::Get()->End();
}
