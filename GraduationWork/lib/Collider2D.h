#pragma once
#include "Collider.h"
#include "typedef.h"
#include <list>

class Collider2D : public Collider {
public:
	Collider2D();
	virtual ~Collider2D();

	virtual bool IsCollide(Collider2D* _collider) = 0;

	/// <summary>
	/// 衝突時に呼ばれる関数を全て実行する
	/// </summary>
	/// <param name="_collider">衝突したオブジェクトのコライダー</param>
	void ExecuteAllCollisionEnter(Collider2D* _collider);

	/// <summary>
	/// 衝突中に呼ばれる関数を全て実行する
	/// </summary>
	/// <param name="_collider">衝突中のオブジェクトのコライダー</param>
	void ExecuteAllCollisionStay(Collider2D* _collider);

	/// <summary>
	/// 衝突終了時に呼ばれる関数を全て実行する
	/// </summary>
	/// <param name="_collider">衝突終了したオブジェクトのコライダー</param>
	void ExecuteAllCollisionExit(Collider2D* _collider);

	/// <summary>
	/// 座標の取得
	/// </summary>
	/// <returns>所有者を原点としたコライダーの座標</returns>
	VECTOR2 GetLocalPosition();

	/// <summary>
	/// ワールド座標上のコライダー座標の取得
	/// </summary>
	/// <returns>ワールド座標上のコライダー座標</returns>
	VECTOR2 GetWorldPosition();

	/// <summary>
	/// コライダーの座標を設定
	/// </summary>
	/// <param name="_pos">所有者を原点とした移動先の座標</param>
	void SetPosition(VECTOR2 _pos);

	/// <summary>
	/// Z軸回転値の取得
	/// </summary>
	/// <returns>回転角度(度)</returns>
	float GetRotate();

	/// <summary>
	/// コライダーを回転
	/// </summary>
	/// <param name="_deg">回転角度</param>
	void Rotate(float _deg);
protected:
	VECTOR2 position;
	float rotation;
};