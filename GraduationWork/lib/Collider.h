#pragma once
#include "Component.h"

class Collider : public Component {
public:
	Collider();
	~Collider();
private:
	bool isTrriger;
};