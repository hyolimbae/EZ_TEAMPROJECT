#include "stdafx.h"
#include "CraftTimeBar.h"
#include "CraftInfo.h"

void CraftTimeBar::Init()
{
	_startPosX = _workArea->GetTransform()->GetPosition().x - 50;
	_maxPosX = _workArea->GetTransform()->GetPosition().x + 50;

	_infoTime = _workArea->GetComponent<CraftInfo>()->GetMCraftInfo()[_workArea->GetTag()].time;

	_polydraw = object->GetComponent<PolygonDraw>();

	_polygonPos.push_back(Vector2(_startPosX, 0));
	_polygonPos.push_back(Vector2(_startPosX, 0));
	_polydraw->SetVertices(_polygonPos);
	_polydraw->SetStrokeWidth(5.f);

	_color.a = 0.6f;
	_color.r = 0.2f;
	_color.g = 0.8f;
	_color.b = 0.4f;

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
		//_color.a = 0.f;
		_polydraw->SetColor(_color);

		_craftState = INTERVAL;
		_isDone = true;
		object->SetIsActive(false);
	}
	
}