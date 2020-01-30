#include "stdafx.h"
#include "ShowWorker.h"
#include "WorkerControl.h"

void ShowWorker::Init()
{
	//WorkerManager���� Map ���� ����� ������ �α� ���� �ڷ� ��������
	//_showWorker = Object::CreateObject(); 
	object->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/PeopleUI.png"));
	//object->GetComponent<Sprite>()->GetTransform()->SetPosition(Vector2(_pos.x - 156, _pos.y-490));
	object->GetComponent<Sprite>()->GetTransform()->SetAnchorPoint(Vector2(0, 0));

	//int i = 0; 
	//for (auto it : _workerControl->GetMWorkers())
	//{
	//	//if (it.second == NULL) continue;
	//	/*_showWorkerSprite = Object::CreateObject(object);
	//	_showWorkerSprite->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/" 
	//		+ _workerControl->GetVWorkerNum()[i]->GetName() + ".png"));
	//	_showWorkerSprite->GetTransform()->SetPosition(object->GetTransform()->GetPosition() + Vector2(+20, 100+ i * 81));
	//	 */
	//	i++;

	//	cout << _workerControl->GetVWorkerNum()[i]->GetName() << endl;
	//}

	for (int i = 0; i < _workerControl->GetVWorkerNum().size(); i++)
	{
		//if (it.second == NULL) continue;
		_showWorkerSprite = Object::CreateObject(object);
		_showWorkerSprite->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/"
			+ _workerControl->GetVWorkerNum()[i]->GetName() + ".png"));
		_showWorkerSprite->GetTransform()->SetPosition(Vector2(-340, 36 + i * 73));

		//cout << _workerControl->GetVWorkerNum()[i] << endl;

		_showWorkerText = Object::CreateObject(object); 
		_showWorkerText->AddComponent<Text>()->
		CreateText(to_wstring(_workerControl->GetMWorkers()[_workerControl->GetVWorkerNum()[i]->GetName()]), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
		_showWorkerText->GetTransform()->SetPosition(Vector2(300, 120 + i * 75));

		_vTest.push_back(_showWorkerText);
	}
}

void ShowWorker::Update()
{
	for (int i = 0; i < _vTest.size(); i++)
	{
		//cout << _workerControl->GetMWorkers()[_workerControl->GetVWorkerNum()[i]->GetName()] << endl;
		_vTest[i]->GetComponent<Text>()->ChangeText(to_wstring(_workerControl->GetMWorkers()[_workerControl->GetVWorkerNum()[i]->GetName()]));
	}
	/*
	if (TIME->�� ���۵� �� ��ȣ) 
	{
		������ ���ڵ��� ���� �ִ� �α��� �� ������
	}
	*/
	/*
	if (TIME->�Ϸ� ���� ��ȣ �ޱ�) 
	{
		������ ���ڵ��� ���� �ִ� �α��� �� ������
	}
	*/

	//for (int i = 0; i < _workerControl->GetVWorkerNum().size(); i++)
//{
//	//Create �� �ƴ϶� changeText�� �ؾ��� 
//	_showWorkerText->GetComponent<Text>()->ChangeText(to_wstring(_workerControl->GetMWorkers()[_workerControl->GetVWorkerNum()[i]->GetName()]));
//}
}

void ShowWorker::OnNotify(MSGTYPE type, string event)
{
}
