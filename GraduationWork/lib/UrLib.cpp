#include "UrLib.h"
#include "DrawManager.h"

int Screen::x = 800;
int Screen::y = 600;

int UrLib::Init(int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int WindowMode)
{
    int ret = 0;

    Screen::x = ScreenSizeX;
    Screen::y = ScreenSizeY;
    
    ret += ChangeWindowMode(WindowMode);

    ret += SetGraphMode(Screen::x, Screen::y, ColorBitDepth);

    ret += DxLib_Init();
    
    ret += SetDrawScreen(DX_SCREEN_BACK);	//����ʂ�`��Ώۂ�

    SceneManager::Get()->Start();

    Input::Start();

    Time::Init();

    SetSysCommandOffFlag(TRUE);

    return ret;
}

void UrLib::Update()
{
    int ret = 0;

    while (ret += ProcessMessage(), ret == 0) {
        ret += clsDx();
        Input::Update();                    // ���͍X�V
        Time::Update();                     // �o�ߎ��ԍX�V
        SceneManager::Get()->Update();      // �V�[���̍X�V����
        ret += UrLib::Draw();               // �`�揈��
        ret += ScreenFlip();		        // ����ʂƕ\��ʂ̓���
        ret += ClearDrawScreen();	        // ����ʂ̕`���S�ď���
        if (SceneManager::Get()->IsEnd())ret = -1;//�I���`�F�b�N
    }
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
    Input::End();
    return ret;
}
