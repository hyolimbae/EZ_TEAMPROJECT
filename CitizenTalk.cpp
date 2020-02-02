#include "stdafx.h"
#include "CitizenTalk.h"

void CitizenTalk::Init()
{
	talk = Object::CreateObject(object);
	talk->GetTransform()->SetScale(Vector2(3, 3));
	talk->GetTransform()->SetPosition(Vector2(0, 80));
	talk->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/Empty_Bubble.png"));
	talk->GetComponent<Sprite>()->SetOpacity(0.f);

	talkText = Object::CreateObject(object);
	talkText->GetTransform()->SetDepth(10);
	talkText->GetTransform()->SetPosition(Vector2(7, 90));
	talkText->AddComponent<Text>()->CreateText(L" ¾È³çÇÏ¼¼¿ä ", L"¸¼Àº °íµñ", L"ko-KR", { 0,0,0,0 }, 12, 100, 40);

}

void CitizenTalk::Update()
{
	object->GetTransform()->SetPosition(citizen->GetTransform()->GetPosition());

	if (TimeManager::GetInstance()->GetTime() - stopTime > 2 && stopTime!=0)
	{
		citizen->SetIsActive(true);
		stopTime = 0;
		talkText->GetComponent<Text>()->SetColor({ 0,0,0,0 }, 0, 200);
		object->GetComponent<Sprite>()->SetOpacity(0.f);
		talk->GetComponent<Sprite>()->SetOpacity(0.f);
//		duration = TimeManager::GetInstance()->GetTime();
	}
}

void CitizenTalk::OnMouseDown()
{
	stopTime = TimeManager::GetInstance()->GetTime();

	if (stopTime - lastTime < 3 && stopTime - lastTime !=0)
		talkText->GetComponent<Text>()->ChangeText(L"¿Ö ¶Ç ºÎ¸£½ÃÁÒ?");
	else
		talkText->GetComponent<Text>()->ChangeText(L" ¾È³çÇÏ¼¼¿ä ");


	citizen->SetIsActive(false);
	object->GetComponent<Sprite>()->SetOpacity(1.f);
	talk->GetComponent<Sprite>()->SetOpacity(1.f);
	talkText->GetComponent<Text>()->SetColor({ 0,0,0,1 }, 0, 200);
	lastTime = TimeManager::GetInstance()->GetTime();

	
}
