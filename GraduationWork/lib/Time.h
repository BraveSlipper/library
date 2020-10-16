#pragma once

class Time
{
private:
	Time()
	{
	}

	~Time()
	{
	}

public:

	static void Init();

	static void Update();

	static float DeltaTime() { return deltaTime; }

	static float UnscaledDeltaTime() { return unscaledDeltaTime; }

private:
	static float deltaTime;

	static float unscaledDeltaTime;

	static float lastTime;

public:
	static float timeScale;

};
