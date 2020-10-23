#pragma once
#include "Collider3D.h"

class SphereCollider;

class BoxCollider : public Collider3D {
public:
	BoxCollider();
	~BoxCollider();

	bool IsCollide(Collider3D* _collider) override;
	float GetHeight() const;
	float GetWidth() const;
	void SetSize(float _hight, float _width);

private:
	float height;
	float width;

private:
	bool IsCollideCircle(SphereCollider* _collider);
	bool IsCollideBox(BoxCollider* _collider);
};
