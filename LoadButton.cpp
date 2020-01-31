#include "stdafx.h"
#include "LoadButton.h"
#include "TileCheck.h"
#include "TileMap.h"
#include "Building.h"
#include "Test.h"

void LoadButton::Init()
{
	object->AddComponent<BoxCollider>();
	vTotal = map->GetComponent<TileMap>()->GetVTotal();
	check = checkObj->GetComponent<TileCheck>();
	newBuilding->GetComponent<Sprite>()->SetOpacity(0.5f);
}

void LoadButton::Update()
{
	if (!isClicked || newBuilding->GetComponent<Test>()->GetIsFixedPosition())
		return;

	newBuilding->GetTransform()->SetPosition(vTotal[check->GetMouseIndex().y + check->GetMouseIndex().x * TILENUM_Y]->GetTransform()->GetPosition() - Vector2(TILEWIDTH/2,0));
}

void LoadButton::OnMouseDown()
{
	isClicked = true;
	newBuilding->SetIsActive(true);

	////Å¸ÀÏºä Á¦¾î 
	//if (isClicked)
	//	map->SetIsActive(true);
	//else
	//	map->SetIsActive(false);

}


