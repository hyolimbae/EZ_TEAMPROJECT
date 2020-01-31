#include "stdafx.h"
#include "ForestWorkerMove.h"

void ForestWorkerMove::Init()
{
	_transform = object->GetTransform();
	_animator = object->GetComponent<Animator>();
	_sprite = object->GetComponent<Sprite>();
	_count = TimeManager::GetInstance()->GetTime();
	_moveSet = MOVESET::IDLE;
	
	//Tag가 무엇인지 불러와서 위치 세팅
	/*if (object->GetTag() == "Miner")
	{
		_transform->SetPosition(Vector2(0, 0));
	}*/
	 
	
	_startPoint = _transform->GetPosition();

	_rand = rand() % 5;
	_timeRand = rand() % 4;
	srand(time(NULL));

	
}

void ForestWorkerMove::Update()
{

	//1초마다 MoveSet Random Setting
	if (TimeManager::GetInstance()->GetTime() - _count > 2)
	{
		_rand = rand() % 5;
		_moveSet = (MOVESET)_rand;
		if (_moveSet == MOVESET::IDLE)
			_count = TimeManager::GetInstance()->GetTime() + 3;
		else if (_moveSet != MOVESET::IDLE)
			_count = TimeManager::GetInstance()->GetTime();
	}

	MovePattern();
	MoveRangeSet();
}

void ForestWorkerMove::MovePattern()
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

void ForestWorkerMove::MoveRangeSet()
{
	Vector2 temp = _startPoint - object->GetTransform()->GetPosition();
	float distance = temp.Magnitude();

	if (distance >= 50 && !_isChange)
	{
		//특정한 범위안에서만 움직인다.
		//가끔 범위밖에서 춤추는 현상이 있어서 별도의 _rCount 할당.
		if (_moveSet == MOVESET::MOVE_LEFT)			_moveSet = MOVESET::MOVE_RIGHT;
		else if (_moveSet == MOVESET::MOVE_RIGHT)	_moveSet = MOVESET::MOVE_LEFT;
		else if (_moveSet == MOVESET::MOVE_UP)		_moveSet = MOVESET::MOVE_DOWN;
		else if (_moveSet == MOVESET::MOVE_DOWN)	_moveSet = MOVESET::MOVE_UP;

		_isChange = true;

	}
	else if (distance < 50 && _isChange) _isChange = false;

}
