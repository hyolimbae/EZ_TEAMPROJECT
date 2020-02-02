#include "stdafx.h"
#include "WcDoneButton.h"
#include "WorkerPanel.h"
#include "GameScene.h"

void WcDoneButton::Init()
{
}

void WcDoneButton::Update()
{
}

void WcDoneButton::OnMouseDown()
{
	WorkerControlManager::GetInstance()->SetPopulation(_workerPanel->GetMForSettingWorker());
	


	if (SceneManager::GetInstance()->GetNowScene()->GetTag() == "GameScene")
		_workerPanel->ControlOnOff(false);

	if (SceneManager::GetInstance()->GetNowScene()->GetTag() == "SetPopulationScene")
		SceneManager::GetInstance()->PushScene(new GameScene);
	
}
