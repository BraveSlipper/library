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
        ret += UrLib::Draw();       // �`�揈��
        ret += ScreenFlip();		// ����ʂƕ\��ʂ̓���
        ret += ClearDrawScreen();	// ����ʂ̕`���S�ď���
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
