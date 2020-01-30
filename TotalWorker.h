#pragma once
#include "Script.h"

//workmanager Map 값 다 가져와서 합쳐서 num 출력할 위치만 지정하면 되는건가
//OnMouseDown 일 경우 클릭 시 SHOW WORKER 클래스 펼쳐지게

class TotalWorker : public Script
{
private: 

	Object* _control; 
	Object* _totalWorkerSprite; 
	Object* _totalWorkerText; 

	Object* _showWorker;

	Sprite* _sprite;

	int _totalNum; 

public: 

	virtual void Init();
	virtual void Update();

	Vector2 Convert(int left, int top, int width, int height)
	{
		Vector2 temp;
		temp.x = left + width / 2 - DesignResolution.x / 2;
		temp.y = (-1) * (top + height / 2 - DesignResolution.y / 2);

		return temp;
	}

	void SetLinkWithControl(Object* control) { _control = control; }
	void SetTotalNum(int totalNum) { _totalNum = totalNum; }
	void SetLinkWithShowWorker(Object* showWorker) { _showWorker = showWorker; }
	
	virtual void OnMouseStay() override;
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

};

