#pragma once
#include "GgaetIp.h"
class CitizenTalk: public Script
{
private:
	Object* citizen;
	Object* talk;
	float stopTime = 0;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void OnMouseDown() override;
	void SetLinkToCitizen(Object* citizen) { this->citizen = citizen; }
};

