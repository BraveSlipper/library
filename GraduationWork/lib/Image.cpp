#include "Image.h"
#include "dxlib/DxLib.h"

std::unordered_map<std::string, Image::INFO> Image::loadInfo;

bool Image::Load(const std::string& _path)
{
	if (path == _path)return true;//パスが同じ場合即終了

	//マップから検索

	INFO* p = nullptr;

	std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(_path);
	if (it == loadInfo.end())
	{
		//未登録時、読み込んでから登録
		int h = LoadGraph(_path.c_str());

		if (h == -1)return false;//失敗したら終了

		p = &loadInfo[_path];//登録したINFOのアドレスを保持

		p->handles.emplace_back(h);
		GetGraphSize(h, &p->sizeX, &p->sizeY);
	}
	else
	{
		//登録済みの場合、カウントを増やしてアドレスを保持
		it->second.count += 1;
		p = &it->second;
	}

	Destroy();//元の画像を破棄

	imageInfo = p;
	path = _path;

	return true;
}

bool Image::LoadDiv(const std::string& _path, unsigned _xdiv, unsigned _ydiv, unsigned _allnum)
{
	if (path == _path)return true;//パスが同じ場合即終了

	//マップから検索

	INFO* p = nullptr;

	std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(_path);
	if (it == loadInfo.end())
	{
		//未登録時、読み込んでから登録
		int x, y;
		GetImageSize_File(_path.c_str(), &x, &y);//ファイルから画像サイズ取得

		if (_allnum == 0u)_allnum = _xdiv * _ydiv;

		INFO info;
		info.sizeX = x / _xdiv;
		info.sizeY = y / _ydiv;
		info.handles.resize(_allnum);

		int result = LoadDivGraph(_path.c_str(), _allnum, _xdiv, _ydiv, info.sizeX, info.sizeY, &info.handles[0]);

		if (result == -1)return false;//失敗したら終了

		p = &loadInfo[_path];//登録したINFOのアドレスを保持
		*p = info;
	}
	else
	{
		//登録済みの場合、カウントを増やしてアドレスを保持
		it->second.count += 1;
		p = &it->second;
	}

	Destroy();//元の画像を破棄

	path = _path;
	imageInfo = p;

	return true;
}

void Image::Destroy()
{
	if (imageInfo == nullptr)return;//読み込んでいない

	//読み込んだ数が0以下で削除
	if (--imageInfo->count <= 0)
	{
		//読み込んだ画像削除
		for (size_t i = 0ull, size = imageInfo->handles.size(); i < size; ++i)
		{
			DeleteGraph(imageInfo->handles[i]);
		}

		//マップから消す
		std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(path);
		if (it != loadInfo.end())
		{
			loadInfo.erase(it);
		}
	}

}
