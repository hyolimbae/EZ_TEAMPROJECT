#include "stdafx.h"
#include "GameScene.h"
#include "ScaleCamera.h"
#include "WorkerControl.h"
#include "UI_ClickButton.h"
#include "WorkerControlUiSet.h"
#include "TotalWorker.h"
#include "ShowWorker.h"
#include "Time.h"

void GameScene::Init()
{
#pragma region UI 관련 Components 

	//BackGround
	Object* backGround = Object::CreateObject();
	backGround->SetTag("BackGround");
	backGround->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Test_background.png"));
	

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


	//workerControl POP-UP 창 
	Object* workerControl = Object::CreateObject(); 
	workerControl->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	workerControl->GetTransform()->SetPosition(Convert(566, 238, 500, 500));
	workerControl->AddComponent<WorkerControl>();
	workerControl->SetIsActive(false); 
	time->GetComponent<Time>()->AddObserver(workerControl->GetComponent<WorkerControl>());


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
	showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerControl(workerControl->GetComponent<WorkerControl>());
	totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	totalWorker->GetComponent<TotalWorker>()->SetLinkWithControl(workerControl);
	workerControl->GetComponent<WorkerControl>()->SetLinkWithWorker(totalWorker);
	

	//Inventory 
	//Object* inventory = Object::CreateObject();
	//inventory->SetTag("UI");
	//inventory->SetName("Inventory");
	//inventory->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Inventory.png"));
	//inventory->GetTransform()->SetPosition(Convert(53, 280, 450, 564));


#pragma region 안쓰는 것들 

	//Object* house = Object::CreateObject();
	//house->SetName("House");
	//auto houseCollider = house->AddComponent<BoxCollider>();
	//houseCollider->SetSize(Vector2(100, 10));
	//house->GetTransform()->SetPosition(Vector2(0, -33));
	//auto housePhysics = house->AddComponent<Physics>();
	//housePhysics->SetBodyType(StaticBody);
	//
	
	////애니메이터 설정하기전에 꼭 기본 SPRITE설정해줘야함. 
	//house->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/house.png"));
	//house->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 0.7f));
	//house->AddComponent<Physics>();
	//house->AddComponent<Animator>();
	//house->AddComponent<ScaleCamera>();
	////house->AddComponent<House>(); 


	////마우스 다운 체크용 TEXT
	//step->AddComponent<Text>();
	//step->GetComponent<Text>()->CreateText(L"", L"HYShortSamul", L"ko-KR", { 1,1,1,1 }, 50, 200, 200);


	
	//연기
	//auto Smoke = Object::CreateObject();
	//Smoke->SetTag("Smoke");
	//Smoke->GetTransform()->SetPosition(Vector2(70, 260));
	//Smoke->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Smoke.png"));


	////SetScale 작을 수록 줄어듬 0.1f--> 실같이 얇아짐
	//Smoke->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 1));
	//Smoke->AddComponent<BoxCollider>()->SetFixedRotation(true);
	//Smoke->GetComponent<BoxCollider>()->SetSize(Vector2(20, 40)); //바닥 땅 렉트 크기 설정


	////Smoke->AddComponent<Physics>();
	//Smoke->AddComponent<Animator>();

	//item들을 관리할 object 

	////공기
	//auto Air = Object::CreateObject();
	//Air->SetTag("Air"); 
	////Air->GetTransform()->SetPosition(Vector2(50, -70));
	////Air->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Air.png"));
	////Air->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));
	//Air->AddComponent<BoxCollider>();
	//Air->AddComponent<itemAction>(); 


	////물 
	//auto Water = Object::CreateObject();
	//Water->SetTag("Water");
	////Water->GetTransform()->SetPosition(Vector2(-10, -150));
	////Water->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Water.png"));
	////Water->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));
	//Water->AddComponent<BoxCollider>();
	//Water->AddComponent<itemAction>();


	////나무
	//auto Wood = Object::CreateObject();
	//Wood->SetTag("Wood");
	//Wood->AddComponent<itemAction>();
	////Wood->GetTransform()->SetPosition(Vector2(110, -150));
	////Wood->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Wood.png"));
	////Wood->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));
	//Wood->AddComponent<BoxCollider>();
	//Wood->GetComponent<BoxCollider>()->SetSize(Vector2(100, 100));

#pragma endregion
}
