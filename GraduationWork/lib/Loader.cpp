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
		//ファイルサイズ
		load.seekg(0, std::ifstream::end);

		int size = static_cast<int>(load.tellg());

		if (size < check.size())return;

		load.seekg(0, std::ifstream::beg);

		//読み込み
		std::vector<char> buf;
		buf.resize(size);

		load.read(&buf[0], size);

		load.close();

		//データ数
		size = static_cast<int>(check.size());

		int count = *reinterpret_cast<int*>(&buf[size]);

		size += INT_SIZE;

		//データ取得
		for (int i = 0; i < count; ++i)
		{
			//キーの長さ
			int keyLength = *reinterpret_cast<int*>(&buf[size]);
			size += INT_SIZE;

			//キー
			std::string key;
			key.assign(&buf[size], keyLength);
			size += keyLength;

			//データ長さ
			int dataLength = *reinterpret_cast<int*>(&buf[size]);
			size += INT_SIZE;

			//データ
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
