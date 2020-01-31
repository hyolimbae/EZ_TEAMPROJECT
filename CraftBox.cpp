#include "stdafx.h"
#include "CraftBox.h"
#include "CraftInfo.h"
#include "CraftSpriteAndText.h"
#include "CraftButton.h"
#include "CraftTimeBar.h"
#include "CraftResult.h"

void CraftBox::Init()
{
	object->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Material_Synthesis.png"));

	object->AddComponent<BoxCollider>();
	object->GetComponent<BoxCollider>()->SetSize(Vector2(200, 100));

	_transform = object->GetTransform();
	_sprite = object->GetComponent<Sprite>();
	_text = object->GetComponent<Text>();

	_transform->SetPosition(Vector2(0, 0));

	// i luv u >3< 
	_mCraftResources = _workArea->GetComponent<CraftInfo>()->GetMCraftInfo()[_workArea->GetTag()].material;
	_craftTime = _workArea->GetComponent<CraftInfo>()->GetMCraftInfo()[_workArea->GetTag()].time;

	for (_miCraftResources = _mCraftResources.begin(); _miCraftResources != _mCraftResources.end(); _miCraftResources++)
	{
		if (_miCraftResources->second == 0) continue;

		_mValidCraftResources.insert(pair<string, int>(_miCraftResources->first, _miCraftResources->second));
	}

	int i = 0;

	for (auto it : _mValidCraftResources)
	{
		Object* craftSpriteAndText = Object::CreateObject(object);
		craftSpriteAndText->SetTag(it.first);
		craftSpriteAndText->AddComponent<CraftSpriteAndText>();
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->SetResourceName(it.first);
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->
			SetMaterialSpriteStartPos(Vector2(_sprite->GetTransform()->GetPosition().x - 125 + i * 120,
				_sprite->GetTransform()->GetPosition().y + 10));
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->
			SetMaterialTextStartPos(Vector2(-90 + i * 120, -50));
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->SetLink(this);
		i++;
	}

	Object* craftbutton = Object::CreateObject(object);
	craftbutton->AddComponent<CraftButton>();
	craftbutton->AddComponent<BoxCollider>();
	craftbutton->GetComponent<BoxCollider>()->SetSize(Vector2(40, 20));
	craftbutton->GetTransform()->SetPosition(Vector2(0, -60));
	craftbutton->GetComponent<CraftButton>()->SetLink(_workArea);

	_craftResult = Object::CreateObject(object);
	_craftResult->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + object->GetTag() + ".png"));
	_craftResult->GetComponent<Sprite>()->GetTransform()->SetPosition(Vector2(120, 10));
	_craftResult->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 0.7f));
	_craftResult->GetComponent<Sprite>()->SetOpacity(0.2f);
	_craftResult->AddComponent<CraftResult>();
	_craftResult->GetComponent<CraftResult>()->Setlink(_timeBar);
	//_craftResult->AddComponent<Text>();
}

void CraftBox::Update()
{
	if (_timeBar->GetIsDone() && _timeBar->GetCraftState() == INTERVAL)
		_craftResult->GetComponent<Sprite>()->SetOpacity(1.f);
	else
		_craftResult->GetComponent<Sprite>()->SetOpacity(0.2f);
}