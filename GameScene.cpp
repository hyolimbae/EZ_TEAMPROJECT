#include "stdafx.h"
#include "GameScene.h"
#include "WorkerPanel.h"
#include "PlusMinusButton.h"
#include "TotalWorker.h"
#include "ShowWorker.h"
#include "Time.h"

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
#include "Test.h"

#include "RandomMove.h"
#include "CitizenAnimation.h"
#include "Tutorial.h"

void GameScene::Init()
{
	ShowCursor(false);

	Object* mouse = Object::CreateObject();
	mouse->SetTag("Mouse");
	mouse->AddComponent<Mouse>();
	ShowCursor(false);


#pragma region EUNSOL

	//BackGround
	//Object* backGround = Object::CreateObject();
	//backGround->SetTag("BackGround");
	//backGround->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Test_background.png"));
	//

	//LuytenTown UI
	Object* luytenTown = Object::CreateObject();
	luytenTown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown.png"));
	luytenTown->GetTransform()->SetPosition(Convert(41, 23, 245, 53));
	

	//ShowWorker Tap UI
	//Object* showWorkerTap = Object::CreateObject();
	//showWorkerTap->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/PeopleUI.png"));
	//showWorkerTap->GetTransform()->SetPosition(Convert(397, 86, 314, 458));


	//Time UI
	Object* time = Object::CreateObject();
	time->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown_Time.png"));
	time->GetTransform()->SetPosition(Convert(821, 23, 320, 52));
	time->AddComponent<Time>(); 
	time->SetIsActive(true); 


	//Setting Icon                   
	Object* UI_Setting = Object::CreateObject();
	UI_Setting->SetTag("UI");
	UI_Setting->SetName("Setting");
	UI_Setting->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Setting_Icon.png"));
	UI_Setting->GetTransform()->SetPosition(Convert(1480, 23, 51, 56));


	//Inventory Bag Icon 
	Object* bag = Object::CreateObject(); 
	bag->SetTag("UI"); 
	bag->SetName("Inventory"); 
	bag->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Inventory_Icon.png"));
	bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96));


	//WorkerPanel POP-UP â 
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


	//<Address Link>
	totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	//totalWorker->GetComponent<TotalWorker>()->SetLinkWithControl(workerPanel);
	workerPanel->GetComponent<WorkerPanel>()->SetLinkWithWorker(totalWorker);
	showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerPanel(workerPanel->GetComponent<WorkerPanel>());

#pragma endregion

#pragma region HYOLIM

	///*auto tileMap = Object::CreateObject();
	//tileMap->GetTransform()->SetPosition(Vector2::zero);
	//tileMap->AddComponent<ControlCamera>();
	//tileMap->AddComponent<TileMap>();
	//auto collider = tileMap->AddComponent<BoxCollider>();
	//collider->SetSize(DesignResolution);
	//tileMap->AddComponent<Physics>()->SetBodyType(StaticBody);

	//for (int i = 0; i < 10; i++)
	//{
	//	auto citizen = Object::CreateObject();
	//	citizen->SetTag("H6");
	//	citizen->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H6_Move_Front.png"));
	//	citizen->GetTransform()->SetScale(Vector2(0.5, 0.5));
	//	citizen->AddComponent<Animator>();
	//	citizen->AddComponent<RandomMove>()->SetLinkToMap(tileMap);
	//	citizen->AddComponent<CitizenAnimation>();
	//}*/

	auto achievementLinkButton = Object::CreateObject();
	achievementLinkButton->GetTransform()->SetPosition(Vector2(DesignResolution.x / 2 - 100, DesignResolution.y / 2 - 50));
	auto aSprite = achievementLinkButton->AddComponent<Sprite>();
	aSprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementButton.png"));
	aSprite->SetDepth((int)ZORDER::UI);


	auto achievement = Object::CreateObject();
	achievement->GetTransform()->SetPosition(Vector2(4, 65));
	auto acompo = achievement->AddComponent<Achievement>();
	auto asprite = achievement->AddComponent<Sprite>();
	asprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementUI.png"));
	asprite->SetDepth((int)ZORDER::UI);
	achievement->AddComponent<BoxCollider>();
	achievement->SetIsActive(false);

	achievementLinkButton->AddComponent<LinkButton>()->SetLink(achievement);

	auto notificationBox = Object::CreateObject();
	auto ncompo = notificationBox->AddComponent<NotificationBox>();

	auto bulidingManager = Object::CreateObject();
	auto manager = bulidingManager->AddComponent<BuildingManager>();
	manager->AddObserver(ncompo);
	manager->AddObserver(acompo);

	auto tutorial = Object::CreateObject();
	tutorial->AddComponent<Tutorial>();
	acompo->AddObserver(tutorial->GetComponent<Tutorial>());

	//auto nightTest = Object::CreateObject();
	//auto nightTestSprite = nightTest->AddComponent<Sprite>();
	//nightTestSprite->SetSprite(Image::CreateImage("Sprite/Night.png"));
	//nightTestSprite->SetOpacity(0.7);

#pragma endregion
}
