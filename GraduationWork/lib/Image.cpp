#include "Image.h"
#include "dxlib/DxLib.h"

std::unordered_map<std::string, Image::INFO> Image::loadInfo;

bool Image::Load(const std::string& _path)
{
	if (path == _path)return true;//�p�X�������ꍇ���I��

	//�}�b�v���猟��

	INFO* p = nullptr;

	std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(_path);
	if (it == loadInfo.end())
	{
		//���o�^���A�ǂݍ���ł���o�^
		int h = LoadGraph(_path.c_str());

		if (h == -1)return false;//���s������I��

		p = &loadInfo[_path];//�o�^����INFO�̃A�h���X��ێ�

		p->handles.emplace_back(h);
		GetGraphSize(h, &p->sizeX, &p->sizeY);
	}
	else
	{
		//�o�^�ς݂̏ꍇ�A�J�E���g�𑝂₵�ăA�h���X��ێ�
		it->second.count += 1;
		p = &it->second;
	}

	Destroy();//���̉摜��j��

	imageInfo = p;
	path = _path;

	return true;
}

bool Image::LoadDiv(const std::string& _path, unsigned _xdiv, unsigned _ydiv, unsigned _allnum)
{
	if (path == _path)return true;//�p�X�������ꍇ���I��

	//�}�b�v���猟��

	INFO* p = nullptr;

	std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(_path);
	if (it == loadInfo.end())
	{
		//���o�^���A�ǂݍ���ł���o�^
		int x, y;
		GetImageSize_File(_path.c_str(), &x, &y);//�t�@�C������摜�T�C�Y�擾

		if (_allnum == 0u)_allnum = _xdiv * _ydiv;

		INFO info;
		info.sizeX = x / _xdiv;
		info.sizeY = y / _ydiv;
		info.handles.resize(_allnum);

		int result = LoadDivGraph(_path.c_str(), _allnum, _xdiv, _ydiv, info.sizeX, info.sizeY, &info.handles[0]);

		if (result == -1)return false;//���s������I��

		p = &loadInfo[_path];//�o�^����INFO�̃A�h���X��ێ�
		*p = info;
	}
	else
	{
		//�o�^�ς݂̏ꍇ�A�J�E���g�𑝂₵�ăA�h���X��ێ�
		it->second.count += 1;
		p = &it->second;
	}

	Destroy();//���̉摜��j��

	path = _path;
	imageInfo = p;

	return true;
}

void Image::Destroy()
{
	if (imageInfo == nullptr)return;//�ǂݍ���ł��Ȃ�

	//�ǂݍ��񂾐���0�ȉ��ō폜
	if (--imageInfo->count <= 0)
	{
		//�ǂݍ��񂾉摜�폜
		for (size_t i = 0ull, size = imageInfo->handles.size(); i < size; ++i)
		{
			DeleteGraph(imageInfo->handles[i]);
		}

		//�}�b�v�������
		std::unordered_map<std::string, INFO>::iterator it = loadInfo.find(path);
		if (it != loadInfo.end())
		{
			loadInfo.erase(it);
		}
	}

}
