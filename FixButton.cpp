#include "stdafx.h"
#include "FixButton.h"
#include "Building.h"
#include "BuildingComponent.h"
#include "ConstructionTimeBar.h"
#include "DefaultBuilding.h"
#include "Inventory.h"
#include "InfoBox.h"

void FixButton::OnMouseDown()
{
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        _neededResources = object->GetParent()->GetComponent<InfoBox>()->GetMValidResources();
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        for (auto it : _neededResources)
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/ {
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/           if (_inventory->GetItemCount(it.first) < it.second)
            /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/              return;
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    }

    if (((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetHouseState() != HOUSE_RUINED)
        return;

    ((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->SetHouseState(HOUSE_UNDER_CONSTRUCTION);

    ((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetConstructionTimeBar()->SetIsActive(true);
    ((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetConstructionTimeBar()
        ->GetComponent<ConstructionTimeBar>()->SetStartTime(TimeManager::GetInstance()->GetTime());
}