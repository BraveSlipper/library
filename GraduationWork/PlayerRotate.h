#pragma once
#include "lib/UrLib.h"

class PlayerRotate : public Component {
public:
	void Start();
	void Update();
private:
	ImageRenderer* imageRenderer;
};