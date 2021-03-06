#pragma once
#include "GgaetIp.h"

/*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        class Inventory;

class FixButton : public Script
{
private:
    Object* _building;
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        Inventory* _inventory;

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        map<string, int> _neededResources;

public:
    virtual void OnMouseDown();
    void SetLink(Object* ob) { _building = ob; }

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/           void SetInventoryLink(Inventory* i) { _inventory = i; }

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/           map<string, int> GetMNeededResources() { return _neededResources; }

};