#pragma once
#include "Script.h"
#include "Observer.h"

//����ð� RealTime 3�п�(180��) 2����
#define PRODUCTIONTIME 5

class ResourceControl : public Script, public Observer
{
private: 
	map<string, int> _mResourceSave;

	bool isDayToProduce = false;
	bool isProducing = false; 
	int _producingnStartTime = 0; 
	int _startTime = 0; 
public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnNotify(MSGTYPE type, string event) override; 

	void MakeResource(); 
};

