#include "stdafx.h"
#include "Character.h"

void Character::Init()
{
	tileMap = map->GetComponent<TileMap>();
	vTotal = tileMap->GetVTotal();

	tileMap->SetTile(Vector2(index.x, index.y), ATTRIBUTE::PLAYER);

}

void Character::Update()
{
	KeyControl();
}

void Character::KeyControl()
{
	
	if (InputManager::GetInstance()->GetKeyDown(VK_UP))
	{
		//���� ó�� 
		if (index.y == 0)
			return;
		if (vTotal[index.x * TILENUM_Y + index.y - 1]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL)
			return;

		tileMap->SetTile(Vector2(index.x, index.y - 1), ATTRIBUTE::PLAYER);
		tileMap->SetTile(Vector2(index.x, index.y), ATTRIBUTE::NONE);

		index = Vector2(index.x, index.y - 1);
	}
	if (InputManager::GetInstance()->GetKeyDown(VK_DOWN))
	{
		//���� ó�� 
		if (index.y == TILENUM_Y-1)
			return;
		if (vTotal[index.x * TILENUM_Y + index.y + 1]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL)
			return;

		tileMap->SetTile(Vector2(index.x, index.y + 1), ATTRIBUTE::PLAYER);
		tileMap->SetTile(Vector2(index.x, index.y), ATTRIBUTE::NONE);

		index = Vector2(index.x, index.y + 1);
	}
	if (InputManager::GetInstance()->GetKeyDown(VK_RIGHT))
	{
		//���� ó�� 
		if (index.x == TILENUM_X - 1)
			return;
		if (vTotal[(index.x+1) * TILENUM_Y + index.y]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL)
			return;

		tileMap->SetTile(Vector2(index.x+1, index.y), ATTRIBUTE::PLAYER);
		tileMap->SetTile(Vector2(index.x, index.y), ATTRIBUTE::NONE);

		index = Vector2(index.x+1, index.y);
	}
	if (InputManager::GetInstance()->GetKeyDown(VK_LEFT))
	{
		//���� ó�� 
		if (index.x == 0)
			return;
		if (vTotal[(index.x - 1) * TILENUM_Y + index.y]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL)
			return;

		tileMap->SetTile(Vector2(index.x - 1, index.y), ATTRIBUTE::PLAYER);
		tileMap->SetTile(Vector2(index.x, index.y), ATTRIBUTE::NONE);

		index = Vector2(index.x - 1, index.y);
	}
}

