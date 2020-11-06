#include <fstream>
#include "Loader.h"

std::unordered_map<std::string, std::string> Loader::info;

namespace
{
	constexpr int INT_SIZE = sizeof(int);
	static const std::string check = "UR_SAVE";
}

void Loader::DeleteAll()
{
	info.clear();
}

void Loader::DeleteKey(const std::string& _key)
{
	info.erase(_key);
}

bool Loader::HasKey(const std::string& _key)
{
	return info.find(_key) != info.end();
}

void Loader::Load()
{
	std::string data;

	std::ifstream load("Save\\save.ur", std::ifstream::binary);

	if (load.is_open())
	{
		//�t�@�C���T�C�Y
		load.seekg(0, std::ifstream::end);

		int size = static_cast<int>(load.tellg());

		if (size < check.size())return;

		load.seekg(0, std::ifstream::beg);

		//�ǂݍ���
		std::vector<char> buf;
		buf.resize(size);

		load.read(&buf[0], size);

		load.close();

		//�f�[�^��
		size = static_cast<int>(check.size());

		int count = *reinterpret_cast<int*>(&buf[size]);

		size += INT_SIZE;

		//�f�[�^�擾
		for (int i = 0; i < count; ++i)
		{
			//�L�[�̒���
			int keyLength = *reinterpret_cast<int*>(&buf[size]);
			size += INT_SIZE;

			//�L�[
			std::string key;
			key.assign(&buf[size], keyLength);
			size += keyLength;

			//�f�[�^����
			int dataLength = *reinterpret_cast<int*>(&buf[size]);
			size += INT_SIZE;

			//�f�[�^
			info[key].assign(&buf[size], dataLength);
			size += dataLength;
		}
	}
}

int Loader::GetInt(const std::string& _key)
{
	std::unordered_map<std::string, std::string>::iterator it = info.find(_key);
	if (it == info.end())
		return 0;
	return *reinterpret_cast<int*>(&it->second[0]);
}

float Loader::GetFloat(const std::string& _key)
{
	int data = GetInt(_key);
	return *reinterpret_cast<float*>(&data);
}

std::string Loader::GetString(const std::string& _key)
{
	std::unordered_map<std::string, std::string>::iterator it = info.find(_key);
	if (it == info.end())
		return "";
	return it->second;
}
