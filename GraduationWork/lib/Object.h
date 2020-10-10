#pragma once
#include <string>

class GameObject;

class Object {
public:
	Object();
	Object(std::string _name);
	~Object();

	virtual void Start();
	virtual void Update();

	/// <summary>
	/// ���O���擾
	/// </summary>
	/// <returns>���O�̕�����</returns>
	std::string GetName() const;

	/// <summary>
	/// Object�̗L���E�������擾
	/// </summary>
	/// <returns>Object�̗L�����</returns>
	bool IsActive() const;

	/// <summary>
	/// Object�̗L����Ԃ��Z�b�g����
	/// </summary>
	/// <param name="_active">�L���ɂ���Ȃ�true</param>
	void SetActive(bool _active);

	/// <summary>
	/// Object�̔j��t���O���擾
	/// </summary>
	/// <returns>Object�̔j��t���O</returns>
	bool IsDestroy() const;

	/// <summary>
	/// Object�̔j��t���O�𗧂Ă�
	/// </summary>
	void Destroy();

	/// <summary>
	/// GameObject�𐶐�����
	/// </summary>
	/// <typeparam name="C">����������GameObject�̃N���X</typeparam>
	/// <returns>��������GameObject�̃|�C���^�[</returns>
	template<class C>
	inline GameObject* Instantiate();

private:
	std::string name;			// ���O
	bool active;				// �L�����
	bool isDestroy;				// �j��t���O
};

template<class C>
inline GameObject* Object::Instantiate()
{
	return new C();
}
