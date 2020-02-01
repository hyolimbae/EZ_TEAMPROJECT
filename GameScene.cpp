#include "stdafx.h"
#include "GameScene.h"


//Eunsoul UI Header
#include "WorkerPanel.h"
#include "PlusMinusButton.h"
#include "TotalWorker.h"
#include "ShowWorker.h"
#include "Time.h"
#include "SettingPanel.h"
#include "SettingIcon.h"
#include "ResourceControl.h"
#include "VolumeBar.h" 

//Hyolm and Haeun
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
<<<<<<< HEAD
#include "Test.h"
=======
#include "BuildingComponent.h"
#include "NewBuilding.h"
>>>>>>> 38d9270b8499080fd5d3aadc49faa1ddbbc28de3

#include "RandomMove.h"
#include "CitizenAnimation.h"


void GameScene::Init()
{
	
	this->SetTag("GameScene");

	ShowCursor(false);

	Object* mouse = Object::CreateObject();
	mouse->SetTag("Mouse");
	mouse->AddComponent<Mouse>();
	ShowCursor(false);


#pragma region EUNSOUL

	//BackGround
	Object* backGround = Object::CreateObject();
	backGround->SetTag("BackGround");
	backGround->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Test_background.png"));
	

	//LuytenTown UI
	Object* luytenTown = Object::CreateObject();
	luytenTown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown.png"));
	luytenTown->GetTransform()->SetPosition(Convert(41, 23, 245, 53));


	//Time UI
	Object* time = Object::CreateObject();
	time->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown_Time.png"));
	time->GetTransform()->SetPosition(Convert(821, 23, 320, 52));
	time->AddComponent<Time>(); 
	time->SetIsActive(true); 


	//Inventory Bag Icon 
	Object* bag = Object::CreateObject(); 
	bag->SetTag("UI"); 
	bag->SetName("Inventory"); 
	bag->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Inventory_Icon.png"));
	bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96));


	//WorkerPanel POP-UP 
	Object* workerPanel = Object::CreateObject(); 
	workerPanel->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	workerPanel->GetTransform()->SetPosition(Convert(566, 238, 500, 500));
	workerPanel->AddComponent<WorkerPanel>();
	workerPanel->SetIsActive(false); 
	time->GetComponent<Time>()->AddObserver(workerPanel->GetComponent<WorkerPanel>());


	//ShowWorker Total UI
	Object* totalWorker = Object::CreateObject();
	totalWorker->AddComponent<BoxCollider>();
	totalWorker->AddComponent<TotalWorker>();
	totalWorker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Town_people.png"));
	totalWorker->GetTransform()->SetPosition(Convert(360, 23, 314, 52));
	totalWorker->GetComponent<BoxCollider>()->SetSize(Vector2(157, 26));

	
	Object* showWorker = Object::CreateObject();
	showWorker->GetTransform()->SetPosition(Vector2(-440, -90));
	showWorker->AddComponent<ShowWorker>();
	showWorker->SetIsActive(false);
	time->GetComponent<Time>()->AddObserver(showWorker->GetComponent<ShowWorker>());

	Object* resourceControl = Object::CreateObject(); 
	resourceControl->AddComponent<ResourceControl>(); 
	time->GetComponent<Time>()->AddObserver(resourceControl->GetComponent<ResourceControl>());


	//////////Setting Panel

	//Setting Icon                   
	Object* settingIcon = Object::CreateObject();
	settingIcon->SetTag("UI");
	settingIcon->SetName("Setting");
	settingIcon->AddComponent<BoxCollider>();
	settingIcon->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Setting_Icon.png"));
	settingIcon->GetTransform()->SetPosition(Convert(1480, 23, 51, 56));
	settingIcon->AddComponent<SettingIcon>(); 
	settingIcon->GetComponent<BoxCollider>()->SetSize(Vector2(100, 100));

	Object* settingPanel = Object::CreateObject();
	settingPanel->AddComponent<SettingPanel>();
	settingPanel->SetIsActive(false);


	//<Address Link>
	totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	workerPanel->GetComponent<WorkerPanel>()->SetLinkWithWorker(totalWorker);
	showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerPanel(workerPanel->GetComponent<WorkerPanel>());
	settingIcon->GetComponent<SettingIcon>()->SetLinkWithSettingPanel(settingPanel);

#pragma endregion

#pragma region HYOLIM

<<<<<<< HEAD
	///*auto tileMap = Object::CreateObject();
	//tileMap->GetTransform()->SetPosition(Vector2::zero);
	//tileMap->AddComponent<ControlCamera>();
	//tileMap->AddComponent<TileMap>();
	//auto collider = tileMap->AddComponent<BoxCollider>();
	//collider->SetSize(DesignResolution);
	//tileMap->AddComponent<Physics>()->SetBodyType(StaticBody);

