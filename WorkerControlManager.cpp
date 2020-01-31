#include "stdafx.h"
#include "WorkerControlManager.h"

WorkerControlManager::WorkerControlManager() {} 

WorkerControlManager* WorkerControlManager::GetInstance()
{
	static WorkerControlManager* instance = new WorkerControlManager();
	return instance;
}

void WorkerControlManager::Init()
{
	_mWorkers.clear();

	_mWorkers.insert(make_pair("Miner", 0));
	_mWorkers.insert(make_pair("Wood_Cutter", 0));
	_mWorkers.insert(make_pair("Water_Collecter", 0));
	_mWorkers.insert(make_pair("Carpenter", 0));
	_mWorkers.insert(make_pair("Refiner", 0));
}


void WorkerControlManager::Update()
{

}

void WorkerControlManager::SetPopulation(map<string, int> map)
{
	_mWorkers = map;
}