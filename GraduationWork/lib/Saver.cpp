#include <fstream>
#include "Saver.h"

std::unordered_map<std::string, std::string> Saver::info;

namespace
{
	constexpr int INT_SIZE = sizeof(int);
	static const std::string TAG = "UR_SAVE";
}

void Saver::DeleteAll()
{
	info.clear();
}

void Saver::DeleteKey(const std::string& _key)
{
	info.erase(_key);
}

bool Saver::HasKey(const std::string& _key)
{
	return info.find(_key) != info.end();
}

void Saver::Save()
{
	std::ofstream save("Save\\save.ur",std::ofstream::binary);

	save.write(TAG.c_str(), TAG.size());

	//データ数
	int count = static_cast<int>(info.size());

	save.write(reinterpret_cast<char*>(&count), INT_SIZE);
	
	for (std::unordered_map<std::string,std::string>::iterator it=info.begin(),end=info.end();it!=end;++it)
	{
		//キーの長さ
		int keyLength = static_cast<int>(it->first.size());
		save.write(reinterpret_cast<char*>(&keyLength), INT_SIZE);

		//キー
		save.write(it->first.c_str(), keyLength);

		//データの長さ
		int dataLength = static_cast<int>(it->second.size());
		save.write(reinterpret_cast<char*>(&dataLength), INT_SIZE);

		//データ
		save.write(it->second.c_str(), dataLength);
	}

}

void Saver::SetInt(const std::string& _key, int _data)
{
	info[_key].assign(reinterpret_cast<char*>(&_data), sizeof(int));
}

void Saver::SetFloat(const std::string& _key, float _data)
{
	info[_key].assign(reinterpret_cast<char*>(&_data), sizeof(float));
}

void Saver::SetString(const std::string& _key, const std::string& _data)
{
	info[_key] = _data;
}
