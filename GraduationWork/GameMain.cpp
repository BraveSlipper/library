#include "GameMain.h"
#include "Player.h"
#include "PlayerChild.h"
#include "TitleScene.h"
#include "PlayerChanger.h"
#include "PlayerComponent.h"
#include "PlayerRotate.h"

void GameMain::Start()
{
	Player* player = Instantiate<Player>();
	player->RemoveComponent<PlayerRotate>();
	player->AddComponent<PlayerComponent>();
	player->transform->position.x = 800;
	player->transform->position.y = 200;
	ImageRenderer* renderer = player->GetComponent<ImageRenderer>();
	renderer->SetImage("..\\Media\\testImage3.png");
	renderer->scale.x = renderer->scale.y = 0.5f;

	Delay<GameMain, void>* p = player->AddComponent<Delay<GameMain, void> >();
	p->instance = this;
	p->call = &GameMain::Add;
	p->endTime = 0.1f;
}

void GameMain::Update()
{
	static int count;

	if (++count > 100000)
	{
		SceneManager::Get()->LoadScene<TitleScene>();
		count = 0;
	}
	if (Input::IsKeyDown(KEY::KEY_ENTER))SceneManager::Get()->LoadScene<TitleScene>();
	if (Input::IsMouseDown(MOUSE::MOUSE_LEFT))SceneManager::Get()->End();

}

void GameMain::Add()
{
	Player* p = Instantiate<Player>();
	p->RemoveComponent<PlayerRotate>();
	p->AddComponent<PlayerComponent>();
	ImageRenderer* renderer = p->GetComponent<ImageRenderer>();
	p->transform->position.x = static_cast<float>(Screen::x);
	p->transform->position.y = static_cast<float>(GetRand(Screen::y));
	renderer->scale.x = 0.5f;
	renderer->scale.y = 0.5f;
	renderer->SetImage("..\\Media\\testImage3.png");
}
