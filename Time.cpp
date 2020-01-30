#include "stdafx.h"
#include "Time.h"

void Time::Init()
{
	_isDay = true; 

	//�ð� ���� text 
	_hourText = Object::CreateObject(object);
	_hourText->AddComponent<Text>();
	_hourText->GetComponent<Text>()->CreateText(to_wstring(_gameTime/3600) + string_to_wstring("��"), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 18, 40, 40);
	_hourText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_hourText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(96, -5));

	_minuteText = Object::CreateObject(object); 
	_minuteText->AddComponent<Text>();
	_minuteText->GetComponent<Text>()->CreateText(to_wstring(_gameTime/60) + string_to_wstring("��"), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 18, 40, 40);
	_minuteText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_minuteText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(134, -5));

	//n���� ���� text 
	_dateText = Object::CreateObject(object); 
	_dateText->AddComponent<Text>(); 
	_dateText->GetComponent<Text>()->CreateText(to_wstring(_realTime/1.2), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 20, 60, 40);
	_dateText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_dateText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(-115, -5));

	//���� ���� text
	_dayText = Object::CreateObject(object);
	_dayText->AddComponent<Text>();
	_dayText->GetComponent<Text>()->CreateText(string_to_wstring(_dayOfWeek) + string_to_wstring("����"), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 20, 100, 40);
	_dayText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_dayText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(-25, -5));


	//��&�� �ð� �̹���
	_dayNightSprite = Object::CreateObject(object);
	_dayNightSprite->GetTransform()->SetPosition(Vector2(-153, 0));
	_dayNightSprite->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/DayIcon.png"));

}


void Time::Update()
{
	GameTimeSet(); 
	if(!_isDay)
	{
		_dayNightSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Night.png"));
		Notify(MSGTYPE::TIME, "NightStart"); //���� ������ ->�� ����
	}
	if (_isDay)
	{
		_dayNightSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/DayIcon.png"));
	}
}


void Time::GameTimeSet()
{
	_realTime = TimeManager::GetInstance()->GetTime();
	_gameTime = _realTime * 48 + 28800;

	int gameDayTime = _realTime % 1200; //���� �ð� 20�� // 900 = 15��(���ð�)

	//int gameDayTime = _gameTime % 720; //720��(48��*600) : realtime ���� 15�� (GameTime ���� 10�ð� (���ð�)) 
	//int gameNightTime = gameDayTime % 240; // 240��(48��*360) : realtime ���� 5�� (GameTime ���� 6�ð� (��ð�))

	_hourText->GetComponent<Text>()->ChangeText(to_wstring(_gameTime / 3600) + string_to_wstring("��"));
	_minuteText->GetComponent<Text>()->ChangeText(to_wstring((_gameTime / 60) % 60) + string_to_wstring("��"));

	//realTime 20�� ������ = �� �������� ǥ�� 
	_dateText->GetComponent<Text>()->ChangeText(to_wstring(_realTime / 1200) + string_to_wstring("����"));
	_dayText->GetComponent<Text>()->ChangeText(string_to_wstring(_dayOfWeek) + string_to_wstring("����"));
	
	_dayOfWeek = "��";

	if (gameDayTime <= 5)
	{ 
		_isDay = true; //���ð� �� == �� ���� 
		//cout << "���� ������" << _isDay;
	}

	if (gameDayTime > 5)
	{
		_isDay = false; //���ð� �� == �� ���� 
		//cout << "���� ������" << _isDay;
	}

	cout << gameDayTime;

	if (gameDayTime == 10)
	{
		Notify(MSGTYPE::TIME, "DayEnd"); //�� �ð��� �� --> �� �̹��� 
	}
	


#pragma region     ���� ���� 
	if ((_realTime / 1200) % 7 == 0) _dayOfWeek = "��";
	if ((_realTime / 1200) % 7 == 1) _dayOfWeek = "ȭ";
	if ((_realTime / 1200) % 7 == 2) _dayOfWeek = "��";
	if ((_realTime / 1200) % 7 == 3) _dayOfWeek = "��";
	if ((_realTime / 1200) % 7 == 4) _dayOfWeek = "��";
	if ((_realTime / 1200) % 7 == 5) _dayOfWeek = "��";
	if ((_realTime / 1200) % 7 == 6) _dayOfWeek = "��";
#pragma endregion 


}
