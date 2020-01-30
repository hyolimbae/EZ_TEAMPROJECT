#include "stdafx.h"
#include "TilePick.h"
#include "TileMap.h"

void TilePick::Init()
{
	vTotal = map->GetVTotal();
}

void TilePick::OnMouseDown()
{
	//���콺 ��ǥ  
	float mouseX = InputManager::GetInstance()->GetMouseWorldPosition().x - CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().x;
	float mouseY = -CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().y - InputManager::GetInstance()->GetMouseWorldPosition().y;

	Vector2 pointZero = Vector2(vTotal[0]->GetTransform()->GetPosition().x, vTotal[0]->GetTransform()->GetPosition().y + TILEHEIGHT / 2);

	//���� 1, 2 ���� 
	float vSlope = (pointZero.y - vTotal[TILENUM_Y - 1]->GetTransform()->GetPosition().y) / (pointZero.x - (vTotal[TILENUM_Y - 1]->GetTransform()->GetPosition().x - TILEWIDTH / 2));
	float hSlope = (-1) * vSlope;

	//���� 1,2 intercept 
	float vIntercept = pointZero.y - vSlope * pointZero.x;
	float hIntercept = pointZero.y - hSlope * pointZero.x;

	//������ ���Ⱑ ���� ���콺 ��ǥ�� �������� �� 1,2�� intercept
	float my_vIntercept = mouseY - vSlope * mouseX;
	float my_hIntercept = mouseY - hSlope * mouseX;

	//������ �� �� ���� ������ 
	Vector2 vIntersect, hIntersect;
	vIntersect.x = (hIntercept - my_vIntercept) / (vSlope - hSlope);
	vIntersect.y = vSlope * vIntersect.x + my_vIntercept;
	hIntersect.x = (vIntercept - my_hIntercept) / (hSlope - vSlope);
	hIntersect.y = hSlope * hIntersect.x + my_hIntercept;

	int index_Y = sqrt((vIntersect.x - mouseX) * (vIntersect.x - mouseX) + (vIntersect.y - mouseY) * (vIntersect.y - mouseY)) /
		sqrt(TILEWIDTH * TILEWIDTH / 4 + TILEHEIGHT * TILEHEIGHT / 4);
	int index_X = sqrt((hIntersect.x - mouseX) * (hIntersect.x - mouseX) + (hIntersect.y - mouseY) * (hIntersect.y - mouseY)) /
		sqrt(TILEWIDTH * TILEWIDTH / 4 + TILEHEIGHT * TILEHEIGHT / 4);

	vTotal[index_Y + index_X * TILENUM_Y]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::WALL);
	auto poly = vTotal[index_Y + index_X * TILENUM_Y]->GetComponent<PolygonDraw>();
	poly->SetColor(Color{ 0,1,0,1 });
	poly->SetDepth(4);
}
