#pragma once
#include "Component.h"
#include "dxlib/DxLib.h"

class Transform : public Component {
public:
	Transform(GameObject* _actor);
	~Transform();

	void Start() override;
	void Update() override;

	/// <summary>
	/// 正面ベクトルを取得
	/// </summary>
	/// <returns>正面ベクトル</returns>
	VECTOR GetForward() const;

	/// <summary>
	/// アップベクトルを取得
	/// </summary>
	/// <returns>アップベクトル</returns>
	VECTOR GetUp() const;

	VECTOR position;
	VECTOR rotation;
	VECTOR scale;
	
private:
	VECTOR forward;
	VECTOR up;
};