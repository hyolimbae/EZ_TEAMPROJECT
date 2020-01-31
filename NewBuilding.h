#pragma once
#include "Building.h"
class NewBuilding: public Building
{
private:
	bool _fixedPosition = false;


	//나중에 night용 스프라이트 
	Sprite* night;

public:

	bool GetFixedPosition() { return _fixedPosition; }
	void SetFixedPosition(bool fixedPosition) { _fixedPosition = fixedPosition; }
};

