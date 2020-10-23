#pragma once
#include "Collider.h"
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
private:
};