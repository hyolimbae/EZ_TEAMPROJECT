#include "stdafx.h"
#include "TileMap.h"
#include "TilePick.h"

void TileMap::Init()
{
	vector<Vector2> pos;

	//ISOMETRIC
	//pos.push_back(Vector2(TILEWIDTH / 2, 0));
	//pos.push_back(Vector2(0, TILEHEIGHT / 2));
	//pos.push_back(Vector2(-TILEWIDTH / 2, 0));
	//pos.push_back(Vector2(0, -TILEHEIGHT / 2));
	//
	//for (int i = 0; i < TILENUM_X; i++)
	//{
	//	for (int j = 0; j < TILENUM_Y; j++)
	//	{
	//		Object* normalTile = Object::CreateObject();
	//		normalTile->GetTransform()->SetPosition(Vector2(i * TILEWIDTH / 2 - j * TILEWIDTH / 2, TILEHEIGHT * TILENUM_Y / 2 - i * TILEHEIGHT / 2 - j * TILEHEIGHT / 2));
	//		normalTile->SetName("Normal");
	//		auto tile = normalTile->AddComponent<Tile>();
	//		tile->SetIndex(Vector2(i, j));
	//		tile->SetAttribute(ATTRIBUTE::NONE);
	//		auto tilePoly = normalTile->AddComponent<PolygonDraw>();
	//		tilePoly->SetVertices(pos);
	//		tilePoly->SetStrokeWidth(2);

	//		vTotal.push_back(normalTile);

	//	}
	//}
	//

	//GENERAL

	testInfo a = { .name = "", .g = 1 };
	pos.push_back(Vector2(-TILEWIDTH/2, TILEHEIGHT/2));
	pos.push_back(Vector2(TILEWIDTH/2, TILEHEIGHT/2));
	pos.push_back(Vector2(TILEWIDTH/2, -TILEHEIGHT/2));
	pos.push_back(Vector2(-TILEHEIGHT/2, -TILEHEIGHT/2));


	for (int i = 0; i < TILENUM_X; i++)
	{
		for (int j = 0; j < TILENUM_Y; j++)
		{
			Object* normalTile = Object::CreateObject(object);
			normalTile->GetTransform()->SetPosition(Vector2(-250 + i*TILEWIDTH, +250 - j*TILEHEIGHT));
			
			normalTile->SetName("Normal");
			auto tile = normalTile->AddComponent<Tile>();
			tile->SetIndex(Vector2(i, j));


			////test
		/*	if (i > 2 && j>=5 && j<7)
			{
				normalTile->SetName("Wall");

				tile->SetAttribute(ATTRIBUTE::WALL);
				auto tilePoly = normalTile->AddComponent<PolygonDraw>();
				tilePoly->SetDepth((int)ZORDER::TILE);
				tilePoly->SetVertices(pos);
				tilePoly->SetStrokeWidth(1);
				tilePoly->SetColor(Color{ 0,0,1,0.7 });
				vTotal.push_back(normalTile);

				continue;
			}*/

			tile->SetAttribute(ATTRIBUTE::NONE);
			auto tilePoly = normalTile->AddComponent<PolygonDraw>();
			tilePoly->SetDepth((int)ZORDER::TILE);
			tilePoly->SetVertices(pos);
			tilePoly->SetStrokeWidth(1);
			tilePoly->SetColor(Color{ 1,1,1,0.7 });

			vTotal.push_back(normalTile);

		}
	}


	//테스트 코드  
	testInfo infoNone;
	infoNone.r = infoNone.g = infoNone.b = 1;
	infoNone.depth = 1;
	infoNone.name = "None";

	testInfo infoWall;
	infoWall.r = infoWall.b = 0;
	infoWall.g = 1;
	infoWall.depth = 2;
	infoWall.name = "Wall";

	testInfo infoPlayer;
	infoPlayer.r = infoPlayer.b = 1;
	infoPlayer.b = 0;
	infoPlayer.depth = 4;
	infoPlayer.name = "Player";

	testInfo infoEnemy;
	infoEnemy.r = infoEnemy.g = 0;
	infoEnemy.b = 1;
	infoEnemy.depth = 4;
	infoEnemy.name = "Enemy";

	attributeInfo.insert(make_pair(ATTRIBUTE::NONE, infoNone));
	attributeInfo.insert(make_pair(ATTRIBUTE::WALL,infoWall));
	attributeInfo.insert(make_pair(ATTRIBUTE::PLAYER, infoPlayer));
	attributeInfo.insert(make_pair(ATTRIBUTE::ENEMY, infoEnemy));


}

void TileMap::Update()
{
	//if (InputManager::GetInstance()->GetKeyDown(VK_RETURN))
		//tilePick->SetIsActive(false);
}

void TileMap::SetTile(Vector2 index, ATTRIBUTE attribute)
{         
	auto tile = vTotal[index.x * TILENUM_Y + index.y]->GetComponent<Tile>();
	auto tilePoly = vTotal[index.x * TILENUM_Y + index.y]->GetComponent<PolygonDraw>();
	tile->SetAttribute(attribute);

	//테스트 코드 
	vTotal[index.x * TILENUM_Y + index.y]->SetName(attributeInfo[attribute].name);
	tilePoly->SetColor(Color{attributeInfo[attribute].r,attributeInfo[attribute].g,attributeInfo[attribute].b,1});
	tilePoly->SetDepth(attributeInfo[attribute].depth);
}
