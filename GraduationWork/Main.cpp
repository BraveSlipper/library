#include "lib/UrLib.h"
#include "TitleScene.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する

	if (UrLib::Init() < 0)		// URライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SceneManager::Get()->LoadScene<TitleScene>();

	//メイン処理
	UrLib::Update();

	UrLib::End();			// URライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
