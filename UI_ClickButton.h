#pragma once
#include "GgaetIp.h"

class WorkerControl;
class UI_ClickButton : public Script
{

private : 
	Transform* _transform;
	bool _isClicked; 

	WorkerControl* _workerControl;
	Sprite* _sprite;
	Collider* collider;


public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnMouseStay();
	virtual void OnMouseDown(); 
	virtual void OnMouseUp(); 

public:

	bool GetisClicked() { return _isClicked; }

	//PlusPopulation(); �Լ� ���� ���� WorkerControl�� ����

	void SetLinkWithWC(WorkerControl* wc) { _workerControl = wc; }
};

