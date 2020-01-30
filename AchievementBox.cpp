#include "stdafx.h"
#include "AchievementBox.h"

void AchievementBox::Init()
{
	box = object->AddComponent<Sprite>();
	box->SetSprite(Image::CreateImage("Sprite/AchievementBox.png"));
	
	auto bar = Object::CreateObject(object);
	progressBar = bar->AddComponent<Sprite>();
	progressBar->SetSprite(Image::CreateImage("Sprite/ProgressBar.png"));
	progressBar->GetTransform()->SetScaleX(0.f);
	bar->GetTransform()->SetPosition(Vector2(-67, 166));
	progressBar->GetTransform()->SetAnchorPoint(Vector2(0, 0.5));

	/*auto trophyobj = Object::CreateObject(object);
	trophy = trophyobj->AddComponent<Sprite>();
	trophy->SetSprite(Image::CreateImage("Sprite/trophy_gold.png"));
	trophyobj->GetTransform()->SetPosition(Vector2(-105, 190));
	trophy->SetOpacity(0.1f);*/

	auto titleText = Object::CreateObject(object);
	title = titleText->AddComponent<Text>();
	title->GetTransform()->SetPosition(Vector2(16, -50));
	title->CreateText(text.first, L"¸¼Àº °íµñ", L"ko-KR", { 0,0,0,1}, 18, 400, 40);
	title->SetAnchorPoint(AnchorPoint::Center);

	auto contentText = Object::CreateObject(object);
	content = contentText->AddComponent<Text>();
	content->GetTransform()->SetPosition(Vector2(16, -70));
	content->CreateText(text.second, L"¸¼Àº °íµñ", L"ko-KR", { 0,0,0,1 }, 13, 400, 40);
	content->SetAnchorPoint(AnchorPoint::Center);

	auto ratioText = Object::CreateObject(object);
	ratio = ratioText->AddComponent<Text>();
	ratio->GetTransform()->SetPosition(Vector2(16, -87));
	ratio->CreateText(to_wstring(currentNum)+L"/"+to_wstring(notifyNum), L"¸¼Àº °íµñ", L"ko-KR", { 1,1,1,1 }, 14, 400, 40);
	ratio->SetAnchorPoint(AnchorPoint::Center);
	//ratio->SetDepth((int)ZORDER::UI);

	auto trophyobj = Object::CreateObject(object);
	trophy = trophyobj->AddComponent<Sprite>();
	trophy->SetSprite(Image::CreateImage("Sprite/trophy_gold.png"));
	trophyobj->GetTransform()->SetPosition(Vector2(-105, 190));
	trophy->SetOpacity(0.1f);

}

void AchievementBox::SetProgress()
{
	if (trophy->GetOpacity() == 1.0f)
		return;
	currentNum++;
	if (notifyNum == currentNum)
		trophy->SetOpacity(1.f);
	progressBar->GetTransform()->SetScaleX((float)currentNum / (float)notifyNum);
	ratio->ChangeText(to_wstring(currentNum) + L"/" + to_wstring(notifyNum));
	ratio->SetAnchorPoint(AnchorPoint::Center);

}
