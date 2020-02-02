#include "stdafx.h"
#include "SettingPanel.h"
#include "VolumeBar.h"


void SettingPanel::Init()
{
	object->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SettingPanel.png"));
	object->GetTransform()->SetPosition(Vector2(563, 290)); 

	//Æ©Åä¸®¾ó ¾À ¿ÀÇÂÇÒ ¹öÆ° »ý¼º 
	_tutorialButton = Object::CreateObject(object); 
	_tutorialButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowTutorial.png"));
	_tutorialButton->GetTransform()->SetPosition(Vector2(3, -100)); 
	
	auto volumeBar = Object::CreateObject(object); 
	volumeBar->AddComponent<VolumeBar>();
	volumeBar->GetComponent<VolumeBar>()->SetLinkWithSettingPanel(object);

}

void SettingPanel::Update()
{

}

void SettingPanel::OnMouseDown()
{

}
