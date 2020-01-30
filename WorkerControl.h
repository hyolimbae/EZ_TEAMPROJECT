#pragma once
#include "GgaetIp.h"
#include "Observer.h"


class WorkerControlUiSet;
class WorkerControl : public Script, public Observer
{
private:
	//map으로 string, num 엮어서 값 저장하게 설정 
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

	void PlusPopulation(string job); //버튼 눌렀을 때 인구 숫자 up 
	void MinusPopulation(string job); //버튼 눌렀을 때 인구 숫자 down
	void ControlOnOff(bool onoff); //workerControl on/off 함수

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