=======
	auto tileMap = Object::CreateObject();
	tileMap->GetTransform()->SetPosition(Vector2::zero);
	tileMap->AddComponent<ControlCamera>();
	tileMap->AddComponent<TileMap>();
	/*auto collider = tileMap->AddComponent<BoxCollider>();
	collider->SetSize(DesignResolution);
	tileMap->AddComponent<Physics>()->SetBodyType(StaticBody);*/


	//인벤토리 
	//auto inven = Object::CreateObject();
	//auto invenCompo = inven->AddComponent<Inventory>();

	////부지 확장 테스트

	//auto lotExpansion = Object::CreateObject();
	//auto expansionCompo = lotExpansion->AddComponent<LotExpansion>();
	//auto lotExpansionColliderCompo = lotExpansion->AddComponent<BoxCollider>();
	//lotExpansionColliderCompo->SetSize(DesignResolution * 2);
	//expansionCompo->SetLinkToMap(tileMap);
	//expansionCompo->SetLinkToInventory(invenCompo);

	//도시 에이스타 테스트 
>>>>>>> 38d9270b8499080fd5d3aadc49faa1ddbbc28de3
	//for (int i = 0; i < 10; i++)
	//{
	//	auto citizen = Object::CreateObject();
	//	citizen->SetTag("H6");
	//	citizen->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H6_Move_Front.png"));
	//	citizen->GetTransform()->SetScale(Vector2(0.5, 0.5));
	//	citizen->AddComponent<Animator>();
	//	citizen->AddComponent<RandomMove>()->SetLinkToMap(tileMap);
	//	citizen->AddComponent<CitizenAnimation>();
<<<<<<< HEAD
	//}*/
=======
	//}

	auto check = Object::CreateObject();
	check->SetName("2");
	check->GetTransform()->SetDepth(2);
	auto checkcompo = check->AddComponent<TileCheck>();
	check->AddComponent<BoxCollider>()->SetSize(DesignResolution * 2);
	checkcompo->SetLink(tileMap);

	auto newBuildingTest = Object::CreateObject();
	newBuildingTest->SetTag("House_A");
	newBuildingTest->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/test.png"));
	newBuildingTest->GetComponent<Sprite>()->SetDepth(1);

	newBuildingTest->AddComponent<PolygonDraw>();
	newBuildingTest->AddComponent<BoxCollider>();
	newBuildingTest->AddComponent<BuildingComponent>()->SetBuilding(new NewBuilding(newBuildingTest));
	newBuildingTest->SetIsActive(false);

	checkcompo->SetLinkToBuilding(newBuildingTest);


	auto loadButton = Object::CreateObject();
	loadButton->SetName("1");
	loadButton->AddComponent<BoxCollider>();
	auto compo = loadButton->AddComponent<LoadButton>();
	loadButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/BuildingConstructionIcon.png"));
	loadButton->GetComponent<Sprite>()->SetDepth(30);
	
	compo->setLinkToMap(tileMap);
	compo->setLinkToNewBuilding(newBuildingTest);
	compo->setLink(check);

	//엄적 테스트
>>>>>>> 38d9270b8499080fd5d3aadc49faa1ddbbc28de3

	//auto achievementLinkButton = Object::CreateObject();
	//achievementLinkButton->GetTransform()->SetPosition(Vector2(DesignResolution.x / 2 - 100, DesignResolution.y / 2 - 50));
	//auto aSprite = achievementLinkButton->AddComponent<Sprite>();
	//aSprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementButton.png"));
	//aSprite->SetDepth((int)ZORDER::UI);


	//auto achievement = Object::CreateObject();
	//achievement->GetTransform()->SetPosition(Vector2(4, 65));
	//auto acompo = achievement->AddComponent<Achievement>();
	//auto asprite = achievement->AddComponent<Sprite>();
	//asprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementUI.png"));
	//asprite->SetDepth((int)ZORDER::UI);
	//achievement->AddComponent<BoxCollider>();

	//achievementLinkButton->AddComponent<LinkButton>()->SetLink(achievement);

	//auto notificationBox = Object::CreateObject();
	//auto ncompo = notificationBox->AddComponent<NotificationBox>();

	//auto bulidingManager = Object::CreateObject();
	//auto manager = bulidingManager->AddComponent<BuildingManager>();
	//manager->AddObserver(ncompo);
	//manager->AddObserver(acompo);

	//auto nightTest = Object::CreateObject();
	//auto nightTestSprite = nightTest->AddComponent<Sprite>();
	//nightTestSprite->SetSprite(Image::CreateImage("Sprite/Night.png"));
	//nightTestSprite->SetOpacity(0.7);

<<<<<<< HEAD
=======

	

>>>>>>> 38d9270b8499080fd5d3aadc49faa1ddbbc28de3
#pragma endregion

}
