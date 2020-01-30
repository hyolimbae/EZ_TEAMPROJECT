#include "stdafx.h"
#include "ShowWorker.h"
#include "WorkerControl.h"

void ShowWorker::Init()
{
	//WorkerManager에서 Map 으로 묶어둔 직업별 인구 설정 자료 가져오기
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
	if (TIME->밤 시작될 때 신호) 
	{
		기존의 숫자들을 집에 있는 인구로 다 보내기
	}
	*/
	/*
	if (TIME->하루 시작 신호 받기) 
	{
		기존의 숫자들을 집에 있는 인구로 다 보내기
	}
	*/

	//for (int i = 0; i < _workerControl->GetVWorkerNum().size(); i++)
//{
//	//Create 가 아니라 changeText로 해야함 
//	_showWorkerText->GetComponent<Text>()->ChangeText(to_wstring(_workerControl->GetMWorkers()[_workerControl->GetVWorkerNum()[i]->GetName()]));
//}
}

void ShowWorker::OnNotify(MSGTYPE type, string event)
{
}
