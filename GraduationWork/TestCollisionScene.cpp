#include "TestCollisionScene.h"
#include "Player.h"
#include "TestTransformComponent.h"

TestCollisionScene::TestCollisionScene()
{
	player1 = Instantiate<Player>();
	player2 = Instantiate<Player>();
}

TestCollisionScene::~TestCollisionScene()
{
}

void TestCollisionScene::Start()
{
	player1->GetComponent<ImageRenderer>()->SetImage("..\\Media\\testCircle.png");
	player1->AddComponent<TestTransformComponent>()->UseControl(true);
	player2->GetComponent<ImageRenderer>()->SetImage("..\\Media\\testCircle.png");
	
	BoxCollider* boxCollider = player1->AddComponent<BoxCollider>();
	boxCollider->SetLength(0, 100.0f);
	boxCollider->SetLength(1, 100.0f);
	boxCollider->SetLength(2, 100.0f);
	boxCollider = player2->AddComponent<BoxCollider>();
	boxCollider->SetLength(0, 100.0f);
	boxCollider->SetLength(1, 100.0f);
	boxCollider->SetLength(2, 100.0f);

	player2->transform->SetPosition(VGet(Screen::x * 0.5f, Screen::y * 0.5f, 0.0f));
}

void TestCollisionScene::Update()
{
	player1->GetComponent<BoxCollider>()->Disp();
	player2->GetComponent<BoxCollider>()->Disp();
}
