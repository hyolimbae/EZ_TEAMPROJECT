#include "stdafx.h"
#include "FixButton.h"
#include "Building.h"
#include "BuildingComponent.h"
#include "ConstructionTimeBar.h"
#include "DefaultBuilding.h"

void FixButton::OnMouseDown()
{
	int i = 0;

	if (((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetHouseState() != HOUSE_RUINED) 
		return;

	((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->SetHouseState(HOUSE_UNDER_CONSTRUCTION);

	((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetConstructionTimeBar()->SetIsActive(true);
	((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetConstructionTimeBar()
								->GetComponent<ConstructionTimeBar>()->SetStartTime(TimeManager::GetInstance()->GetTime());

}
