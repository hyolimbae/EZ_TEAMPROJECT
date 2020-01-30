#pragma once
#include "GgaetIp.h"

class WorkerManager : public Script
{
private:

	//map으로 string, num 엮어서 값 저장하게 설정 
	map<string, int> mWorkers;

	void Init();
	void Update();
	

public:
	//인부들의 숫자를 조정하는 함수-- > setter 로 다른 곳에서 인부 조절 가능하게 설정

	//void gWorkerPopulation(string job, int num); 

	//Getter 로 자원 클래스에서 값을 가져갈 수 있도록 설정
	map<string, int> GetMWorkers() { return mWorkers; }

};
