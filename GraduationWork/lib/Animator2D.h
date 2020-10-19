#pragma once
#include "Component.h"
#include "Anim2D.h"
#include <list>

class ImageRenderer;

class Animator2D : public Component {
public:
	Animator2D();
	~Animator2D();
	void Start();
	void Update() final;

private:
	ImageRenderer* imageRenderer;
	std::list<Anim2D*> animList;
	Anim2D* currentAnim;
};