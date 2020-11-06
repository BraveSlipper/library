#pragma once

#include <unordered_map>
#include <string>

class Loader
{
private:
	Loader()
	{
	}

	~Loader()
	{
	}

public:
	static void DeleteAll();

	static void DeleteKey(const std::string& _key);

	static bool HasKey(const std::string& _key);

	static void Load();

	static int GetInt(const std::string& _key);

	static float GetFloat(const std::string& _key);

	static std::string GetString(const std::string& _key);

private:
	static std::unordered_map<std::string, std::string> info;

};
