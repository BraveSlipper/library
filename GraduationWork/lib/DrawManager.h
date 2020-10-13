#pragma once

#include <list>

class Renderer;

class DrawManager
{
public:
	DrawManager() {}
	~DrawManager();

	/// <summary>
	/// インスタンス取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static DrawManager* Get();

	/// <summary>
	/// インスタンス破棄
	/// </summary>
	/// <returns>true：破棄、false：生成されていない</returns>
	bool Destroy();

	/// <summary>
	/// 登録された描画オブジェクトの描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 描画オブジェクト追加
	/// </summary>
	/// <param name="_p">追加する描画オブジェクト</param>
	void Add(Renderer* _p);

	/// <summary>
	/// 描画オブジェクト破棄
	/// </summary>
	/// <param name="_p">破棄する描画オブジェクト</param>
	/// <returns>true：破棄、false：存在しない</returns>
	bool Erase(Renderer* _p);

private:
	std::list<Renderer*> rendererList;//描画リスト
	static DrawManager* instance;
};
