#include "stdafx.h"
#include "BuildingManager.h"
#include "BuildingComponent.h"
#include "BuildingInfo.h"
#include "InfoBox.h"
#include "ConstructionTimeBar.h"

#include "DefaultBuilding.h"
#include "NewBuilding.h"

void BuildingManager::Init()
{
	_vHouses = MapManager::GetInstance()->GetVBuilding();
}

void BuildingManager::SetFixedNum(int num)
{
	_fixedHouseNum = num;

	Notify(MSGTYPE::INFORMATION, "������ ����");
	Notify(MSGTYPE::INFORMATION, "������ �밡");

	if (_fixedHouseNum == 4)
		Notify(MSGTYPE::NOTIFICATION,"������ ����");
	else if(_fixedHouseNum == 8)
		Notify(MSGTYPE::NOTIFICATION,"������ �밡");

}

void BuildingManager::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::TIME)
		return;

	for (int i = 0; i < _vHouses.size(); i++)
	{
		auto buildingCompo = _vHouses[i]->GetComponent<BuildingComponent>();
		if (buildingCompo->GetBuilding()->GetBuildingType() != NEW)
			return;

		if (event == "DayStart")
			_vHouses[i]->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/"+ _vHouses[i]->GetTag() + "_Fixed.png"));
		
		else if (event == "NightStart")
			_vHouses[i]->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + _vHouses[i]->GetTag() + "_Lighted.png"));
		
	}
}
