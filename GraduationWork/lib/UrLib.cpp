#include "UrLib.h"

int UrLib::Init()
{
    int ret = 0;

    ret += DxLib_Init();

    return 0;
}

int UrLib::Update()
{
    int ret = 0;

    while (ret += ProcessMessage(), ret == 0) {
        ret += UrLib::Draw();       // 描画処理
        ret += ScreenFlip();		// 裏画面と表画面の入替
        ret += ClearDrawScreen();	// 裏画面の描画を全て消去
    }
    return 0;
}

int UrLib::Draw()
{
    return 0;
}

int UrLib::End()
{
    return 0;
}
