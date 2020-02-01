#include "stdafx.h"
#include "FactoryScene.h"
#include "WorkerAnimation.h"
#include "FactoryWorkerMove.h"
#include "Bubble.h"
#include "CraftSpriteAndText.h"
#include "CraftInfo.h"
#include "LinkButton.h"
#include "CraftTimeBar.h"
#include "WorkArea.h"
#include "CraftBox.h"

void FactoryScene::Init()
{
	Object* background = Object::CreateObject();
	background->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Factory.png"));
	
	for (int i = 0; i < 3; i++)
	{
		Object* facWorker = Object::CreateObject();
		if (i == 0)	facWorker->SetTag("Brick");
		if (i == 1)	facWorker->SetTag("Metal");
		if (i == 2) facWorker->SetTag("Plank");
		string sumString = "H" + to_string(i % 6);
		facWorker->SetName(sumString);
		facWorker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + sumString + "_Idle_Front.png"));
		facWorker->GetTransform()->SetScale(Vector2(0.6f, 0.6f));
		if (facWorker->GetTag() == "Plank") facWorker->GetTransform()->SetPosition(Vector2(0, 265));
		if (facWorker->GetTag() == "Brick") facWorker->GetTransform()->SetPosition(Vector2(315, 80));
		if (facWorker->GetTag() == "Metal") facWorker->GetTransform()->SetPosition(Vector2(-240, 60));
		facWorker->AddComponent<Animator>();
		facWorker->AddComponent<FactoryWorkerMove>();
		facWorker->AddComponent<WorkerAnimation>();

		//Bubble Set
		Object* facBubble = Object::CreateObject();
		facBubble->AddComponent<Bubble>()->SetLink(facWorker);
		facBubble->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/" + facWorker->GetTag() + "_Bubble.png"));
	}

	for (int i = 0; i < 3; i++)
	{
		Object* workArea = Object::CreateObject();
		if(i == 0) workArea->SetTag("Plank");
		if(i == 1) workArea->SetTag("Brick");
		if(i == 2) workArea->SetTag("MetalSheet");
		if (workArea->GetTag() == "Plank")		workArea->GetTransform()->SetPosition(Vector2(0, 300));
		if (workArea->GetTag() == "Brick")		workArea->GetTransform()->SetPosition(Vector2(260, 50));
		if (workArea->GetTag() == "MetalSheet") workArea->GetTransform()->SetPosition(Vector2(-250, 40));
		workArea->AddComponent<WorkArea>();
		workArea->AddComponent<BoxCollider>();
		workArea->GetComponent<BoxCollider>()->SetSize(Vector2(130, 110));
		workArea->AddComponent<CraftInfo>();
		workArea->AddComponent<LinkButton>();

		// productionBox(product)가 infoBox같은 애
		Object* craftBox = Object::CreateObject();
		if (i == 0) craftBox->SetTag("Plank");
		if (i == 1) craftBox->SetTag("Brick");
		if (i == 2) craftBox->SetTag("MetalSheet");
		craftBox->AddComponent<BoxCollider>();
		craftBox->AddComponent<CraftBox>();
		craftBox->SetIsActive(false);
		workArea->GetComponent<LinkButton>()->SetLink(craftBox);

		//productionBox->SetIsActive(false);

		Object* craftTimeBar = Object::CreateObject();
		craftTimeBar->AddComponent<CraftTimeBar>();
		craftTimeBar->AddComponent<PolygonDraw>();
		craftTimeBar->SetIsActive(false);
		craftTimeBar->GetComponent<CraftTimeBar>()->SetLink(workArea);

		craftBox->GetComponent<CraftBox>()->SetLink(workArea);
		craftBox->GetComponent<CraftBox>()->SetTimeBarLink(craftTimeBar->GetComponent<CraftTimeBar>());
		workArea->GetComponent<WorkArea>()->SetLink(craftBox);
		workArea->GetComponent<WorkArea>()->SetTimeBarLink(craftTimeBar);
	}

}