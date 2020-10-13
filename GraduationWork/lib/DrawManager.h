#pragma once

#include <list>

class Renderer;

class DrawManager
{
public:
	DrawManager() {}
	~DrawManager();

	/// <summary>
	/// �C���X�^���X�擾
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static DrawManager* Get();

	/// <summary>
	/// �C���X�^���X�j��
	/// </summary>
	/// <returns>true�F�j���Afalse�F��������Ă��Ȃ�</returns>
	bool Destroy();

	/// <summary>
	/// �o�^���ꂽ�`��I�u�W�F�N�g�̕`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �`��I�u�W�F�N�g�ǉ�
	/// </summary>
	/// <param name="_p">�ǉ�����`��I�u�W�F�N�g</param>
	void Add(Renderer* _p);

	/// <summary>
	/// �`��I�u�W�F�N�g�j��
	/// </summary>
	/// <param name="_p">�j������`��I�u�W�F�N�g</param>
	/// <returns>true�F�j���Afalse�F���݂��Ȃ�</returns>
	bool Erase(Renderer* _p);

private:
	std::list<Renderer*> rendererList;//�`�惊�X�g
	static DrawManager* instance;
};
