#pragma once
#include "Collider.h"

class Collider3D : public Collider {
public:
	Collider3D();
	virtual ~Collider3D();

	virtual bool IsCollide(Collider3D* _collider) = 0;

	/// <summary>
	/// 衝突時に呼ばれる関数を全て実行する
	/// </summary>
	/// <param name="_collider">衝突したオブジェクトのコライダー</param>
	void ExecuteAllCollisionEnter(Collider3D* _collider);

	/// <summary>
	/// 衝突中に呼ばれる関数を全て実行する
	/// </summary>
	/// <param name="_collider">衝突中のオブジェクトのコライダー</param>
	void ExecuteAllCollisionStay(Collider3D* _collider);

	/// <summary>
	/// 衝突終了時に呼ばれる関数を全て実行する
	/// </summary>
	/// <param name="_collider">衝突終了したオブジェクトのコライダー</param>
	void ExecuteAllCollisionExit(Collider3D* _collider);
};