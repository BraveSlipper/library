#include "UrLib.h"
#include "DrawManager.h"

int Screen::x = 800;
int Screen::y = 600;

int UrLib::Init()
{
    int ret = 0;

    ret += DxLib_Init();
    ret += SetDrawScreen(DX_SCREEN_BACK);	//— ‰æ–Ê‚ğ•`‰æ‘ÎÛ‚Ö
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
        ret += clsDx();
        SceneManager::Get()->Update();      // ƒV[ƒ“‚ÌXVˆ—
        ret += UrLib::Draw();               // •`‰æˆ—
        ret += ScreenFlip();		        // — ‰æ–Ê‚Æ•\‰æ–Ê‚Ì“ü‘Ö
        ret += ClearDrawScreen();	        // — ‰æ–Ê‚Ì•`‰æ‚ğ‘S‚ÄÁ‹
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
