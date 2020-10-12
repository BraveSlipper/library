#pragma once
#include <string>

class GameObject;

class Scene;

class Object {
	friend Scene;
public:
	Object();
	~Object();

	virtual void Start();
	virtual void Update();

	/// <summary>
	/// 名前を取得
	/// </summary>
	/// <returns>名前の文字列</returns>
	std::string GetTypeName() const;

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

private:
	std::string className;		// 名前
	bool active;				// 有効状態
	bool isDestroy;				// 破壊フラグ
};
