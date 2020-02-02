#pragma once
#include "GgaetIp.h"

/*�����������������*/        class Inventory;

class FixButton : public Script
{
private:
    Object* _building;
    /*�����������������*/        Inventory* _inventory;

    /*�����������������*/        map<string, int> _neededResources;

public:
    virtual void OnMouseDown();
    void SetLink(Object* ob) { _building = ob; }

    /*�����������������*/           void SetInventoryLink(Inventory* i) { _inventory = i; }

    /*�����������������*/           map<string, int> GetMNeededResources() { return _neededResources; }

};