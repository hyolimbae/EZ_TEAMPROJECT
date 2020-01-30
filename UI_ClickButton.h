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

	//PlusPopulation(); 함수 쓰기 위해 WorkerControl과 연결

	void SetLinkWithWC(WorkerControl* wc) { _workerControl = wc; }
};

