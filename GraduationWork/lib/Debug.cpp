#include "Debug.h"
#include <stdio.h>
#include <consoleapi.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>

namespace
{
#if _DEBUG || DEBUG

	bool isOutFlag = false;

#endif // _DEBUG || DEBUG

}

namespace
{
#if DEBUG || _DEBUG
	
	int console = -1;

	void CreateConsoleWindow()
	{
		if (console == -1)
		{
			//コンソールウィンドウ作成
			if (!AllocConsole())return;

			//作成したコンソールウィンドウをCと関連付ける
			console = _open_osfhandle(reinterpret_cast<intptr_t>(GetStdHandle(STD_OUTPUT_HANDLE)), _O_TEXT);

			//コンソールウィンドウの文字出力作成し、標準出力関数に上書き
			*stdout = *_fdopen(console, "w");

			//バッファ設定
			setvbuf(stdout, nullptr, _IONBF, 0);
		}
	}

	void ReleaseConsoleWindow()
	{
		if (console != -1)
			_close(console);
		console = -1;
	}

#endif // DEBUG || _DEBUG
}

namespace
{
#if _DEBUG || DEBUG

	bool CheckCreateWindow(bool _onlyFlag)
	{
		if ((isOutFlag) || (_onlyFlag == false))
		{
			CreateConsoleWindow();
			return true;
		}
		return false;
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(int _outdata, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		printf("%d", _outdata);
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(float _outdata, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		printf("%f", _outdata);
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(bool _outdata, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		if (_outdata)
			printf("%s", "true");
		else
			printf("%s", "false");
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(const std::string& _outdata, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		printf("%s", _outdata.c_str());
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(const std::string& _str, int _data, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		printf("%s%d", _str.c_str(), _data);
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(const std::string& _str, float _data, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		printf("%s%f", _str.c_str(), _data);
	}

#endif // _DEBUG || DEBUG
}

void Debug::Write(const std::string& _str, bool _data, bool _isConsoleCreatedOnly)
{
#if _DEBUG || DEBUG

	if (CheckCreateWindow(_isConsoleCreatedOnly))
	{
		if (_data)
			printf("%s%s", _str.c_str(), "true");
		else
			printf("%s%s", _str.c_str(), "false");
	}

#endif // _DEBUG || DEBUG
}

void Debug::OutFlag(bool _flag)
{
#if _DEBUG || DEBUG

	isOutFlag = _flag;

	if (isOutFlag)
	{
		CreateConsoleWindow();
	}

#endif // _DEBUG || DEBUG
}

void Debug::Release()
{
#if DEBUG || _DEBUG

	ReleaseConsoleWindow();

#endif // DEBUG || _DEBUG
}

std::string Debug::OutString(int _line, const char* _file, const char* _datastr)
{
	std::string out = "ファイル名：";
	return out.append(_file).append("\n").
		append("行番号：").append(std::to_string(_line)).append("\n").
		append(_datastr).append("：");
}
