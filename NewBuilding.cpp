#include "stdafx.h"
#include "NewBuilding.h"

void NewBuilding::Init()
{
	Building::Init();
	buildingType = NEW;
	_sprite = _thisObj->GetComponent<Sprite>();
	_sprite->SetSprite(Image::CreateImage("Sprite/" + _thisObj->GetTag() + "_Fixed.png"));
}

void NewBuilding::Update()
{
	Building::Update();
}


