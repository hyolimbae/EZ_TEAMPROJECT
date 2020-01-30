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
//	// 임시 House
	Object* houseTest = Object::CreateObject();
	houseTest->SetTag("House_C");
	houseTest->AddComponent<Sprite>();/*->SetSprite(Image::CreateImage("Sprite/House_C_Ruined.png"));*/
	houseTest->AddComponent<BuildingInfo>();
	houseTest->AddComponent<PolygonDraw>();
	houseTest->AddComponent<BuildingComponent>()->SetBuilding(new DefaultBuilding(houseTest));
	auto houseTestCollider = houseTest->AddComponent<BoxCollider>();
	houseTestCollider->SetSize(Vector2(90, 100));
	houseTest->GetTransform()->SetPosition(Vector2(-220, -110));

	// InfoBox
	Object* infoBox = Object::CreateObject();
	infoBox->AddComponent<InfoBox>();

	// ConstructionTimeBar
	Object* constructionTimeBar = Object::CreateObject();
	constructionTimeBar->AddComponent<ConstructionTimeBar>();
	constructionTimeBar->AddComponent<PolygonDraw>();
	constructionTimeBar->SetIsActive(false);
	constructionTimeBar->GetComponent<ConstructionTimeBar>()->SetLink(houseTest);

	// House랑 InfoBox 링크
	infoBox->GetComponent<InfoBox>()->SetLink(houseTest);
	((DefaultBuilding*)(houseTest->GetComponent<BuildingComponent>()->GetBuilding()))->SetLink(infoBox);
	((DefaultBuilding*)(houseTest->GetComponent<BuildingComponent>()->GetBuilding()))->SetTimeBarLink(constructionTimeBar);
	((DefaultBuilding*)(houseTest->GetComponent<BuildingComponent>()->GetBuilding()))->SetLinkWithManager(this);


	_vHouses.push_back(houseTest);
	


	////================================================================
	//// 임시 House2
	//Object* houseTest2 = Object::CreateObject();
	//houseTest2->SetTag("House_A");
	//houseTest2->AddComponent<Building>();
	//houseTest2->AddComponent<BuildingInfo>();
	//houseTest2->AddComponent<PolygonDraw>();
	//auto houseTest2Collider = houseTest2->AddComponent<BoxCollider>();
	//houseTest2Collider->SetSize(Vector2(90, 100));
	//houseTest2->GetTransform()->SetPosition(Vector2(220, -110));
	//// InfoBox
	//Object* infoBox2 = Object::CreateObject();
	//infoBox2->AddComponent<InfoBox>();
	//// ConstructionTimeBar
	//Object* constructionTimeBar2 = Object::CreateObject();
	//constructionTimeBar2->AddComponent<ConstructionTimeBar>();
	//constructionTimeBar2->AddComponent<PolygonDraw>();
	//constructionTimeBar2->SetIsActive(false);
	//constructionTimeBar2->GetComponent<ConstructionTimeBar>()->SetLink(houseTest2);

	//// House랑 InfoBox 링크
	//infoBox2->GetComponent<InfoBox>()->SetLink(houseTest2);
	//houseTest2->GetComponent<Building>()->SetLink(infoBox2);
	//houseTest2->GetComponent<Building>()->SetTimeBarLink(constructionTimeBar2);

	//_vHouses.push_back(houseTest2);



}
void BuildingManager::Update()
{
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