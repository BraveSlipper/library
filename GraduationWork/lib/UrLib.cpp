#include "UrLib.h"
#include "DrawManager.h"

int Screen::x = 800;
int Screen::y = 600;

int UrLib::Init()
{
    int ret = 0;

    ret += DxLib_Init();
    ret += SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
    SceneManager::Get()->Start();

    return ret;
}

int UrLib::Init(int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int WindowMode, int RefreshRate)
{
    Screen::x = ScreenSizeX;
    Screen::y = ScreenSizeY;
    ChangeWindowMode(WindowMode);
    SetGraphMode(Screen::x, Screen::y, ColorBitDepth, RefreshRate);
    return Init();
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
    DrawManager::Get()->Draw();
    return ret;
}

int UrLib::End()
{
    int ret = 0;
    SceneManager::Get()->Destroy();
    DrawManager::Get()->Destroy();
    return ret;
}
