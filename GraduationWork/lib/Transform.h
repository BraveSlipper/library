#pragma once
#include "Component.h"
#include "dxlib/DxLib.h"

class Transform : public Component {
public:
	Transform();
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

	/// <summary>
	/// ワールドにおけるTransformを取得
	/// </summary>
	/// <returns>ワールドトランスフォーム</returns>
	Transform GetWorldTransform();

	VECTOR position;
	VECTOR rotation;
	VECTOR scale;



private:
	/// <summary>
	/// ローカル座標からワールド座標へ変換し、代入する
	/// </summary>
	/// <param name="_parent">親のポインター</param>
	/// <param name="_pos">変換したいローカルポジション</param>
	void SetWorldPosition(GameObject* _parent, VECTOR& _pos);

private:
	VECTOR foward;
	VECTOR right;
};