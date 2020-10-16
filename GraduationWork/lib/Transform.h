#pragma once
#include "Component.h"
#include "dxlib/DxLib.h"
#include "typedef.h"

class Transform : public Component {
public:
	Transform();
	~Transform();

	void Start() override;
	void Update() override;

	/// <summary>
	/// 座標を代入
	/// </summary>
	/// <param name="_pos">代入したい座標</param>
	void SetPosition(VECTOR _pos);

	/// <summary>
	/// 座標を加算する
	/// </summary>
	/// <param name="_add"></param>
	void AddPosition(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
	void AddPosition(VECTOR _add);

	/// <summary>
	/// X軸で回転する
	/// </summary>
	/// <param name="_deg">回転角度</param>
	void AxisRotateX(float _deg);

	/// <summary>
	/// Y軸で回転する
	/// </summary>
	/// <param name="_deg">回転角度</param>
	void AxisRotateY(float _deg);

	/// <summary>
	/// Z軸で回転する
	/// </summary>
	/// <param name="_deg">回転角度</param>
	void AxisRotateZ(float _deg);

	/// <summary>
	/// 任意軸で回転する
	/// </summary>
	/// <param name="_axis">回転軸</param>
	/// <param name="_deg">回転角度</param>
	void Rotate(VECTOR _axis, float _deg);

	/// <summary>
	/// 正面ベクトルを取得
	/// </summary>
	/// <returns>正面ベクトル</returns>
	VECTOR GetForward() const;

	/// <summary>
	/// 右ベクトルを取得
	/// </summary>
	/// <returns>右ベクトル</returns>
	VECTOR GetRight() const;

	/// <summary>
	/// アップベクトルを取得
	/// </summary>
	/// <returns>アップベクトル</returns>
	VECTOR GetUp() const;

	VECTOR position;
	VECTOR scale;

private:
	Quaternion foward;
	Quaternion right;
	Quaternion up;
};