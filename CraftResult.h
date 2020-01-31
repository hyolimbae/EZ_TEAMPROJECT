#pragma once
#include "GgaetIp.h"

class CraftTimeBar;
class CraftResult : public Script
{
private:
	CraftTimeBar* _timeBar;

public:
	virtual void Init();
	//virtual void Update();
	virtual void OnMouseDown();

	void Setlink(CraftTimeBar* c) { _timeBar = c; }
};