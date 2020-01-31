#include "stdafx.h"
#include "CraftButton.h"
#include "CraftTimeBar.h"
#include "WorkArea.h"

void CraftButton::Init()
{
	
}

void CraftButton::Update()
{

}

void CraftButton::OnMouseDown()
{
	//object->GetTransform()->SetScale(Vector2(0.5, 0.5));

	if (_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetIsActive() ||
		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->GetIsDone() == true) return;
	
	_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->SetIsActive(true);

	_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->
		SetStartTime(TimeManager::GetInstance()->GetTime());

	_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->SetCraftState(CRAFTING);
}

void CraftButton::OnMouseUp()
{
	//object->GetTransform()->SetScale(Vector2(1, 1));

}
