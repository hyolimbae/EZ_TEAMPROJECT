#include "stdafx.h"
#include "WorkerControlManager.h"



WorkerControlManager::WorkerControlManager() 
{
	_mWorkers.clear();

	_mWorkers.insert(make_pair("Miner", 0));
	_mWorkers.insert(make_pair("Wood_Cutter", 0));
	_mWorkers.insert(make_pair("Water_Collecter", 0));
	_mWorkers.insert(make_pair("Carpenter", 0));
	_mWorkers.insert(make_pair("Refiner", 0));

	//�����ڿ� ������ �� �� ���� ����Ǵϱ� ���̻� 0���� �ʱ�ȭ ���� ����
	//init�� �θ� WorkerControlManager�� Scene���� ��Ͻ�ų ��� Scene�� �ڽĵ鿡�� ��� �ʱ�ȭ �ȴ�.
} 

WorkerControlManager* WorkerControlManager::GetInstance()
{
	static WorkerControlManager* instance = new WorkerControlManager();
	return instance;
}

void WorkerControlManager::SetPopulation(map<string, int> map)
{
	_mWorkers = map;
}