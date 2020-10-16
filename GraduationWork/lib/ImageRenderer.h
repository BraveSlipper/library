#pragma once
#include "typedef.h"
#include "Renderer.h"
#include "Image.h"
#include <string>

class ImageRenderer : public Renderer {
public:
	ImageRenderer();
	~ImageRenderer();
	void Draw();

	/// <summary>
	/// 画像を読み込む
	/// </summary>
	/// <param name="_filePass">読込みたい画像ファイルのパス</param>
	/// <returns>読み込み成功でtrue, ファイルが見つからないか既に同じものを読み込んでいたらfalse</returns>
	bool SetImage(const std::string& _filePass);

	/// <summary>
	/// 画像ハンドル取得
	/// </summary>
	/// <returns>画像ハンドル</returns>
	int GetHandle()const { return image.handle; }

	VECTOR2 position;
	float rotation;
	VECTOR2 scale;
	float alpha;
	int transFlag;
	int turnFlag;
	int order;

private:
	Image image;
};