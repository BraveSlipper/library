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
    
    ret += SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ

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
        Input::Update();                    // 入力更新
        Time::Update();                     // 経過時間更新
        SceneManager::Get()->Update();      // シーンの更新処理
        ret += UrLib::Draw();               // 描画処理
        ret += ScreenFlip();		        // 裏画面と表画面の入替
        ret += ClearDrawScreen();	        // 裏画面の描画を全て消去
        if (SceneManager::Get()->IsEnd())ret = -1;//終了チェック
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
