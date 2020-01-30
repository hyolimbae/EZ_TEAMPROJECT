#include "stdafx.h"
#include "DefaultBuilding.h"
#include "InfoBox.h"
#include "ConstructionTimeBar.h"

void DefaultBuilding::Init()
{
	Building::Init();
	_sprite = _thisObj->GetComponent<Sprite>();
	_sprite->SetSprite(Image::CreateImage("Sprite/" + _thisObj->GetTag() + "_Ruined.png"));
	_polydraw = _thisObj->GetComponent<PolygonDraw>();
	_infoBoxComponent = _infoBox->GetComponent<InfoBox>();

	_houseState = HOUSE_RUINED;
	_infoBox->SetIsActive(false);
}

void DefaultBuilding::Update()
{
	if (_thisObj->GetComponent<BoxCollider>()->GetOnMouse())
	{
		if (_houseState == HOUSE_RUINED)
			_infoBox->SetIsActive(true);
		else
			_infoBox->SetIsActive(false);
	}
	else
	{
		if (_houseState == HOUSE_RUINED)
			_infoBox->SetIsActive(false);
	}
}

