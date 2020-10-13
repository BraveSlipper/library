#pragma once
#include "lib/UrLib.h"

class Player;

class GameMain :public Scene
{
public:
	GameMain()
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

};
