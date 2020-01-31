#include "stdafx.h"
#include "ShowWorker.h"
#include "WorkerPanel.h"

void ShowWorker::Init()
{
	_isNight = false;

	object->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/PeopleUI.png"));
	object->GetComponent<Sprite>()->GetTransform()->SetAnchorPoint(Vector2(0, 0));

	for (int i = 0; i < _workerPanel->GetVWorkerNum().size(); i++)
	{
		_showWorkerSprite = Object::CreateObject(object);
		_showWorkerSprite->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/"
															+_workerPanel->GetVWorkerNum()[i]->GetName() + ".png"));
		_showWorkerSprite->GetTransform()->SetPosition(Vector2(96, 120 + i * 75));

		_showWorkerText = Object::CreateObject(object); 
		_showWorkerText->AddComponent<Text>()->
		CreateText(to_wstring(WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()]), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
		_showWorkerText->GetTransform()->SetPosition(Vector2(300, 120 + i * 75));

		_vWorkerNumList.push_back(_showWorkerText);
		_vWorkerAmount.push_back(WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()]);
	}

	_inHouseWorkerText = Object::CreateObject(object);
	_inHouseWorkerText->AddComponent<Text>();
	_inHouseWorkerText->GetComponent<Text>()->CreateText(to_wstring(_totalHouseWorker), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
	_inHouseWorkerText->GetTransform()->SetPosition(Vector2(300, 45));
}

void ShowWorker::Update()
{
	cout << _isNight;

	//�κε� int���� ��Ƴ��� vector
	for (int i = 0; i < _vWorkerAmount.size(); i++)
	{
		_vWorkerAmount[i] = WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()];
	}

	if (!_isNight) //���� ���� WorkerPanel �� �޾ƿ� �� �ֵ���
	{
		_inHouseWorkerText->GetComponent<Text>()->ChangeText(to_wstring(0));

		//������ worker ���� ���� 
		for (int i = 0; i < _vWorkerNumList.size(); i++)
		{
			_vWorkerNumList[i]->GetComponent<Text>()->ChangeText(to_wstring(WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()]));
		}
	}
	else if(_isNight) //���� �� 
	{
		//��ü �κ� ������ ���ư��� ���� -> �ߵ���
		_totalHouseWorker = _vWorkerAmount[0] + _vWorkerAmount[1] + _vWorkerAmount[2] + _vWorkerAmount[3] + _vWorkerAmount[4];
		_inHouseWorkerText->GetComponent<Text>()->ChangeText(to_wstring(_totalHouseWorker));

		//������ worker ���� 0���� --> Inhouse
		for (int i = 0; i < _vWorkerNumList.size(); i++)
		{
			_vWorkerNumList[i]->GetComponent<Text>()->ChangeText(to_wstring(0));
		}
	}
}

void ShowWorker::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::TIME) return;

	if (event == "NightStart") //���� ��
	{
		_isNight = true; 
	}
	else if (event == "NightEnd") //���� �� 
	{
		_isNight = false; //�ι�° �� ��ħ�� ��ȣ�� �ȵ���
	}
}

