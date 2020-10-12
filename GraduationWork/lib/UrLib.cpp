#include "UrLib.h"

int UrLib::Init()
{
    int ret = 0;

    ret += DxLib_Init();
    ret += SetDrawScreen(DX_SCREEN_BACK);	//����ʂ�`��Ώۂ�
    SceneManager::Get()->Start();

    return ret;
}

int UrLib::Update()
{
    int ret = 0;

    while (ret += ProcessMessage(), ret == 0) {
        SceneManager::Get()->Update();      // �V�[���̍X�V����
        ret += UrLib::Draw();               // �`�揈��
        ret += ScreenFlip();		        // ����ʂƕ\��ʂ̓���
        ret += ClearDrawScreen();	        // ����ʂ̕`���S�ď���
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
