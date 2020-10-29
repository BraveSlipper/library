#include "GameMain.h"
#include "Player.h"
#include "PlayerChild.h"
#include "TitleScene.h"
#include "PlayerChanger.h"
#include "PlayerComponent.h"
#include "PlayerRotate.h"

void GameMain::Start()
{
	player = Instantiate<Player>();
	player->RemoveComponent<PlayerRotate>();
//	player->AddComponent<PlayerComponent>();
	player->SetChild(Instantiate<PlayerChild>());
	for (GameObject* p : player->GetChildren())
	{
		p->RemoveComponent<PlayerComponent>();
		p->AddComponent<SoundListener>();
	}
	player->transform->position.x = 800;
	player->transform->position.y = 200;
	ImageRenderer* renderer = player->GetComponent<ImageRenderer>();
	renderer->SetImage("..\\Media\\testImage3.png");
	renderer->scale.x = renderer->scale.y = 0.5f;

	Delay<GameMain, void>* p = player->AddComponent<Delay<GameMain, void> >();
	p->instance = this;
	p->call = &GameMain::Add;
	p->endTime = 0.1f;

	Sound* s = player->AddComponent<Sound>();
	s->isLoop = true;

	player->transform->position = VGet(0.f, 0.f, 0.f);

	int h=MV1LoadModel("../Model/‰‰¹ƒ~ƒN.pmd");
	int num = MV1GetMeshNum(h);
	if (num == 1)
	{
		int a = 0;
	}
	MV1SetMeshVisible(h, 0, FALSE);
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

	printfDx("time:%f\n", Time::DeltaTime());
	printfDx("time:%f\n", Time::DeltaTime());

	if (Input::IsKeyDown(KEY::KEY_J))
	{
		Sound* s = player->GetComponent<Sound>();
		s->Load("../Sound/testVoice.mp3");
		s->isLoop = false;
		s->Play();
	}
	if (Input::IsKeyDown(KEY::KEY_F))
	{
		Sound* s = player->GetComponent<Sound>();
		s->Load3D("../Sound/testBGM.mp3");
		s->isLoop = true;
		s->Play();
	}

	if (Input::IsKeyPush(KEY::KEY_UP))
	{
		Sound* s = player->GetComponent<Sound>();
		s->volume++;
	}
	if (Input::IsKeyPush(KEY::KEY_DOWN))
	{
		Sound* s = player->GetComponent<Sound>();
		s->volume--;
	}
	if (Input::IsKeyPush(KEY::KEY_LEFT))
	{
		Sound* s = player->GetComponent<Sound>();
		s->pan--;
	}
	if (Input::IsKeyPush(KEY::KEY_RIGHT))
	{
		Sound* s = player->GetComponent<Sound>();
		s->pan++;
	}
	Sound* s = player->GetComponent<Sound>();
	printfDx("pan:%d\n", s->pan);
	printfDx("volume:%d\n", s->volume);

	if (Input::IsKeyPush(KEY::KEY_5))
	{
		for (GameObject* p : player->GetChildren())
		{
			p->transform->AddPosition(VGet(0.1f, 0.f, 0.f));
		}
	}
	if (Input::IsKeyPush(KEY::KEY_6))
	{
		for (GameObject* p : player->GetChildren())
		{
			p->transform->AddPosition(VGet(-0.1f, 0.f, 0.f));
		}
	}
	for (GameObject* p : player->GetChildren())
	{
		printfDx("posx:%f\n", p->transform->position.x);
		printfDx("posy:%f\n", p->transform->position.y);
		printfDx("posz:%f\n", p->transform->position.z);
	}
	printfDx("playerx:%f\n", player->transform->position.x);
	printfDx("playery:%f\n", player->transform->position.y);
	printfDx("playerz:%f\n", player->transform->position.z);
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
