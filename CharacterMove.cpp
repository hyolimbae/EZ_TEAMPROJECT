#include "stdafx.h"
#include "CharacterMove.h"

void CharacterMove::Init()
{
	animator = object->GetComponent<Animator>();
	sprite = object->GetComponent<Sprite>();
}

void CharacterMove::Update()
{
	int moveDirection = 0;

	//���� �� ��ü�� �� �̹���(SPRITE)���� ������ ������ 
	//�� SPRITE�� ������(��. SIZE, FLIP)�� ���ϰ� �����
	//�̹����� �ٲٴ��� �� �������� �����ȴ�.
	//�� �̹��� ��ü�� �������� �����°� �ƴ϶�
	//��ü ��ü�� �̹����� ������ ������ 



	//LEFT�� RIGHT�� ���� ������ 0�� �����⶧���� IDLE
	//LEFT�� RIGHT�� ������ 0�� �ƴ϶� MOVE
	if (InputManager::GetInstance()->GetKey(VK_LEFT) )
	{
		sprite->SetFlip(true);
		moveDirection -= 1;
	}
	if (InputManager::GetInstance()->GetKey(VK_RIGHT))
	{
		sprite->SetFlip(false);
		moveDirection += 1;
	}

	//SPACE�� ������ ���� ������ TRUE�� ����� �װ� �ƴ϶�� 
	//FALSE 
	if (InputManager::GetInstance()->GetKey(VK_SPACE))
	{
		animator->SetParameter("Jump", true);
	}
	else
	{
		animator->SetParameter("Jump", false);
	}

	animator->SetParameter("Run", moveDirection);
}