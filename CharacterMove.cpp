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

	//이제 한 객체는 한 이미지(SPRITE)만을 가지기 때문에 
	//이 SPRITE의 변수값(예. SIZE, FLIP)을 변하게 만들면
	//이미지를 바꾸더라도 이 변수값은 유지된다.
	//즉 이미지 자체가 변수값을 가지는게 아니라
	//객체 자체가 이미지용 변수를 가진다 



	//LEFT와 RIGHT을 같이 누르면 0이 나오기때문에 IDLE
	//LEFT나 RIGHT를 누르면 0이 아니라서 MOVE
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

	//SPACE를 누르면 점프 조건을 TRUE로 만들고 그게 아니라면 
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