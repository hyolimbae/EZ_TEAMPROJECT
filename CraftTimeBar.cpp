#include "stdafx.h"
#include "CraftTimeBar.h"
#include "CraftInfo.h"

void CraftTimeBar::Init()
{
	_startPosX = _workArea->GetTransform()->GetPosition().x - 50; //시작 위치 
	_maxPosX = _workArea->GetTransform()->GetPosition().x + 50; //최대 길이 

	_infoTime = _workArea->GetComponent<CraftInfo>()->GetMCraftInfo()[_workArea->GetTag()].time;

	_polydraw = object->GetComponent<PolygonDraw>();

	_polygonPos.push_back(Vector2(_startPosX, 0)); 
	_polygonPos.push_back(Vector2(_startPosX, 0));
	_polydraw->SetVertices(_polygonPos); //정점의 위치 설정
	_polydraw->SetStrokeWidth(5.f); //테두리 두께(stroke-width)

	_color = { 0.2f, 0.8f, 0.4f, 0.6f }; //기존 255가 1이라고 보면 된다 
	_polydraw->SetColor(_color);
}

void CraftTimeBar::Update()
{
	_polydraw->SetVertices(_polygonPos);  

	if (_polygonPos[1].x < _maxPosX) 
	{
		if (_craftState == INTERVAL) return;
		
		_polygonPos[1].x = (200.0 * (TimeManager::GetInstance()->GetTime() - _startTime)) / _infoTime + _startPosX;

		//_craftState = CRAFTING;
		_isDone = false;
	}
	else if(_polygonPos[1].x = _maxPosX)
	{
		_polygonPos[1].x = _startPosX;
		//_color.a = 0.f; //다 차면 투명해지게 
		_polydraw->SetColor(_color);

		_craftState = INTERVAL;
		_isDone = true;
		object->SetIsActive(false);
	}
	
}