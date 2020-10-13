#pragma once
#include "typedef.h"
#include "Renderer.h"
#include "Image.h"
#include <string>

class ImageRenderer : public Renderer {
public:
	ImageRenderer();
	~ImageRenderer();
	void Draw();

	/// <summary>
	/// �摜��ǂݍ���
	/// </summary>
	/// <param name="_filePass">�Ǎ��݂����摜�t�@�C���̃p�X</param>
	/// <returns>�ǂݍ��ݐ�����true, �t�@�C����������Ȃ������ɓ������̂�ǂݍ���ł�����false</returns>
	bool SetImage(const std::string& _filePass);

	VECTOR2 position;
	float rotate;
	VECTOR2 scale;
	float alpha;
	int transFlag;
	int turnFlag;
	int order;

private:
	Image image;
};