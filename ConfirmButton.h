#pragma once
#include "GgaetIp.h"

class Inventory;

class ConfirmButton: public Script
{
private:
	Inventory* inven;
	Object* window;
public:
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

	void SetLinkToInventory(Inventory* inven) { this->inven = inven; }
	void SetLinkToWindow(Object* obj) { this->window = obj; }
};

