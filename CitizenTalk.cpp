#include "stdafx.h"
#include "CitizenTalk.h"

void CitizenTalk::Init()
{
	talk = Object::CreateObject(object);
	talk->GetTransform()->SetPosition(Vector2(0, 80));
	talk->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/Brick_Bubble.png"));
	talk->GetComponent<Sprite>()->SetOpacity(0.f);
}

void CitizenTalk::Update()
{
	object->GetTransform()->SetPosition(citizen->GetTransform()->GetPosition());

	if (TimeManager::GetInstance()->GetTime() - stopTime > 2 && stopTime!=0)
	{
		citizen->SetIsActive(true);
		stopTime = 0;
		object->GetComponent<Sprite>()->SetOpacity(0.f);
		talk->GetComponent<Sprite>()->SetOpacity(0.f);
	}
}

void CitizenTalk::OnMouseDown()
{
	stopTime = TimeManager::GetInstance()->GetTime();
	citizen->SetIsActive(false);
	object->GetComponent<Sprite>()->SetOpacity(1.f);
	talk->GetComponent<Sprite>()->SetOpacity(1.f);


}
