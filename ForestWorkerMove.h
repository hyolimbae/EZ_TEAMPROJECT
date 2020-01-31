#pragma once
#include "GgaetIp.h"
#include <time.h>

enum class MOVESET
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	IDLE
};

class ForestWorkerMove : public Script
{
private:
	Transform* _transform;
	Animator* _animator;
	Sprite* _sprite;

	MOVESET _moveSet = MOVESET::MOVE_LEFT;

	int _count;

	int _rand;
	int _timeRand;

	Vector2 _startPoint;

	bool _isChange;

public:
	virtual void Init() override;
	virtual void Update() override;

	void MovePattern();
	void MoveRangeSet();

}; 

