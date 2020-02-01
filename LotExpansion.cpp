#include "stdafx.h"
#include "LotExpansion.h"
#include "TileMap.h"
#include "ConfirmButton.h"
#include "Inventory.h"
#include "LinkButton.h"

void LotExpansion::Init()
{
	vTotal = map->GetComponent<TileMap>()->GetVTotal();


	for (int i = 0; i < 3; i++)
	{
		auto expansion = Object::CreateObject(object);
		auto drawCompo = expansion->AddComponent<PolygonDraw>();
		drawCompo->SetColor({ 0,1,0,0.4 });
		if (i > 0)
			drawCompo->SetColor({ 1,0,0,0.4 });
		expansion->SetIsActive(false);
		vExpansion.push_back(expansion);
	}

	for (int i = 0; i < 3; i++)
	{
		auto expansion = Object::CreateObject(object);
		auto drawCompo = expansion->AddComponent<PolygonDraw>();
		drawCompo->SetColor({ 0,1,0,0.7 });
		drawCompo->SetStrokeWidth(2);
		expansion->SetIsActive(false);
		vInfo.push_back(expansion);
	}

	auto textObj = Object::CreateObject();
	dimensionText = textObj->AddComponent<Text>();
	dimensionText->CreateText(L"", L"���� ���", L"ko-KR", { 0,1,0,0.7 }, 20, 300, 40);


	//CONFIRMATION WINDOW 
	confirmationWindow = Object::CreateObject();
	confirmationWindow->AddComponent<BoxCollider>();
	confirmationWindow->GetTransform()->SetScale(Vector2(1.5, 1.5));
	confirmationWindow->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/ExpansionConfirmWindow.png"));
	confirmationWindow->SetIsActive(false);
	
	auto linkButton = Object::CreateObject(confirmationWindow);
	linkButton->AddComponent<BoxCollider>()->SetSize(confirmationWindow->GetComponent<BoxCollider>()->GetSize());
	linkButton->AddComponent<LinkButton>()->SetLink(confirmationWindow);


	//CONFIRMATION TEXT
	auto confirmationTextObj = Object::CreateObject(confirmationWindow);
	confirmationText= confirmationTextObj->AddComponent<Text>();
	confirmationTextObj->GetTransform()->SetPosition(Vector2(160, -45));
	confirmationText->CreateText(L"", L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 15, 355, 40);

	//CONFIRMATION BUTTON 
	auto confirmationButton = Object::CreateObject(confirmationWindow);
	confirmationButton->AddComponent<BoxCollider>();
	confirmationButton->GetTransform()->SetPosition(Vector2(80, -40));
	confirmationButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/ExpansionConfirmButton.png"));
	confirmationButton->AddComponent<ConfirmButton>()->SetLinkToInventory(inventory);
	confirmationButton->GetComponent<ConfirmButton>()->SetLinkToWindow(confirmationWindow);

	testDirt = testStone = 100;
}

void LotExpansion::Update()
{
	DrawExpansion();

	if(InputManager::GetInstance()->GetKeyDown(VK_F2))
		map->GetComponent<TileMap>()->SetTileView(!map->GetComponent<TileMap>()->GetTileView());
}

void LotExpansion::OnMouseDown()
{
	if (confirmationWindow->GetIsActive())
		return;

	//���� ��ǥ ���� 
	float mouseX = InputManager::GetInstance()->GetMouseWorldPosition().x - CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().x;
	float mouseY = -CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().y - InputManager::GetInstance()->GetMouseWorldPosition().y;

	startIndex.x =  (int)(mouseX - (vTotal[0]->GetTransform()->GetPosition().x - TILEWIDTH / 2)) / TILEWIDTH ;
	startIndex.y = (int)(vTotal[0]->GetTransform()->GetPosition().y + TILEHEIGHT / 2 - mouseY) / TILEHEIGHT;

	//�߰ߵ� ���̶�� 
	/*if (vTotal[startIndex.x * TILENUM_Y + startIndex.y]->GetComponent<Tile>()->GetAttribute() != ATTRIBUTE::UNDISCOVERED)
		return;*/

	for (int i = 0; i < 3; i++)
	{
		vExpansion[i]->SetIsActive(true);
		vInfo[i]->SetIsActive(true);
		dimensionText->GetGameObject()->SetIsActive(true);
	}
		
}

void LotExpansion::OnMouseUp()
{
	if (CostCheck()&& vExpansion[0]->GetIsActive())
	{
		confirmationWindow->SetIsActive(true);
		confirmationText->ChangeText(to_wstring((int)(20*dimension.x*dimension.y)) + L"       " +
									 to_wstring((int)(20 *dimension.x * dimension.y)));
	}

	for (int i = 0; i < 3; i++)
	{
		vExpansion[i]->SetIsActive(false);
		vInfo[i]->SetIsActive(false);
		dimensionText->GetGameObject()->SetIsActive(false);
	}

}

