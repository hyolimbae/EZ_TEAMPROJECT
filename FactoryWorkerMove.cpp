#include "stdafx.h"
#include "FactoryWorkerMove.h"

void FactoryWorkerMove::Init()
{
	_transform = object->GetTransform();
	_animator = object->GetComponent<Animator>();
	_sprite = object->GetComponent<Sprite>();
}

void FactoryWorkerMove::Update()
{
	MovePattern();
}

void FactoryWorkerMove::MovePattern()
{
	int moveDirection = 0;

	if (_moveSet == MOVESET::MOVE_LEFT)
	{
		_sprite->SetFlip(false);
		_transform->Translate(Vector2(-2, 0));
		moveDirection = 0;
	}
	else if (_moveSet == MOVESET::MOVE_RIGHT)
	{
		_sprite->SetFlip(true);
		_transform->Translate(Vector2(2, 0));
		moveDirection = 0;
	}
	else if (_moveSet == MOVESET::MOVE_UP)
	{
		_transform->Translate(Vector2(0, -2));
		moveDirection -= 1;
	}
	else if (_moveSet == MOVESET::MOVE_DOWN)
	{
		_transform->Translate(Vector2(0, 2));
		moveDirection += 1;
	}
	else if (_moveSet == MOVESET::IDLE)
	{
		moveDirection += 3;
	}

	_animator->SetParameter("Move", moveDirection);
}
