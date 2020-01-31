#include "stdafx.h"
#include "InfoBox.h"
#include "Building.h"
#include "BuildingInfo.h"
#include "InfoSpriteAndText.h"
#include "FixButton.h"

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

void InfoBox::Init()
{
	// InfoBox 관련
	_transform = object->GetTransform();
	_transform->SetPosition(Vector2(_building->GetTransform()->GetPosition().x, _building->GetTransform()->GetPosition().y + 270));

	object->AddComponent<BoxCollider>();
	
	// InfoBox의 정보 관련
	_mMaterial = _building->GetComponent<BuildingInfo>()->GetBuildingInfo()[_building->GetTag()].material;
	_time = _building->GetComponent<BuildingInfo>()->GetBuildingInfo()[_building->GetTag()].time;

	for (_miMaterial = _mMaterial.begin(); _miMaterial != _mMaterial.end(); _miMaterial++)
	{
		if (_miMaterial->second == 0) continue;
		_mValidResources.insert(pair<string, int>(_miMaterial->first, _miMaterial->second));
	}

	_sprite = object->AddComponent<Sprite>();
	_sprite->SetSprite(Image::CreateImage("Sprite/Need_" + to_string(_mValidResources.size()) + "K.png"));

	int i = 0;

	for (auto it : _mValidResources)
	{
		Object* infoSpriteAndText = Object::CreateObject(object);


		infoSpriteAndText->AddComponent<InfoSpriteAndText>();
		infoSpriteAndText->GetComponent<InfoSpriteAndText>()->SetResourceKey(it.first);

		infoSpriteAndText->GetComponent<InfoSpriteAndText>()
			->SetSpriteStartPos(Vector2(_sprite->GetTransform()->GetPosition().x + 170,  i * 50 - 52));


		infoSpriteAndText->GetComponent<InfoSpriteAndText>()
			->SetTextStartPos(Vector2( 50, -136 + i * 50));

		infoSpriteAndText->GetComponent<InfoSpriteAndText>()->SetLink(this);

		i++;
	}

	// 수리 버튼 관련
	Object* fixButton = Object::CreateObject();
	fixButton->AddComponent<FixButton>();
	fixButton->AddComponent<BoxCollider>();
	fixButton->GetComponent<BoxCollider>()->SetSize(Vector2(36, 18));
	fixButton->GetTransform()->SetPosition(Vector2(object->GetTransform()->GetPosition().x, 
		object->GetTransform()->GetPosition().y - 100));
	fixButton->GetComponent<FixButton>()->SetLink(_building);
}

void InfoBox::Update()
{

}