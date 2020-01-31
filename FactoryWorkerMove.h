#pragma once
#include "GgaetIp.h"

enum class MOVESET
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	IDLE
};

class FactoryWorkerMove : public Script
{
private:
	Transform* _transform;
	Animator* _animator;
	Sprite* _sprite;

	MOVESET _moveSet = MOVESET::IDLE;

public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void MovePattern();
};

