#include "stdafx.h"
#include "SetPopulationScene.h"
#include "WorkerPanel.h"

void SetPopulationScene::Init()
{
	this->SetTag("SetPopulationScene");



	ApplicationManager::GetInstance()->SetResolution(1600, 900, false);

	Object* setPopulationScene = Object::CreateObject();
	setPopulationScene->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	setPopulationScene->GetTransform()->SetPosition(Vector2(0, 0)); 
	setPopulationScene->AddComponent<WorkerPanel>(); 


}
