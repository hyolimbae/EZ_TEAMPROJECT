#include "stdafx.h"
#include "WorkerManager.h"


void WorkerManager::Init()
{
	//������ ���ڴ� ��� �����Ǵµ� ��� �����ؾ� ����? 
	
	//ó������ 0������ ���� 

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
