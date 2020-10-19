#pragma once
#include "lib/UrLib.h"

class Player;

class GameMain :public Scene
{
public:
	GameMain():
		num(0)
	{
	}

	~GameMain()
	{
	}

	void Start()override;

	void Update()override;

private:
	GameObject* player;
	Component* control;

	ImageRenderer* renderer;

	int num;

	void Add();
};
