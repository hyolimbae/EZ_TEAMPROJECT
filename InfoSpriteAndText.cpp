#include "stdafx.h"
#include "InfoSpriteAndText.h"
#include "InfoBox.h"
/*�����������������*/        #include "FixButton.h"

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

    /*�����������������*/         _mNeededResources = _fixButton->GetMNeededResources();
    /*�����������������*/         string rAmount2 = to_string(_mNeededResources[_resourceKey]);
    /*�����������������*/         wstring _resourceKeyW2;
    /*�����������������*/         _resourceKeyW2.assign(rAmount2.begin(), rAmount2.end());
    /*�����������������*/
    /*�����������������*/         Object* invenStatusText = Object::CreateObject(object->GetParent());
    /*�����������������*/         invenStatusText->AddComponent<Text>();
    /*�����������������*/         invenStatusText->GetComponent<Text>()->CreateText(_resourceKeyW2, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 20, 50, 100);
    /*�����������������*/         invenStatusText->GetTransform()->SetPosition(Vector2(_textStartPos.x - 50, _textStartPos.y));
    /*�����������������*/         invenStatusText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftTop);
    /*�����������������*/
    /*�����������������*/         Color green = { 0.f, 1.f, 0.2f, 1.f };
    /*�����������������*/         Color red = { 1.f, 0.2f, 0.2f, 1.f };
    /*�����������������*/
    /*�����������������*/         if (_mNeededResources[_resourceKey] >= _mInfo[_resourceKey])
        /*�����������������*/ {
        /*�����������������*/            invenStatusText->GetComponent<Text>()->SetColor(green, 0, 3);
        /*�����������������*/
    }
    /*�����������������*/         else
        /*�����������������*/ {
        /*�����������������*/            invenStatusText->GetComponent<Text>()->SetColor(red, 0, 3);
        /*�����������������*/
    }
}

void InfoSpriteAndText::Update()
{

}