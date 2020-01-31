#pragma once
#include "GgaetIp.h"

class CraftTimeBar;

class CraftButton :	public Script
{
private:
	Object* _workArea;
	CraftTimeBar* _timeBar;

public:
	virtual void Init();
	virtual void Update();
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

	virtual void SetLink(Object* b) { _workArea = b; }
};