#pragma once

class Anim2D {
public:
	Anim2D(unsigned int _start, unsigned int _end, float _speed, bool _isLoop) : start(_start), end(_end), speed(_speed), isLoop(_isLoop) {}
	~Anim2D() {}

private:
	unsigned int start, end;
	float speed;
	bool isLoop;
};