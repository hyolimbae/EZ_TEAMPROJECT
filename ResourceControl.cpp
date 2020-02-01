#include "stdafx.h"
#include "ResourceControl.h"

//1�� �ڿ� ���� �����ϴ� Ŭ���� 

void ResourceControl::Init()
{

	_startTime = TimeManager::GetInstance()->GetTime(); 

	_mResourceSave.clear(); 
	
	_mResourceSave.insert(make_pair("Stone", 0));
	_mResourceSave.insert(make_pair("Dirt", 0));
	_mResourceSave.insert(make_pair("Water", 0));
	_mResourceSave.insert(make_pair("Ore", 0));
	_mResourceSave.insert(make_pair("Wood", 0));

	//Wood_Cutter --> ���� �޾ƿͼ� = ���� ������ * 3�п� 2���� 
	//Miner --> ���� �޾ƿͼ� = ����, ����, �� ������ * 3�п� 2���� 
	//Water_Collecter --> ���� �޾ƿͼ� = �� ������ * 3�п� 2���� 
}


void ResourceControl::Update()
{
	if (isDayToProduce) //�� ������ �� 
	{
		//_producingnStartTime = ���� �ð� ���ϱ�
		_producingnStartTime = TimeManager::GetInstance()->GetTime() - _startTime;
		if (_producingnStartTime >= PRODUCTIONTIME) // 5���� �� �� ���� ����ǰ�
		{
			MakeResource();
			_startTime = TimeManager::GetInstance()->GetTime(); //�ð� �ٽ� �ʱ�ȭ
		}
	}
}


void ResourceControl::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::TIME) return;

	if (event == "isDay") //���� �� �ڿ� �����ϵ���
	{
		isDayToProduce = true;
	}
}

void ResourceControl::MakeResource()
{
		//_mResourceSave["Stone", "Dirt", "Ore" ] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 2;
		_mResourceSave["Ore"] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 2;
		_mResourceSave["Dirt"] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 2;
		_mResourceSave["Stone"] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 2;
		_mResourceSave["Water"] += WorkerControlManager::GetInstance()->GetMWorkers()["Water_Collecter"] *2;
		_mResourceSave["Wood"] += WorkerControlManager::GetInstance()->GetMWorkers()["Wood_Cutter"] * 2;

//#pragma region �ڿ� Ȯ�ο� cout ���
//		cout << "�� �ڿ� : " << _mResourceSave["Stone"] << endl;
//		cout << "�� �ڿ� : " << _mResourceSave["Dirt"] << endl;
//		cout << "�� �ڿ� : " << _mResourceSave["Water"] << endl;
//		cout << "���� �ڿ� : " << _mResourceSave["Ore"] << endl;
//		cout << "���� �ڿ� : " << _mResourceSave["Wood"] << endl;
//		cout << "======================" << endl;
//#pragma endregion
}