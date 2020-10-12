#pragma once

#include "Scene.h"

class SceneManager
{
private:
	/// <summary>
	/// �V�[������
	/// </summary>
	/// <typeparam name="C">�V�[���^</typeparam>
	/// <param name="_name">�V�[����</param>
	/// <returns>���������V�[���̃A�h���X</returns>
	template<class C>
	static Scene* CreateScene() { return new C; }

public:
	/// <summary>
	/// �C���X�^���X�擾
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static SceneManager* Get();

private:
	SceneManager():
		mainScene(nullptr), createScene(nullptr)
	{
	}

	~SceneManager()
	{
		if (mainScene != nullptr)
		{
			delete mainScene;
			mainScene = nullptr;
		}
	}

public:
	/// <summary>
	/// �C���X�^���X�j��
	/// </summary>
	/// <returns>true�F�j���Afalse�F��������Ă��Ȃ�</returns>
	bool Destroy();

	/// <summary>
	/// ������
	/// </summary>
	void Start();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �V�[���؂�ւ�
	/// </summary>
	/// <typeparam name="C">�؂�ւ���V�[��</typeparam>
	template<class C>
	void LoadScene()
	{
		sceneName = typeid(C).name;
		createScene = CreateScene<Scene>;
	}

	/// <summary>
	/// ���C���V�[���ɃT�u�V�[����ǉ�
	/// </summary>
	/// <typeparam name="C">�ǉ�����T�u�V�[��</typeparam>
	/// <returns>true�F�����Afalse�F���C���V�[������������Ă��Ȃ�</returns>
	template<class C>
	bool AddSubScene()
	{
		if (mainScene == nullptr)return false;

		return mainScene->AddSubScene<C>();
	}

	/// <summary>
	/// ���C���V�[������T�u�V�[����j��
	/// </summary>
	/// <typeparam name="C">�j������T�u�V�[��</typeparam>
	/// <returns>true�F�T�u�V�[���̔j���Afalse�F���C���V�[������������Ă��Ȃ�</returns>
	template<class C>
	bool DestroySubScene()const
	{
		if (mainScene == nullptr)return false;

		return mainScene->DestroySubScene<C>();
	}

	/// <summary>
	/// ���C���V�[���擾
	/// </summary>
	/// <typeparam name="C">���C���V�[���̌^</typeparam>
	/// <returns>���C���V�[���擾</returns>
	template<class C>
	C* GetMainScene()const { return dynamic_cast<C*>(mainScene); }

	/// <summary>
	/// ���݂̃V�[�����擾
	/// </summary>
	/// <returns>���݂̃V�[��</returns>
	Scene* GetCurrentScene();

private:
	/// <summary>
	/// �V�[���؂�ւ�
	/// </summary>
	void ChangeScene();

private:
	Scene* mainScene;//���C���V�[��

	Scene* (*createScene)();//���C���V�[���؂�ւ��֐�

	std::string sceneName;//���C���V�[����

	static SceneManager* instance;//SceneManager�̃C���X�^���X

};
