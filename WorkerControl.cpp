#include "stdafx.h"
#include "WorkerControl.h"
#include "WorkerManager.h"
#include "WorkerControlUiSet.h"
#include "UI_ClickButton.h"
#include "TotalWorker.h"
#include "WcDoneButton.h"

#include <numeric>

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

void WorkerControl::Init()
{
	_totalPopulation = 0;
	_mWorkers.clear();

	//ó������ 0������ ���� 
	_mWorkers.insert(make_pair("Wood_Cutter", 0));
	_mWorkers.insert(make_pair("Water_Collecter", 0));
	_mWorkers.insert(make_pair("Miner", 0));
	_mWorkers.insert(make_pair("Refiner", 0));
	_mWorkers.insert(make_pair("Carpenter", 0));

	int i = 0;
		for (auto it : _mWorkers)
		{
			_buttonDown = Object::CreateObject(object);
			_buttonDown->SetTag("Button_Minus");
			_buttonDown->SetName(it.first /*+ " MButton"*/);
			_buttonDown->AddComponent<BoxCollider>();
			_buttonDown->AddComponent<UI_ClickButton>();
			_buttonDown->GetTransform()->SetPosition(Vector2(40, -160 + i * 80));
			_buttonDown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Button_Minus_Icon.png"));
			_buttonDown->GetComponent<UI_ClickButton>()->SetLinkWithWC(this);


			_jobSprite = Object::CreateObject(object);
			_jobSprite->AddComponent<Sprite>();
			_jobSprite->SetTag("jobSprite");
			_jobSprite->SetName(it.first);
			_jobSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/" + it.first + ".png"));
			_jobSprite->GetTransform()->SetPosition(Vector2(-120, -165 + i * 81));


			_workerNum = Object::CreateObject(object);
			_workerNum->SetName(it.first);
			_workerNum->AddComponent<Text>();
			_workerNum->GetComponent<Text>()->CreateText(to_wstring(_mWorkers[object->GetName()]), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
			_workerNum->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
			_workerNum->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(100, -160 + i * 80));
			_vWorkerNum.push_back(_workerNum);


			_buttonUp = Object::CreateObject(object);
			_buttonUp->SetTag("Button_Plus");
			_buttonUp->SetName(it.first);
			_buttonUp->AddComponent<BoxCollider>();
			_buttonUp->AddComponent<UI_ClickButton>();
			_buttonUp->GetTransform()->SetPosition(Vector2(170, -160 + i * 80));
			_buttonUp->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Button_Plus_Icon.png"));
			_buttonUp->GetComponent<UI_ClickButton>()->SetLinkWithWC(this);

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
void WorkerControl::Update()
{
	_totalPopulation = 0; //���⿡ �־� _totalPopulation�� ���̴� �ٸ� ���� ���ڰ� �� 

	//�κ� ���� ���
	for (int i = 0; i < _vWorkerNum.size(); i++)
	{
		//Create �� �ƴ϶� changeText�� �ؾ��� 
		_vWorkerNum[i]->GetComponent<Text>()->ChangeText(to_wstring(_mWorkers[_vWorkerNum[i]->GetName()]));
	}

	for (auto it : _mWorkers)
	{
		_totalPopulation += it.second;
	}
	_totalWorker->GetComponent<TotalWorker>()->SetTotalNum(_totalPopulation); 
}

	//���� �����Ű�� �˾�â �߰� ����
	//->��ư�� ������ �� ���ڰ� ���� : ��ü�� ���� 50�� ���� ���ϰ� ����

void WorkerControl::PlusPopulation(string job)
{
	if ((_totalPopulation < 50) && (_totalPopulation >= 0))
	{
		_mWorkers[job]++;

		//cout << _mWorkers.find(job)->second << endl;
		//for (int i = 0; i < _vWorkerNum.size(); i++)
		//{
		//	//Create �� �ƴ϶� changeText�� �ؾ��� 
		//	_mWorkers[_vWorkerNum[i]->GetName()];
		//}
		//for (int i = 0; i < _vWorkerNum.size(); i++)
	//{
	//	cout << "job" << _vWorkerNum[i]->GetName() << _mWorkers[_vWorkerNum[i]->GetName()] << endl;
	//}
	}
}

void WorkerControl::MinusPopulation(string job)
{
	if ((_totalPopulation <= 50) && (_totalPopulation > 0))
	{
		_mWorkers[job] --;
	}
}

void WorkerControl::OnNotify(MSGTYPE type, string event)
{ 
	//workerControl �ϰ� ���� ���� Ÿ���� �ð��� ��� ���ߵ��� ���� -->�׷��� TIMEMANAGER�� ��� ���ư��� �ִ�.
	if (type != MSGTYPE::TIME) return;

	if (event == "DayEnd")
	{
		object->SetIsActive(true);
	}
}

void WorkerControl::ControlOnOff(bool onoff)
{
	object->SetIsActive(onoff);
}


//void WorkerControl::Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
//{
//	// �� ù ���ڰ� �������� ��� ����
//	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
//	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
//	string::size_type pos = str.find_first_of(delimiters, lastPos);
//
//	while (string::npos != pos || string::npos != lastPos)
//	{
//		// token�� ã������ vector�� �߰��Ѵ�
//		tokens.push_back(str.substr(lastPos, pos - lastPos));
//		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
//		lastPos = str.find_first_not_of(delimiters, pos);
//		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
//		pos = str.find_first_of(delimiters, lastPos);
//	}
//}
//
////map[Key] = UpdateValue ���� �̹� Key���� �����ϴ� � ������ ���� �ٲٰ� �ʹٸ�

#pragma region �ȵǴ� �ڵ�
	/*Object* workerSetBox = Object::CreateObject();
		auto button = workerSetBox->AddComponent<WorkerSetButton>();
		button->SetLink(this);*/

		//_workerControlUiSet = Object::CreateObject();
		//_workerControlUiSet->AddComponent<WorkerControlUiSet>();
		//_workerControlUiSet->GetComponent<WorkerControlUiSet>()->SetLink(object);
		//_workerControlUiSet->GetComponent<WorkerControlUiSet>()->SetButtonPosition(Vector2(object->GetTransform()->GetPosition().x,
		//	object->GetTransform()->GetPosition().y + i * 60));

		//_workerControlUiSet->SetName(it.first);

	//for (auto it : _mWorkers)
	//{
	//	cout << it.first << endl;
	//}

	//for (int i = 0; i < _vWorkerNum.size(); i++)
	//{
	//	cout << _vWorkerNum[i]->GetName() << endl;
	//}

	//for (_miWorkers = _mWorkers.begin(); _miWorkers != _mWorkers.end(); _miWorkers++)
	//{
	//	_workerNum->GetComponent<Text>()->ChangeText(to_wstring(_mWorkers.find(_vWorkerNum[i]->GetName())->second));	 //to_wstring : int --> string���� ��ȯ 
	//}

	//cout << _vWorkerNum[i]->GetName() << endl;
	//
	//int a = _mWorkers.size();
	//int b = _vWorkerNum.size();
	//int c = 100;

	//for (_miWorkers = _mWorkers.begin(); _miWorkers != _mWorkers.end(); _miWorkers++)
	//{
	//	////miWorkers->second++;//�ʿ� �ִ� �ڷḦ ���ϴ� �۾� 
	//	//_mWorkers[object->GetName()] ++;
	//	if (_miWorkers->first != _workerControlUiSet->GetName()) continue;
	//	
	//	_mWorkers.find(_miWorkers->first)->second++;

	//	cout << _miWorkers->first << ", " << _workerControlUiSet->GetName() << endl;

	//}

	//string str1 = _buttonUp->GetName();
	//string str2 = _workerNum->GetName();

	//Tokenize(str1, _vTokenizedWords_Button);
	//Tokenize(str2, _vTokenizedWords_Text);

	//for (auto it : _mWorkers)
	//{
	//	if (_vTokenizedWords_Button[0] != _vTokenizedWords_Text[0]) continue;

	//	//_mWorkers.find(_vTokenizedWords_Text[0] + " Num")->second++;

	//	cout << _vTokenizedWords_Text[0] << endl;
	//}

	//cout << _vTokenizedWords_Text[0] << endl;

	// job �� ���� string���� " UButton/MButton" ���� �װſ� " Num"�� ���ؼ� �� Ű ���� �����带 �ٲ��

	//Tokenize(job, _vTokenizedWords_Button);

	//_vTokenizedWords_Button[0] + " Num"

	//job + " Num"

#pragma endregion