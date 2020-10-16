#pragma once
#include "dxlib/DxLib.h"
#include "typedef.h"
#include "Function.h"
#include "SceneManager.h"
#include "Transform.h"
#include "ImageRenderer.h"
#include "Input.h"
#include "Time.h"
#include "Delay.h"

namespace UrLib {
	int Init(int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int WindowMode);
	void Update();
	int Draw();
	int End();

	class Screen {
	public:
		static int x, y;
	};
}
using namespace UrLib;