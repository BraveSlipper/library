#pragma once

#include "Component.h"

class Renderer :public Component
{
public:
	Renderer();
	virtual ~Renderer();

	/// <summary>
	/// •`‰æ
	/// </summary>
	virtual void Draw() = 0;

private:

};
