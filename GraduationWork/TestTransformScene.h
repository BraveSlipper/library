#pragma once
#include "lib/UrLib.h"

class TestTransformScene : public Scene {
public:
	TestTransformScene();
	~TestTransformScene();
	void Start();
	void Update();
private:
	GameObject* obj;
};