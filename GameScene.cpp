#include "stdafx.h"
#include "GameScene.h"
#include "WorkerPanel.h"
#include "PlusMinusButton.h"
#include "TotalWorker.h"
#include "ShowWorker.h"
//#include "Time.h"

//Hyolim and Haeun
#include "AStar.h"
#include "ControlCamera.h"
#include "Character.h"
#include "TileMap.h"
#include "TilePick.h"

#include "BuildingManager.h"
#include "Building.h"

#include "Mouse.h"

#include "LinkButton.h"
#include "NotificationBox.h"
#include "Achievement.h"

#include "LoadButton.h"
#include "TileCheck.h"
#include "BuildingComponent.h"
#include "NewBuilding.h"

#include "RandomMove.h"
#include "CitizenAnimation.h"
#include "CitizenTalk.h"
#include "Tutorial.h"

#include "LotExpansion.h"
#include "Inventory.h"
#include "LoadBox.h"

#include <time.h>

void GameScene::Init()
{
	//ShowCursor(false);

	//Object* mouse = Object::CreateObject();
	//mouse->SetTag("Mouse");
	//mouse->AddComponent<Mouse>();
	//ShowCursor(false);


#pragma region EUNSOL

	////BackGround
	////Object* backGround = Object::CreateObject();
	////backGround->SetTag("BackGround");
	////backGround->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Test_background.png"));
	////

	////LuytenTown UI
	//Object* luytenTown = Object::CreateObject();
	//luytenTown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown.png"));
	//luytenTown->GetTransform()->SetPosition(Convert(41, 23, 245, 53));
	//

	////ShowWorker Tap UI
	////Object* showWorkerTap = Object::CreateObject();
	////showWorkerTap->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/PeopleUI.png"));
	////showWorkerTap->GetTransform()->SetPosition(Convert(397, 86, 314, 458));


	////Time UI
	//Object* time = Object::CreateObject();
	//time->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown_Time.png"));
	//time->GetTransform()->SetPosition(Convert(821, 23, 320, 52));
	//time->AddComponent<Time>(); 
	//time->SetIsActive(true); 


	////Setting Icon                   
	//Object* UI_Setting = Object::CreateObject();
	//UI_Setting->SetTag("UI");
	//UI_Setting->SetName("Setting");
	//UI_Setting->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Setting_Icon.png"));
	//UI_Setting->GetTransform()->SetPosition(Convert(1480, 23, 51, 56));


	////Inventory Bag Icon 
	//Object* bag = Object::CreateObject(); 
	//bag->SetTag("UI"); 
	//bag->SetName("Inventory"); 
	//bag->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Inventory_Icon.png"));
	//bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96));


	////WorkerPanel POP-UP â 
	//Object* workerPanel = Object::CreateObject(); 
	//workerPanel->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	//workerPanel->GetTransform()->SetPosition(Convert(566, 238, 500, 500));
	//workerPanel->AddComponent<WorkerPanel>();
	//workerPanel->SetIsActive(false); 
	//time->GetComponent<Time>()->AddObserver(workerPanel->GetComponent<WorkerPanel>());


	////ShowWorker Total UI
	//Object* totalWorker = Object::CreateObject();
	//totalWorker->AddComponent<BoxCollider>();
	//totalWorker->AddComponent<TotalWorker>();
	//totalWorker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Town_people.png"));
	//totalWorker->GetTransform()->SetPosition(Convert(360, 23, 314, 52));
	//totalWorker->GetComponent<BoxCollider>()->SetSize(Vector2(157, 26));

	//
	//Object* showWorker = Object::CreateObject();
	//showWorker->GetTransform()->SetPosition(Vector2(-440, -90));
	//showWorker->AddComponent<ShowWorker>();
	//showWorker->SetIsActive(false);
	//time->GetComponent<Time>()->AddObserver(showWorker->GetComponent<ShowWorker>());


	////<Address Link>
	//totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	////totalWorker->GetComponent<TotalWorker>()->SetLinkWithControl(workerPanel);
	//workerPanel->GetComponent<WorkerPanel>()->SetLinkWithWorker(totalWorker);
	//showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerPanel(workerPanel->GetComponent<WorkerPanel>());

#pragma endregion

#pragma region HYOLIM

	
	auto tileMap = Object::CreateObject();
	tileMap->AddComponent<ControlCamera>();
	tileMap->AddComponent<TileMap>();
	/*auto collider = tileMap->AddComponent<BoxCollider>();
	collider->SetSize(DesignResolution);
	tileMap->AddComponent<Physics>()->SetBodyType(StaticBody);*/


	//인벤토리 
	/*■■■■■■■■■■■■■■■■*/        Object* inventory = Object::CreateObject();
	/*■■■■■■■■■■■■■■■■*/        inventory->AddComponent<Inventory>();

	/*■■■■■■■■■■■■■■■■*/        MapManager::GetInstance()->SetInventoryLink(inventory->GetComponent<Inventory>());
	//부지 확장 테스트

	//auto lotExpansion = Object::CreateObject();
	////lotExpansion->GetTransform()->SetPosition(Vector2(0, -1000));
	//auto expansionCompo = lotExpansion->AddComponent<LotExpansion>();
	//auto lotExpansionColliderCompo = lotExpansion->AddComponent<BoxCollider>();
	////lotExpansionColliderCompo->SetSize(Vector2(50*80,50*80));
	//expansionCompo->SetLinkToMap(tileMap);
	//expansionCompo->SetLinkToInventory(invenCompo);

	//도시 에이스타 테스트 



	//for (int i = 0; i < 3; i++)
	//{
	//	int random = rand() % 6;
	//	auto citizen = Object::CreateObject();
	//	citizen->SetTag("H" + to_string(random));
	//	citizen->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H" + to_string(random)+"_Move_Front.png"));
	//	//citizen->GetTransform()->SetScale(Vector2(0.5, 0.5));
	//	citizen->AddComponent<Animator>();
	//	citizen->AddComponent<RandomMove>()->SetLinkToMap(tileMap);
	//	citizen->AddComponent<CitizenAnimation>();
	//	citizen->GetTransform()->SetDepth(100);


	//	auto citizentalk = Object::CreateObject();
	//	citizentalk->GetTransform()->SetPosition(citizen->GetTransform()->GetPosition());
	//	citizentalk->SetTag("H" + to_string(random));
	//	citizentalk->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H" +to_string(random)+"_Idle_Front.png"));
	//	//citizentalk->GetTransform()->SetScale(Vector2(0.5, 0.5));

	//	citizentalk->GetComponent<Sprite>()->SetOpacity(0.f);
	//	citizentalk->AddComponent<BoxCollider>();
	//	citizentalk->AddComponent<CitizenTalk>()->SetLinkToCitizen(citizen);
	//	citizentalk->GetTransform()->SetDepth(100);
	//}


		/*auto check = Object::CreateObject();
		check->GetTransform()->SetDepth(2);
		auto checkcompo = check->AddComponent<TileCheck>();
		check->AddComponent<BoxCollider>()->SetSize(Vector2(50*100,50*100));
		checkcompo->SetLink(tileMap);

		auto newBuildingTest = Object::CreateObject();
		newBuildingTest->SetTag("House_A");
		newBuildingTest->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/test.png"));
		newBuildingTest->GetComponent<Sprite>()->SetDepth(1);

		newBuildingTest->AddComponent<PolygonDraw>();
		newBuildingTest->AddComponent<BoxCollider>()->SetSize(Vector2(100,110));
		newBuildingTest->AddComponent<BuildingComponent>()->SetBuilding(new NewBuilding(newBuildingTest));
		newBuildingTest->SetIsActive(false);

		checkcompo->SetLinkToBuilding(newBuildingTest);*/


		//건물 생성 체크
		//auto constructionButton = Object::CreateObject();
		//constructionButton->GetTransform()->SetPosition(Vector2(-698, -207));
		//constructionButton->AddComponent<BoxCollider>();
		//constructionButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/BuildingConstructionIcon.png"));
		//constructionButton->GetTransform()->SetDepth(3);

		//auto loadBox = Object::CreateObject();
		//loadBox->GetTransform()->SetPosition(Vector2(-477, -118));
		//loadBox->AddComponent<BoxCollider>();
		//loadBox->AddComponent<LoadBox>();
		//constructionButton->AddComponent<LinkButton>()->SetLink(loadBox);
		//loadBox->SetIsActive(false);
		//loadBox->GetTransform()->SetDepth(4);
		//loadBox->GetComponent<LoadBox>()->SetLinkToMap(tileMap);


		////엄적 테스트

		//auto achievementLinkButton = Object::CreateObject();
		//achievementLinkButton->GetTransform()->SetPosition(Vector2(DesignResolution.x / 2 - 100, DesignResolution.y / 2 - 570));
		//auto aSprite = achievementLinkButton->AddComponent<Sprite>();
		//aSprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementButton.png"));
		//aSprite->SetDepth((int)ZORDER::UI);


		//auto achievement = Object::CreateObject();
		//achievement->GetTransform()->SetPosition(Vector2(500, 200));
		//auto acompo = achievement->AddComponent<Achievement>();
		//auto asprite = achievement->AddComponent<Sprite>();
		//asprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementUI.png"));
		//asprite->SetDepth((int)ZORDER::UI);
		//achievement->AddComponent<BoxCollider>();
		//achievement->SetIsActive(false);

		//achievementLinkButton->AddComponent<LinkButton>()->SetLink(achievement);

		//auto notificationBox = Object::CreateObject();
		//auto ncompo = notificationBox->AddComponent<NotificationBox>();

		auto buildingManager = Object::CreateObject();
		auto manager = buildingManager->AddComponent<BuildingManager>();
		//manager->AddObserver(ncompo);
		//manager->AddObserver(acompo);
		//acompo->AddObserver(loadBox->GetComponent<LoadBox>()); 

		MapManager::GetInstance()->Load("CityMap", manager);

		//Object* time = Object::CreateObject();
		//time->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown_Time.png"));
		//time->GetTransform()->SetPosition(Convert(821, 23, 320, 52));
		//time->AddComponent<Time>();
		//time->SetIsActive(true);

		//time->GetComponent<Time>()->AddObserver(manager);

		//auto tutorial = Object::CreateObject();
		//tutorial->AddComponent<Tutorial>();
		//acompo->AddObserver(tutorial->GetComponent<Tutorial>());

		//auto nightTest = Object::CreateObject();
		//auto nightTestSprite = nightTest->AddComponent<Sprite>();
		//nightTestSprite->SetSprite(Image::CreateImage("Sprite/Night.png"));
		//nightTestSprite->SetOpacity(0.7);


#pragma endregion
}
