#include "stdafx.h"
#include "PlayerGame.h"




void PlayerGame::Init()
{
	//nowScene���� Ŭ������ �� Zoom In�� �Ǹ� ������ �����ϰԲ� ī�޶� ��������
	if (_house->GetInPutKey() == true)
	{
		_isGameStart = true;
	}

	if (_house->GetInPutKey() == false)
	{
		_isGameStart = false;
	}
}

void PlayerGame::Update()
{
	if (_isGameStart == true)
	{
		//�������� �����ϴ� �ð����� �ΰ� Ÿ�̸Ӹ� �ٱ��? 
		//fallingItem(); 

	}

	//�÷��� ���̸� bool���� �Է� --> bool���� ������ //nowScene���� Ŭ������ �� Zoom In�� ��� 
	//{
		//fallingItem -->������ �������� Ŭ���� �ҷ����� bulletFire(); 
		//SetIcon(); 

		//ChooseItem(); --> �÷��̾ ������ �����ϱ� 
		//ChooseItem(); --> �÷��̾� �����۰� falling item�� ������ ��


		//���� ���� ��� 
	
	//--> �ٽ� falling Item(); 
	//}

	//�÷��� ���� �ƴ� �� --> ���Ϳ� ������ �� �߸��� ������ �ϸ� ���� ���� --> zoom out
}



void PlayerGame::SetIcon()
{
	//��ư�� ������ �����ؼ� setopacity 


	//Air->GetTransform()->SetPosition(Vector2(50, -70));
	//Air->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Air.png"));
	//Air->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));

	//Water->GetTransform()->SetPosition(Vector2(-10, -150));
	//Water->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Water.png"));
	//Water->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));

	//Wood->GetTransform()->SetPosition(Vector2(110, -150));
	//Wood->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Wood.png"));
	//Wood->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));

}


void PlayerGame::ChooseItem()
{
}

void PlayerGame::Result()
{
}
