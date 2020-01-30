#pragma once
#include "Building.h"
class NewBuilding: public Building
{
private:

	bool _fixedPosition = false;

public:

	bool GetFixedPosition() { return _fixedPosition; }
	void SetFixedPosition(bool fixedPosition) { _fixedPosition = fixedPosition; }
};

