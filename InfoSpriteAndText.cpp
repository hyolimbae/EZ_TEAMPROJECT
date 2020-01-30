#include "stdafx.h"
#include "InfoSpriteAndText.h"
#include "InfoBox.h"

void InfoSpriteAndText::Init()
{
	 _mInfo = _infoBox->GetMValidResources();
	 _miInfo = _infoBox->GetMiValidResources();

	 Object* infoSprite = Object::CreateObject(object->GetParent());
	 _sprite = infoSprite->AddComponent<Sprite>();
	 _sprite->SetSprite(Image::CreateImage("Sprite/Need_" + _resourceKey + ".png"));
	 _sprite->GetTransform()->SetPosition(_spriteStartPos);

	 string rAmount = to_string(_mInfo[_resourceKey]);
	 wstring _resourceKeyW;
	 _resourceKeyW.assign(rAmount.begin(), rAmount.end());

	 Object* infoText = Object::CreateObject(object->GetParent());
	 _text = infoText->AddComponent<Text>();
	 _text->CreateText(_resourceKeyW, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 20, 50, 100);
	 _text->GetTransform()->SetPosition(_textStartPos);
	 _text->SetAnchorPoint(AnchorPoint::LeftTop);
}

void InfoSpriteAndText::Update()
{
	
}  