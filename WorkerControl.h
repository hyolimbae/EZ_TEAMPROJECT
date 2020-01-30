#pragma once
#include "GgaetIp.h"
#include "Observer.h"


class WorkerControlUiSet;
class WorkerControl : public Script, public Observer
{
private:
	//map���� string, num ��� �� �����ϰ� ���� 
	map<string, int> _mWorkers;
	map<string, int> ::iterator _miWorkers;

	int _totalPopulation;
	int _saveWorker; 

	Object* _totalWorker; 
	Object* _workerNum;
	Object* _buttonDown;
	Object* _buttonUp;
	Object* _jobSprite; 
	Object* _settingDoneButton; 

	vector<Object*> _vWorkerNum;
	vector<string> _vTokenizedWords_Button;
	vector<string> _vTokenizedWords_Text;

public: 
	virtual void Init();
	virtual void Update();

	void PlusPopulation(string job); //��ư ������ �� �α� ���� up 
	void MinusPopulation(string job); //��ư ������ �� �α� ���� down
	void ControlOnOff(bool onoff); //workerControl on/off �Լ�

	virtual void OnNotify(MSGTYPE type, string event) override;
	
public:
	//GETTER & SETTER
	map<string, int> GetMWorkers() { return _mWorkers; }
	vector<Object*> GetVWorkerNum() { return _vWorkerNum; }
	map<string, int>::iterator GetMiWorkers() {return _miWorkers;} 

	void SetLinkWithWorker(Object* control) { _totalWorker = control; }
	vector<Object*> GetWorkerNum() { return _vWorkerNum; }
	int GetTotalPopulation() { return _totalPopulation; }
	/*void Tokenize(const string& str,
					vector<string>& tokens,
					const string& delimiters = " ");*/

};

