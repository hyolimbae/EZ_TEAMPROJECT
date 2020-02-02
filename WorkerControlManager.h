#pragma once
#include "GgaetIp.h"


class WorkerControlManager
{
private:
	WorkerControlManager(); //������ --> ��� ������ �� Ŭ������ ������ �� ���� �ȴ�. 
	//map���� string, num ��� �� �����ϰ� ���� 
	map<string, int> _mWorkers;
	map<string, int> ::iterator _miWorkers;

	int _totalPopulation =0;


public:

	static WorkerControlManager* GetInstance(); //��𿡼��� �� instance �� ������ �� ���� ���������� ���� ����


	map<string, int> GetMWorkers() { return _mWorkers; }
	map<string, int>::iterator GetMiWorkers() { return _miWorkers; }
	int GetTotalPopulation() { return _totalPopulation; }

	void SetPopulation(map<string, int> _map);
	//void SetPopulation(string job, int num); //��ư ������ �� �α� ���� up 

	void SetTotalPopulation(int num) { _totalPopulation = num; }

	void Init() {}
	void Update() {}
};

