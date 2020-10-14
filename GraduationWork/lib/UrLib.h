#pragma once
#include "dxlib/DxLib.h"
#include "typedef.h"
#include "Function.h"
#include "SceneManager.h"
#include "Transform.h"
#include "ImageRenderer.h"
#include "Input.h"

namespace UrLib {
	int Init();
	int Init(int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int WindowMode, int RefreshRate = 60);
	void Update();
	int Draw();
	int End();

	class Screen {
	public:
		static int x, y;
	};
}
using namespace UrLib;