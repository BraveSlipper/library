#pragma once
#include "lib/UrLib.h"

class TitleScene : public Scene {
public:
	TitleScene();
	~TitleScene();
	void Start();
	void Update();

	void ResetCount() { count = 0; };

private:
	GameObject* player1;
	GameObject* player2;
	int count;
	int nextSceneCount;
};