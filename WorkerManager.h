#pragma once
#include "GgaetIp.h"

class WorkerManager : public Script
{
private:

	//map���� string, num ��� �� �����ϰ� ���� 
	map<string, int> mWorkers;

	void Init();
	void Update();
	

public:
	//�κε��� ���ڸ� �����ϴ� �Լ�-- > setter �� �ٸ� ������ �κ� ���� �����ϰ� ����

	//void gWorkerPopulation(string job, int num); 

	//Getter �� �ڿ� Ŭ�������� ���� ������ �� �ֵ��� ����
	map<string, int> GetMWorkers() { return mWorkers; }

};
