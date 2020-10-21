#pragma once

#include "dxlib/DxLib.h"

#include "Component.h"

class SoundListener : public Component
{
public:
	SoundListener() :
		prevPos(VGet(0.f, 0.f, 0.f))
	{
	}

	~SoundListener()
	{
	}

	void Start();

	void Update();

private:
	VECTOR prevPos;//前フレーム座標

};
