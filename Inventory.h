#pragma once
#include "GgaetIp.h"
class Inventory : public Script
{
private:
	map<string, int> items;
public:
	void AddItem(string itemName, int count) { items[itemName] += count; }
	int GetItemCount(string itemName) { return items[itemName]; }
};

