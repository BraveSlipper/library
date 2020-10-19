#include "Animator2D.h"
#include "ImageRenderer.h"

Animator2D::Animator2D() :
	currentAnim(nullptr)
{
	imageRenderer = GetComponent<ImageRenderer>();
	if (imageRenderer == nullptr) {
		imageRenderer = AddComponent<ImageRenderer>();
	}

	animList.clear();
}

Animator2D::~Animator2D()
{
}

void Animator2D::Start()
{
}

void Animator2D::Update()
{

}
