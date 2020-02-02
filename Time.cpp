#include "stdafx.h"
#include "Time.h"

void Time::Init()
{
	_isDay = true; 

	//시간 띄우는 text 
	_hourText = Object::CreateObject(object);
	_hourText->AddComponent<Text>();
	_hourText->GetComponent<Text>()->CreateText(to_wstring(_gameTime/3600) + string_to_wstring("시"), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 18, 40, 40);
	_hourText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_hourText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(96, -5));

	_minuteText = Object::CreateObject(object); 
	_minuteText->AddComponent<Text>();
	_minuteText->GetComponent<Text>()->CreateText(to_wstring(_gameTime/60) + string_to_wstring("분"), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 18, 40, 40);
	_minuteText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_minuteText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(134, -5));

	//n일차 띄우는 text 
	_dateText = Object::CreateObject(object); 
	_dateText->AddComponent<Text>(); 
	_dateText->GetComponent<Text>()->CreateText(to_wstring(_realTime/1.2), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 20, 60, 40);
	_dateText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_dateText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(-115, -5));

	//요일 띄우는 text
	_dayText = Object::CreateObject(object);
	_dayText->AddComponent<Text>();
	_dayText->GetComponent<Text>()->CreateText(string_to_wstring(_dayOfWeek) + string_to_wstring("요일"), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 20, 100, 40);
	_dayText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftCenter);
	_dayText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(-25, -5));

	//낮&밤 시간 이미지
	_dayNightSprite = Object::CreateObject(object);
	_dayNightSprite->GetTransform()->SetPosition(Vector2(-153, 0));
	_dayNightSprite->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/DayIcon.png"));
}


void Time::Update()
{
	GameTimeSet(); 

}


void Time::GameTimeSet()
{
	_realTime = TimeManager::GetInstance()->GetTime();
	_gameTime = _realTime * 48 + 28800; //시간이 흘렀을 때 얘는 8시로 초기화 안될 것임 

	int gameDayTime = _realTime % 10; //현실 시간 20분 // 900 = 15분(낮시간)
	//cout << "시간" << gameDayTime << endl;
	//int gameDayTime = _gameTime % 720; //720초(48초*600) : realtime 기준 15분 (GameTime 기준 10시간 (낮시간)) 
	//int gameNightTime = gameDayTime % 240; // 240초(48초*360) : realtime 기준 5분 (GameTime 기준 6시간 (밤시간))

	_hourText->GetComponent<Text>()->ChangeText(to_wstring(_gameTime / 3600) + string_to_wstring("시"));
	_minuteText->GetComponent<Text>()->ChangeText(to_wstring((_gameTime / 60) % 60) + string_to_wstring("분"));

	//realTime 20분 나누기 = 몇 일차인지 표시 
	_dateText->GetComponent<Text>()->ChangeText(to_wstring(_realTime / 1200) + string_to_wstring("일차"));
	_dayText->GetComponent<Text>()->ChangeText(string_to_wstring(_dayOfWeek) + string_to_wstring("요일"));
	
	_dayOfWeek = "월";


	//TEST 
	if (gameDayTime == 0)
	{
		if (_isDay)
			return;
		_isDay = true;
		//cout << "낮이다" << endl;
		_dayNightSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/DayIcon.png"));
		Notify(MSGTYPE::TIME, "isDay");
	}
	else if (gameDayTime == 5)
	{
		if (!_isDay)
			return;
		_isDay = false;
		//cout << "밤이다" << endl;
		_dayNightSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/DayIcon.png"));
		Notify(MSGTYPE::TIME, "isNight");
	}

	if (gameDayTime == 10)
	{
		Notify(MSGTYPE::TIME, "SingleDateEnd"); //밤 시간일 때
	}

	//if (gameDayTime == 10 && gameDayTime!=0)
	//{
	//	Notify(MSGTYPE::TIME, "SingleDateEnd"); //밤 시간일 때 
	//}
	

#pragma region     요일 설정 
	if ((_realTime / 1200) % 7 == 0) _dayOfWeek = "월";
	if ((_realTime / 1200) % 7 == 1) _dayOfWeek = "화";
	if ((_realTime / 1200) % 7 == 2) _dayOfWeek = "수";
	if ((_realTime / 1200) % 7 == 3) _dayOfWeek = "목";
	if ((_realTime / 1200) % 7 == 4) _dayOfWeek = "금";
	if ((_realTime / 1200) % 7 == 5) _dayOfWeek = "토";
	if ((_realTime / 1200) % 7 == 6) _dayOfWeek = "일";
#pragma endregion 


}
