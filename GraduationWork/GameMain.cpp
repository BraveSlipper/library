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

	Delay<GameMain, void>* p = player->AddComponent<Delay<GameMain, void> >();
	p->instance = this;
	p->call = &GameMain::Add;
	p->endTime = 0.2f;
}

void GameMain::Update()
{
	player->transform->position.x -= 1.f;
	static int count;

	if (++count > 100000)
	{
		SceneManager::Get()->LoadScene<TitleScene>();
		count = 0;
	}
	if (Input::IsKeyDown(KEY::KEY_ENTER))SceneManager::Get()->LoadScene<TitleScene>();
	if(Input::IsMouseDown(MOUSE::MOUSE_LEFT))SceneManager::Get()->End();

}

void GameMain::Add()
{
	Player* p = Instantiate<Player>();
	ImageRenderer* renderer = p->GetComponent<ImageRenderer>();
	p->transform->position.x = static_cast<float>(GetRand(Screen::x));
	p->transform->position.y = static_cast<float>(GetRand(Screen::y));
	renderer->scale.x = 0.5f;
	renderer->scale.y = 0.5f;
}
