#pragma once
#include <map>

using namespace std;

enum class KeyState
{
	None,
	Down,
	Stay,
	Up
};

class InputManager
{
private:
	map<int, KeyState> keyStates;
	Vector2 mousePosition;
public:
	static InputManager* GetInstance();

	void SetMousePosition(Vector2 mousePosition);

	bool GetKey(int key);
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

	void Update();

	Vector2 GetMouseWorldPosition();
	Vector2 GetMousePosition();
};

