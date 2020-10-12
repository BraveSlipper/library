#include "UrLib.h"

int UrLib::Init()
{
    int ret = 0;

    ret += DxLib_Init();
    ret += SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
    SceneManager::Get()->Start();

    return ret;
}

int UrLib::Update()
{
    int ret = 0;

    while (ret += ProcessMessage(), ret == 0) {
        SceneManager::Get()->Update();      // シーンの更新処理
        ret += UrLib::Draw();               // 描画処理
        ret += ScreenFlip();		        // 裏画面と表画面の入替
        ret += ClearDrawScreen();	        // 裏画面の描画を全て消去
    }
    return ret;
}

int UrLib::Draw()
{
    int ret = 0;
    return ret;
}

int UrLib::End()
{
    int ret = 0;
    return ret;
}
