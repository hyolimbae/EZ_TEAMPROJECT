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

	//처음에는 0명으로 설정 
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
	_totalPopulation = 0; //여기에 둬야 _totalPopulation이 쓰이는 다른 곳에 숫자가 들어감 

	//인부 숫자 출력
	for (int i = 0; i < _vWorkerNum.size(); i++)
	{
		//Create 가 아니라 changeText로 해야함 
		_vWorkerNum[i]->GetComponent<Text>()->ChangeText(to_wstring(_mWorkers[_vWorkerNum[i]->GetName()]));
	}

	for (auto it : _mWorkers)
	{
		_totalPopulation += it.second;
	}
	_totalWorker->GetComponent<TotalWorker>()->SetTotalNum(_totalPopulation); 
}

	//게임 종료시키고 팝업창 뜨게 설정
	//->버튼을 눌렀을 때 숫자가 증가 : 전체의 합이 50을 넘지 못하게 설정

void WorkerControl::PlusPopulation(string job)
{
	if ((_totalPopulation < 50) && (_totalPopulation >= 0))
	{
		_mWorkers[job]++;

		//cout << _mWorkers.find(job)->second << endl;
		//for (int i = 0; i < _vWorkerNum.size(); i++)
		//{
		//	//Create 가 아니라 changeText로 해야함 
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
	//workerControl 하고 있을 때는 타임의 시간을 잠시 멈추도록 설정 -->그래도 TIMEMANAGER는 계속 돌아가고 있다.
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
//	// 맨 첫 글자가 구분자인 경우 무시
//	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
//	// 구분자가 아닌 첫 글자를 찾는다
//	string::size_type pos = str.find_first_of(delimiters, lastPos);
//
//	while (string::npos != pos || string::npos != lastPos)
//	{
//		// token을 찾았으니 vector에 추가한다
//		tokens.push_back(str.substr(lastPos, pos - lastPos));
//		// 구분자를 뛰어넘는다.  "not_of"에 주의하라
//		lastPos = str.find_first_not_of(delimiters, pos);
//		// 다음 구분자가 아닌 글자를 찾는다
//		pos = str.find_first_of(delimiters, lastPos);
//	}
//}
//
////map[Key] = UpdateValue 만약 이미 Key값이 존재하는 어떤 인자의 값을 바꾸고 싶다면

#pragma region 안되는 코드
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
	//	_workerNum->GetComponent<Text>()->ChangeText(to_wstring(_mWorkers.find(_vWorkerNum[i]->GetName())->second));	 //to_wstring : int --> string으로 변환 
	//}

	//cout << _vWorkerNum[i]->GetName() << endl;
	//
	//int a = _mWorkers.size();
	//int b = _vWorkerNum.size();
	//int c = 100;

	//for (_miWorkers = _mWorkers.begin(); _miWorkers != _mWorkers.end(); _miWorkers++)
	//{
	//	////miWorkers->second++;//맵에 있는 자료를 더하는 작업 
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

	// job 로 받은 string에서 " UButton/MButton" 빼고 그거에 " Num"을 더해서 고 키 값의 세컨드를 바꿔라

	//Tokenize(job, _vTokenizedWords_Button);

	//_vTokenizedWords_Button[0] + " Num"

	//job + " Num"

#pragma endregion