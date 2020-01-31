#include "stdafx.h"
#include "TileCheck.h"
#include "TileMap.h"
#include "Test.h"

void TileCheck::Init()
{
	vTotal = map->GetComponent<TileMap>()->GetVTotal();

	vector<Vector2> pos;
	pos.push_back(Vector2(-TILEWIDTH / 2, TILEHEIGHT / 2));
	pos.push_back(Vector2(TILEWIDTH / 2, TILEHEIGHT / 2));
	pos.push_back(Vector2(TILEWIDTH / 2, -TILEHEIGHT / 2));
	pos.push_back(Vector2(-TILEHEIGHT / 2, -TILEHEIGHT / 2));

	newBuildingSprite = newBuilding->GetComponent<Sprite>();
	dimension.x = newBuildingSprite->GetFrameSize().x / TILEWIDTH;
	dimension.y = newBuildingSprite->GetFrameSize().y / TILEHEIGHT;

	for (int i = 0; i < dimension.x; i++)
	{
		for (int j = 0; j < dimension.y; j++)
		{
			Object* normalTile = Object::CreateObject(object);
			auto tilePoly = normalTile->AddComponent<PolygonDraw>();
			tilePoly->SetVertices(pos);
			vTemp.push_back(normalTile);
		}
	}

}

void TileCheck::Update()
{
	if (object->GetComponent<BoxCollider>()->GetOnMouse())
	{
		DrawTile();
	}
	
}

void TileCheck::OnMouseDown()
{
	if (newBuilding->GetComponent<Test>()->GetIsFixedPosition())
		return;


	//FIX POSITION 
	for (int i = 0; i < dimension.x; i++)
		for (int j = 0; j < dimension.y; j++)
			vTotal[(GetMouseIndex().x - dimension.x / 2 + i) * TILENUM_Y + GetMouseIndex().y + dimension.y / 2 - j]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::WALL);
		

	newBuilding->GetComponent<Test>()->SetIsFixedPosition(true);
	newBuilding->GetComponent<Sprite>()->SetOpacity(1.f);
	object->SetIsActive(false);
}

void TileCheck::DrawTile()
{
	if (!map->GetIsActive())
		return;

	//마우스 좌표  
	float mouseX = InputManager::GetInstance()->GetMouseWorldPosition().x - CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().x;
	float mouseY = -CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().y - InputManager::GetInstance()->GetMouseWorldPosition().y;

	index_X = (mouseX - (vTotal[0]->GetTransform()->GetPosition().x - TILEWIDTH / 2)) / TILEWIDTH + 1;
	index_Y = ((-1)*mouseY  +(vTotal[TILENUM_Y - 1]->GetTransform()->GetPosition().y - TILEWIDTH / 2)) / TILEHEIGHT - 2;

	//예외 처리 
	if (index_Y + index_X * TILENUM_Y < 0 || index_Y + index_X * TILENUM_Y > vTotal.size() - 1)
		return;
	if (mouseY > vTotal[TILENUM_Y-1]->GetTransform()->GetPosition().y + TILEHEIGHT / 2)
		return;
	if (index_X - dimension.x / 2 <= 0 || index_X + dimension.x / 2 >= TILENUM_X - 1)
		return;
	/*if (index_Y + dimension.y / 2 <= 0 || index_Y - dimension.y / 2 >= TILENUM_Y - 1)
		return;*/


	//타일 그려주기 
	for (int i = 0; i < dimension.x; i++)
	{
		for (int j = 0; j < dimension.y; j++)
		{
			auto tilePoly = vTemp[i * dimension.y + j]->GetComponent<PolygonDraw>();

			vTemp[i * dimension.y + j]->SetIsActive(true);
			tilePoly->GetTransform()->SetPosition(vTotal[(index_X - dimension.x / 2 + i) * TILENUM_Y + index_Y + dimension.y / 2 - j]->GetTransform()->GetPosition());
			tilePoly->SetDepth(4);


			if (vTotal[(index_X - dimension.x / 2 + i) * TILENUM_Y + index_Y + dimension.y / 2 - j]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL)
				tilePoly->SetColor(Color{ 1,0,0,1 });
			else
				tilePoly->SetColor(Color{ 0,1,0,1 });
		}
	}

	SetMouseIndex(Vector2(index_X, index_Y));
}

