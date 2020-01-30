#pragma once
#include "GgaetIp.h"
class Test: public Script
{
private:
	bool isFixedPosition = false;

public:
	bool GetIsFixedPosition() { return isFixedPosition; }
	void SetIsFixedPosition(bool isFixedPosition) { this->isFixedPosition = isFixedPosition; }
};

