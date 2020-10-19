#pragma once

#include <unordered_map>
#include <vector>

class Image
{
	struct INFO
	{
		INFO() : count(1) {}
		std::vector<int> handles;//�摜�n���h��
		int count;
		int sizeX, sizeY;//�摜�c���T�C�Y
	};

public:
	Image() :
		imageInfo(nullptr)
	{
	}

	~Image()
	{
		Destroy();
	}

	/// <summary>
	/// �摜�ǂݍ���
	/// </summary>
	/// <param name="_path">�t�@�C���p�X</param>
	/// <returns>true�F�ǂݍ��ݐ����Afalse�F���s</returns>
	bool Load(const std::string& _path);

	/// <summary>
	/// �����摜�ǂݍ���
	/// </summary>
	/// <param name="_path">�t�@�C���p�X</param>
	/// <param name="_xdiv">��������</param>
	/// <param name="_ydiv">�c������</param>
	/// <param name="_allnum">�S�̕������A0��_xdiv*_ydiv</param>
	/// <returns>true�F�ǂݍ��ݐ����Afalse�F���s</returns>
	bool LoadDiv(const std::string& _path, unsigned _xdiv, unsigned _ydiv, unsigned _allnum = 0u);

private:
	void Destroy();

public:
	INFO* imageInfo;
	std::string path;//�t�@�C���p�X

private:
	static std::unordered_map<std::string, INFO> loadInfo;//�t�@�C���p�X�ƎQ�Ɛ����֘A�t����

};
