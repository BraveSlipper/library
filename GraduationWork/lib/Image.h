#pragma once

#include <unordered_map>

class Image
{
	struct INFO
	{
		INFO(int _handle) :handle(_handle), count(1) {}
		int handle;
		int count;
	};

public:
	Image() :
		handle(-1), sizeX(0), sizeY(0)
	{
	}

	~Image()
	{
		Destroy();
	}

	/// <summary>
	/// 画像読み込み
	/// </summary>
	/// <param name="_path">ファイルパス</param>
	/// <returns>true：読み込み成功、false：失敗</returns>
	bool Load(const std::string& _path);

private:
	void Destroy();

public:
	int handle;//画像ハンドル
	int sizeX, sizeY;//画像縦横サイズ
	std::string path;//ファイルパス

private:
	static std::unordered_map<std::string, INFO> loadInfo;//ファイルパスと参照数を関連付ける

};
