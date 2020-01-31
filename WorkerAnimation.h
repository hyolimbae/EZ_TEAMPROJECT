#pragma once
#include "GgaetIp.h"
#include <time.h>

class WorkerAnimation : public Script
{
private:
	int _rand;
	Sprite* _sprite;
public:

	virtual void Init();
	virtual void Update();
};

