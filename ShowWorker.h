#pragma once
#include "Script.h"
#include "Observer.h"

class WorkerPanel; 
class ShowWorker : public Script, public Observer
{
private:

	Object* _showWorker; 
	Object* _showWorkerText;
	Object* _showWorkerSprite;
	Object* _totalWorker;
	Object* _inHouseWorkerText; //���� �ִ� �α�

	WorkerPanel* _workerPanel; 

	vector<Object*> _vWorkerNumList;
	vector<int> _vWorkerAmount;

	int _totalHouseWorker = 0;

	bool _isNight;

public:

	virtual void Init();
	virtual void Update();

	virtual void OnNotify(MSGTYPE type, string event) override;

	void SetLinkWithWorkerPanel(WorkerPanel* workerPanel) { _workerPanel = workerPanel; }
};

