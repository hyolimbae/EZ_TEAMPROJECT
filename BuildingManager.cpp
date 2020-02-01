#include "stdafx.h"
#include "BuildingManager.h"
#include "BuildingComponent.h"
#include "BuildingInfo.h"
#include "InfoBox.h"
#include "ConstructionTimeBar.h"

#include "DefaultBuilding.h"
#include "NewBuilding.h"

#include "MapManager.h"

void BuildingManager::Init()
{

	MapManager::GetInstance()->Load("CityMap",this);
	//for (int i = 0; i < 21; i++)
	//{
	//	// House
	//	Object* house = Object::CreateObject();

	//	if (i % 4 == 0) house->SetTag("House_A");
	//	if (i % 4 == 1) house->SetTag("House_B");
	//	if (i % 4 == 2) house->SetTag("House_C");
	//	if (i % 4 == 3) house->SetTag("House_D");

	//	house->AddComponent<Sprite>();
	//	house->AddComponent<BuildingInfo>();
	//	house->AddComponent<PolygonDraw>();
	//	house->AddComponent<BuildingComponent>()->SetBuilding(new DefaultBuilding(house));
	//	auto houseCollider = house->AddComponent<BoxCollider>();
	//	houseCollider->SetSize(Vector2(90, 100));
	//	house->GetTransform()->SetPosition(Vector2(0, 0));

	//	// InfoBox
	//	Object* infoBox = Object::CreateObject();
	//	infoBox->AddComponent<InfoBox>();

	//	// ConstructionTimeBar
	//	Object* constructionTimeBar = Object::CreateObject();
	//	constructionTimeBar->AddComponent<ConstructionTimeBar>();
	//	constructionTimeBar->AddComponent<PolygonDraw>();
	//	constructionTimeBar->SetIsActive(false);
	//	constructionTimeBar->GetComponent<ConstructionTimeBar>()->SetLink(house);

	//	// House랑 InfoBox 링크
	//	infoBox->GetComponent<InfoBox>()->SetLink(house);
	//	((DefaultBuilding*)(house->GetComponent<BuildingComponent>()->GetBuilding()))->SetLink(infoBox);
	//	((DefaultBuilding*)(house->GetComponent<BuildingComponent>()->GetBuilding()))->SetTimeBarLink(constructionTimeBar);
	//	((DefaultBuilding*)(house->GetComponent<BuildingComponent>()->GetBuilding()))->SetLinkWithManager(this);

	//	_vHouses.push_back(house);
	//}

	//_vHouses[0]->GetTransform()->SetPosition(Vector2(-363, 387));
	//_vHouses[1]->GetTransform()->SetPosition(Vector2(-58, 387));
	//_vHouses[2]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[3]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[4]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[5]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[6]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[7]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[8]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[9]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[10]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[11]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[12]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[13]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[14]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[15]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[16]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[17]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[18]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[19]->GetTransform()->SetPosition(Vector2(0, 0));
	//_vHouses[20]->GetTransform()->SetPosition(Vector2(0, 0));
}



void BuildingManager::SetFixedNum(int num)
{
	_fixedHouseNum = num;

	Notify(MSGTYPE::INFORMATION, "수리의 귀재");
	Notify(MSGTYPE::INFORMATION, "수리의 대가");

	if (_fixedHouseNum == 4)
		Notify(MSGTYPE::NOTIFICATION,"수리의 귀재");
	else if(_fixedHouseNum == 8)
		Notify(MSGTYPE::NOTIFICATION,"수리의 대가");

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
		{
			_vHouses[i]->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/"+ _vHouses[i]->GetTag() + "_Fixed.png"));
		}
		else if (event == "NightStart")
		{
			_vHouses[i]->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + _vHouses[i]->GetTag() + "_Lighted.png"));
		}
	}
}
