#include "stdafx.h"
#include "CraftResult.h"
#include "CraftTimeBar.h"

void CraftResult::Init()
{
	object->AddComponent<BoxCollider>();
	object->GetComponent<BoxCollider>()->SetSize(Vector2(50, 50));
	object->GetTransform()->SetPosition(Vector2(120, 10));
}

void CraftResult::OnMouseDown()
{
	if (_timeBar->GetIsDone())
	{
		_timeBar->SetCraftState(INTERVAL);
		object->GetComponent<Sprite>()->SetOpacity(0.2f);
		_timeBar->SetIsDone(false);
	}
	//if (_timeBar->GetCraftState() == INTERVAL && _timeBar->GetIsDone())
	//{
	//	_timeBar->SetCraftState(CRAFTING);
	//	_timeBar->SetIsDone(false);
	//	object->GetComponent<Sprite>()->SetOpacity(0.2f);
	//}

}