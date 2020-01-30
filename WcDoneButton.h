#pragma once
#include "Script.h"

class WorkerControl;
class WcDoneButton : public Script
{
	Transform* _transform;
	WorkerControl* _workerControl;
	Collider* collider;

public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnMouseDown();

	void SetLinkWithWC(WorkerControl* wc) { _workerControl = wc; }
};