void LotExpansion::DrawExpansion()
{
	if (!vExpansion[0]->GetIsActive())
		return;

	vector<Vector2> polyVertices;
	vector<Vector2> polyVertices_info;

	float mouseX = InputManager::GetInstance()->GetMouseWorldPosition().x - CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().x;
	float mouseY = -CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetPosition().y - InputManager::GetInstance()->GetMouseWorldPosition().y;

	//���� ���� - startpos 
	Vector2 startPos;
	startPos.x = vTotal[startIndex.x * TILENUM_Y + startIndex.y]->GetTransform()->GetPosition().x - TILEWIDTH / 2;
	startPos.y = vTotal[startIndex.x * TILENUM_Y + startIndex.y]->GetTransform()->GetPosition().y + TILEHEIGHT / 2;

	//���� ���� - endpos
	Vector2 endIndex;
	endIndex.x = (int)(mouseX - (vTotal[0]->GetTransform()->GetPosition().x - TILEWIDTH / 2)) / TILEWIDTH;
	endIndex.y = (int)(vTotal[0]->GetTransform()->GetPosition().y + TILEHEIGHT / 2 - mouseY) / TILEHEIGHT;

	Vector2 endPos;
	endPos.x = vTotal[endIndex.x * TILENUM_Y + endIndex.y]->GetTransform()->GetPosition().x + TILEWIDTH / 2;
	endPos.y = vTotal[endIndex.x * TILENUM_Y + endIndex.y]->GetTransform()->GetPosition().y - TILEHEIGHT / 2;

	polyVertices.push_back(Vector2(startPos.x,(startIndex.y - endIndex.y-2)*TILEHEIGHT/2 + startPos.y+ TILEHEIGHT/2));
	polyVertices.push_back(Vector2(endPos.x, (startIndex.y - endIndex.y-2) * TILEHEIGHT / 2 + startPos.y +TILEHEIGHT/2));

	vExpansion[0]->GetComponent<PolygonDraw>()->SetStrokeWidth((endIndex.y - startIndex.y+1)*TILEHEIGHT);
	vExpansion[0]->GetComponent<PolygonDraw>()->SetVertices(polyVertices);

	//Dimension update
	dimension = Vector2((int)abs(endIndex.x - startIndex.x + 1), (int)(abs(endIndex.y - startIndex.y + 1)));
	dimensionText->GetTransform()->SetPosition(Vector2(startPos.x + (endPos.x - startPos.x)/2+200, startPos.y - (startPos.y - endPos.y) / 2 + 50));
	dimensionText->ChangeText(to_wstring((int)dimension.x) + L" X " + to_wstring((int)(dimension.y)));


	//�ڽ�Ʈ�� �Ѿ�ٸ� 
	if (!CostCheck())
	{

		vExpansion[0]->GetComponent<PolygonDraw>()->SetColor({ 1,0,0,0.4 });
		polyVertices_info.push_back(startPos);
		polyVertices_info.push_back(Vector2(vTotal[maxIndex.x * TILENUM_Y + maxIndex.y]->GetTransform()->GetPosition().x + TILEWIDTH / 2,
											vTotal[maxIndex.x * TILENUM_Y + maxIndex.y]->GetTransform()->GetPosition().y - TILEHEIGHT / 2));
		vInfo[0]->GetComponent<PolygonDraw>()->SetVertices(polyVertices_info);


		//REDAREA - 1 (���߿�)
		vector<Vector2> redArea1;
		Vector2 startPos1 = Vector2(vTotal[(maxIndex.x+1) * TILENUM_Y + startIndex.y]->GetTransform()->GetPosition().x - TILEWIDTH / 2,
									vTotal[(maxIndex.x+1) * TILENUM_Y + startIndex.y]->GetTransform()->GetPosition().y + TILEHEIGHT / 2);

		Vector2 endPos1 =   Vector2(vTotal[endIndex.x * TILENUM_Y + endIndex.y]->GetTransform()->GetPosition().x + TILEHEIGHT / 2,
									vTotal[endIndex.x * TILENUM_Y + endIndex.y]->GetTransform()->GetPosition().y - TILEHEIGHT / 2);

		redArea1.push_back(Vector2(startPos1.x, startPos1.y + TILEHEIGHT/2));
		redArea1.push_back(Vector2(endPos1.x,   startPos1.y + TILEHEIGHT/2));

		vExpansion[1]->GetComponent<PolygonDraw>()->SetVertices(redArea1);
		vExpansion[1]->GetComponent<PolygonDraw>()->SetStrokeWidth((endIndex.y - startIndex.y + 1) * TILEHEIGHT);


		return;
	}
	else
	{

		vExpansion[0]->GetComponent<PolygonDraw>()->SetColor({ 0,1,0,0.4 });
		maxIndex = endIndex;
	}

	polyVertices_info.push_back(startPos);
	polyVertices_info.push_back(endPos);
	vInfo[0]->GetComponent<PolygonDraw>()->SetVertices(polyVertices_info);

}

bool LotExpansion::CostCheck()
{
	int dirtNeeded = dimension.x * dimension.y * 20;
	int stoneNeeded = dimension.x * dimension.y * 20;

	//���� �޾Ƽ� ���⼭ �� 
	if (testDirt >= dirtNeeded && testStone >= stoneNeeded)
		return true;
	
	return false;
}
