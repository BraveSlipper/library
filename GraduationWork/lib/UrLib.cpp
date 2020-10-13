#include "UrLib.h"
#include "DrawManager.h"

int UrLib::Init()
{
    int ret = 0;

    ret += DxLib_Init();
    ret += SetDrawScreen(DX_SCREEN_BACK);	//— ‰æ–Ê‚ğ•`‰æ‘ÎÛ‚Ö
    SceneManager::Get()->Start();

    return ret;
}

int UrLib::Update()
{
    int ret = 0;

    while (ret += ProcessMessage(), ret == 0) {
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
