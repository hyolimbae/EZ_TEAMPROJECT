#include "stdafx.h"
#include "NotificationBox.h"

void NotificationBox::Init()
{
	object->GetTransform()->SetPosition(Vector2(0,200));
	sprite = object->AddComponent<Sprite>();
	sprite->SetOpacity(0.f);
	sprite->SetSprite(Image::CreateImage("Sprite/NotificationBox.png"));
	sprite->GetTransform()->SetScale(Vector2(0.5, 0.5));
	//sprite->SetDepth((int)ZORDER::UI);

	//��ǥ������ �� OBJ�� CHILD�� ��� 
	auto textChild = Object::CreateObject(object);
	text = textChild->AddComponent<Text>();
	text->CreateText(L"üũ", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,0 }, 30, 400, 40);
	text->GetTransform()->SetPosition(text->GetTransform()->GetPosition() + Vector2(-60, -2));
	text->SetAnchorPoint(AnchorPoint::LeftCenter);
	//text->SetDepth((int)ZORDER::UI);
}

void NotificationBox::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::NOTIFICATION)
		return;

	sprite->SetOpacity(1.f);
	text->ChangeText(string_to_wstring(event));
	SetTextOpacity(1.f);
	alphaTime = TimeManager::GetInstance()->GetTime();
	isNotified = true;
}

void NotificationBox::Update()
{
	//�ΰ��� ���ÿ� ���ö� ���� ��Ȳó�� ����� �ҵ� 
	FadeOut();
}

void NotificationBox::FadeOut()
{
	if (!isNotified || TimeManager::GetInstance()->GetTime() - alphaTime < 1)
		return;

	sprite->SetOpacity(sprite->GetOpacity() - 0.01f);
	SetTextOpacity(GetTextOpacity() - 0.01f);

	if (!sprite->GetOpacity())
		isNotified = true;
	
}

void NotificationBox::SetTextOpacity(float alpha)
{
	text->SetColor(Color{ 1,1,1,alpha }, 0, 400);
	textOpacity = alpha;
}

