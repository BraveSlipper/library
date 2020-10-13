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
	/// �摜�ǂݍ���
	/// </summary>
	/// <param name="_path">�t�@�C���p�X</param>
	/// <returns>true�F�ǂݍ��ݐ����Afalse�F���s</returns>
	bool Load(const std::string& _path);

private:
	void Destroy();

public:
	int handle;//�摜�n���h��
	int sizeX, sizeY;//�摜�c���T�C�Y
	std::string path;//�t�@�C���p�X

private:
	static std::unordered_map<std::string, INFO> loadInfo;//�t�@�C���p�X�ƎQ�Ɛ����֘A�t����

};
