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
	/// 名前を取得
	/// </summary>
	/// <returns>名前の文字列</returns>
	std::string GetName() const;

	/// <summary>
	/// Objectの有効・無効を取得
	/// </summary>
	/// <returns>Objectの有効状態</returns>
	bool IsActive() const;

	/// <summary>
	/// Objectの有効状態をセットする
	/// </summary>
	/// <param name="_active">有効にするならtrue</param>
	void SetActive(bool _active);

	/// <summary>
	/// Objectの破壊フラグを取得
	/// </summary>
	/// <returns>Objectの破壊フラグ</returns>
	bool IsDestroy() const;

	/// <summary>
	/// Objectの破壊フラグを立てる
	/// </summary>
	void Destroy();

	/// <summary>
	/// GameObjectを生成する
	/// </summary>
	/// <typeparam name="C">生成したいGameObjectのクラス</typeparam>
	/// <returns>生成したGameObjectのポインター</returns>
	template<class C>
	inline GameObject* Instantiate();

private:
	std::string name;			// 名前
	bool active;				// 有効状態
	bool isDestroy;				// 破壊フラグ
};

template<class C>
inline GameObject* Object::Instantiate()
{
	return new C();
}
