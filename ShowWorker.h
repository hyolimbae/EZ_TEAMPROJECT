#pragma once
#include "Script.h"
#include "Observer.h"

class WorkerControl; 
class ShowWorker : public Script, public Observer
{
private:

	Object* _showWorker; 
	Object* _showWorkerText;
	Object* _showWorkerSprite;
	Object* _totalWorker;

	WorkerControl* _workerControl; 

	vector<Object*> _vTest;


public:

	virtual void Init();
	virtual void Update();

	//totalWorker ui와 showworker 패널 이미지 연결하기 위한 링크 
	void SetLinkWithShowWorker(Object* total) { _totalWorker = total; }
	void SetLinkWithWorkerControl(WorkerControl* workerControl) { _workerControl = workerControl; }

	virtual void OnNotify(MSGTYPE type, string event) override;
};

