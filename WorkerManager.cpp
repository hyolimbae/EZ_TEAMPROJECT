#include "stdafx.h"
#include "WorkerManager.h"


void WorkerManager::Init()
{
	//저장할 숫자는 계속 변동되는데 어떻게 설정해야 하지? 
	
	//처음에는 0명으로 설정 

	mWorkers.insert(make_pair("Miner", 0));
	mWorkers.insert(make_pair("Wood_Cutter", 0));
	mWorkers.insert(make_pair("Water_Collecter", 0));
	mWorkers.insert(make_pair("Carpenter", 0));
	mWorkers.insert(make_pair("Refiner", 0));
}


void WorkerManager::Update()
{


}


//void WorkerManager::SetWorkerPopulation(string job, int num)
//{
//	mWorkers[job] = num;
//}
//
