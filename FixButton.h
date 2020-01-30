#pragma once
#include "GgaetIp.h"

class FixButton : public Script
{
private:
	Object* _building;

public:
	virtual void OnMouseDown();
	void SetLink(Object* ob) { _building = ob; }
};