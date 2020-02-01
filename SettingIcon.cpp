#include "stdafx.h"
#include "SettingIcon.h"
#include "SettingPanel.h"



void SettingIcon::Init()
{
	_sprite = object->GetComponent<Sprite>(); 
}


void SettingIcon::Update()
{

}


void SettingIcon::OnMouseDown()
{
	_sprite->GetTransform()->SetScale(Vector2(0.98f, 0.98f));
	_settingPanel->SetIsActive(!_settingPanel->GetIsActive());
}

void SettingIcon::OnMouseUp()
{
	_sprite->GetTransform()->SetScale(Vector2(1.0f, 1.0f));
}
