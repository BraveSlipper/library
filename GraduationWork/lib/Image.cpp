#include "Image.h"
#include "dxlib/DxLib.h"

std::unordered_map<std::string, Image::INFO> Image::loadInfo;

bool Image::Load(const std::string& _path)
{
	if (path == _path)return true;

	int h = -1;

	std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(_path);
	if (it == loadInfo.end())
	{
		h = LoadGraph(_path.c_str());

		if (h == -1)return false;

		INFO info(h);
		loadInfo.insert(std::make_pair(_path, h));
	}
	else
	{
		it->second.count += 1;
		h = it->second.handle;
	}

	Destroy();

	path = _path;
	handle = h;

	GetGraphSize(handle, &sizeX, &sizeY);

	return true;
}

void Image::Destroy()
{
	if (handle == -1)return;

	std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(path);
	if (it != loadInfo.end())
	{
		it->second.count -= 1;
		if (it->second.count <= 0)
		{
			DeleteGraph(it->second.handle);
			loadInfo.erase(it);
		}
	}
	handle = -1;
}
