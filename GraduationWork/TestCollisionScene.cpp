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
	
	CircleCollider2D* circleCollider2D = player1->AddComponent<CircleCollider2D>();
	circleCollider2D->SetRadius(100.0f);
	circleCollider2D = player2->AddComponent<CircleCollider2D>();
	circleCollider2D->SetRadius(100.0f);

	player2->transform->SetPosition(VGet(Screen::x * 0.5f, Screen::y * 0.5f, 0.0f));
}

void TestCollisionScene::Update()
{
	player1->GetComponent<CircleCollider2D>()->Disp();
	player2->GetComponent<CircleCollider2D>()->Disp();
}
