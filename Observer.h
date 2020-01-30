#pragma once
#include "GgaetIp.h"

class Observer abstract 
{
public:
	virtual void OnNotify(MSGTYPE type, string event) = 0;
	//virtual void OnNotify(TIMETYPE type) = 0; //= 0;을 붙이면 순수 가상 
};

