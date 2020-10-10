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
        ret += UrLib::Draw();       // •`‰æˆ—
        ret += ScreenFlip();		// — ‰æ–Ê‚Æ•\‰æ–Ê‚Ì“ü‘Ö
        ret += ClearDrawScreen();	// — ‰æ–Ê‚Ì•`‰æ‚ğ‘S‚ÄÁ‹
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
