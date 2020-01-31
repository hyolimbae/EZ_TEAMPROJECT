#include "stdafx.h"
#include "Title.h"
#include "GameScene.h"
#include "FactoryScene.h"
#include "ForestScene.h"

void Title::Init()
{
	ApplicationManager::GetInstance()->SetResolution(1600, 900, false);
	SceneManager::GetInstance()->PushScene(new GameScene);
}