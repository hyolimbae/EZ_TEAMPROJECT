#pragma once
#include "Component.h"

class Script : public Component
{
public:
	virtual void OnMouseDown() {};
	
	virtual void OnMouse() {};

	virtual void OnMouseStay() {};

	virtual void OnMouseUp() {};

	virtual void OnMouseExit() {};

	virtual void OnCollisionEnter(Object* obj) {};
	virtual void OnCollisionExit(Object* obj) {};
	virtual void OnCollisionStay(Object* obj) {};
};

