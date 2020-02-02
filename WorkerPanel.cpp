#include "stdafx.h"
#include "WorkerPanel.h"
#include "PlusMinusButton.h"
#include "TotalWorker.h"
#include "WcDoneButton.h"

#include <numeric>

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:")

void WorkerPanel::Init()
{
	_mForSettingWorker = WorkerControlManager::GetInstance()->GetMWorkers(); 

	int i = 0;
		for (auto it : _mForSettingWorker)
		{
			_buttonDown = Object::CreateObject(object);
			_buttonDown->SetTag("Button_Minus");
			_buttonDown->SetName(it.first /*+ " MButton"*/);
			_buttonDown->AddComponent<BoxCollider>();
			_buttonDown->AddComponent<PlusMinusButton>();
			_buttonDown->GetTransform()->SetPosition(Vector2(40, -160 + i * 80));
			_buttonDown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Button_Minus_Icon.png"));
			_buttonDown->GetComponent<PlusMinusButton>()->SetLinkWithWC(this);


			_jobSprite = Object::CreateObject(object);
			_jobSprite->AddComponent<Sprite>();
			_jobSprite->SetTag("jobSprite");
			_jobSprite->SetName(it.first);
			_jobSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/" + it.first + ".png"));
			_jobSprite->GetTransform()->SetPosition(Vector2(-120, -165 + i * 81));


			_workerNum = Object::CreateObject(object);
			_workerNum->SetName(it.first);
			_workerNum->AddComponent<Text>();
			_workerNum->GetComponent<Text>()->CreateText(to_wstring(_mForSettingWorker[it.first]), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
			_workerNum->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
			_workerNum->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(100, -160 + i * 80));
			_vWorkerNum.push_back(_workerNum);


			_buttonUp = Object::CreateObject(object);
			_buttonUp->SetTag("Button_Plus");
			_buttonUp->SetName(it.first);
			_buttonUp->AddComponent<BoxCollider>();
			_buttonUp->AddComponent<PlusMinusButton>();
			_buttonUp->GetTransform()->SetPosition(Vector2(170, -160 + i * 80));
			_buttonUp->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Button_Plus_Icon.png"));
			_buttonUp->GetComponent<PlusMinusButton>()->SetLinkWithWC(this);

			i++;
		}

	_settingDoneButton = Object::CreateObject(object);
	_settingDoneButton->SetName("settingDoneButton");
	_settingDoneButton->AddComponent<BoxCollider>();
	_settingDoneButton->GetComponent<BoxCollider>()->SetSize(Vector2(70, 17));
	_settingDoneButton->AddComponent<WcDoneButton>();
	_settingDoneButton->GetTransform()->SetPosition(Vector2(0, -230));
	_settingDoneButton->SetIsActive(true);
	_settingDoneButton->GetComponent<WcDoneButton>()->SetLinkWithWC(this);
}


void WorkerPanel::Update()
{
	_totalPopulationForSet = 0;

	//������Ʈ �Ǵ� �� �α���
	for (auto it : _mForSettingWorker)
	{
		_totalPopulationForSet += it.second; 
	}

	//�κ� ���� ���
	for (int i = 0; i < _vWorkerNum.size(); i++)
	{
		_vWorkerNum[i]->GetComponent<Text>()->ChangeText(to_wstring(_mForSettingWorker[_vWorkerNum[i]->GetName()]));
	}
}


void WorkerPanel::ContolPopulationNum(int num, string job)
{
	_mForSettingWorker[job] = _mForSettingWorker[job] + num;
}


void WorkerPanel::OnNotify(MSGTYPE type, string event)
{ 
	//WorkerPanel �ϰ� ���� ���� Ÿ���� �ð��� ��� ���ߵ��� ���� -->�׷��� TIMEMANAGER�� ��� ���ư��� �ִ�.
	if (type != MSGTYPE::TIME) return;

	if (event == "SingleDateEnd")
	{
		object->SetIsActive(true);
	}
}


void WorkerPanel::ControlOnOff(bool onoff)
{
	object->SetIsActive(onoff);
}
