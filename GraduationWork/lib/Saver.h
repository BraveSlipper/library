#pragma once

#include <unordered_map>

class Saver
{
private:
	Saver()
	{
	}

	~Saver()
	{
	}

public:
	static void DeleteAll();

	static void DeleteKey(const std::string& _key);

	static bool HasKey(const std::string& _key);

	static void Save();

	static void SetInt(const std::string& _key, int _data);

	static void SetFloat(const std::string& _key, float _data);

	static void SetString(const std::string& _key, const std::string& _data);

private:
	static std::unordered_map<std::string, std::string> info;

};
