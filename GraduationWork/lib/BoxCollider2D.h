#pragma once
#include "Collider2D.h"

class CircleCollider2D;

class BoxCollider2D : public Collider2D {
public:
	BoxCollider2D();
	~BoxCollider2D();

	void Disp();
	bool IsCollide(Collider2D* _collider) override;
	float GetHeight() const;
	float GetWidth() const;
	void SetSize(float _hight, float _width);

private:
	float height;
	float width;

private:
	bool IsCollideCircle(CircleCollider2D* _collider);
	bool IsCollideBox(BoxCollider2D* _collider);
};
