#pragma once
#include "Script.h"
#include <atlconv.h>
#include "Subject.h"

class Time : public Script, public Subject
{
private: 
	float _dayStartTime;
	float _nightStartTime;
	float _dayEndTime;
	int _realTime = 0; 
	int _gameTime = 0;
	int _gameStartTime =0; 

	Object* _hourText; //시간
	Object* _minuteText; //분 
	Object* _dateText; //n일차//요일
	Object* _dayText; //요일

	Object* _dayNightSprite;

	string _dayOfWeek;

	bool _isDay;

public:
	virtual void Init() override;
	virtual void Update() override;
	void GameTimeSet(); 
	wstring string_to_wstring(string str)
	{
		USES_CONVERSION;
		return std::wstring(A2W(str.c_str()));
	}

};

