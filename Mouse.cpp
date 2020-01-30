#include "stdafx.h"
#include "Mouse.h"

void Mouse::Init()
{
	_transform = object->GetTransform();
	_sprite = object->GetComponent<Sprite>();
	_sprite->SetDepth(5);
	_sound = object->GetComponent<Sound>();

	_transform->SetAnchorPoint(Vector2(0,1));

}

void Mouse::Update()
{
	_transform->SetPosition((InputManager::GetInstance()->GetMouseWorldPosition() - DesignResolution/2) * Vector2(1,-1));

	ClickMotionAndSound();
}

void Mouse::ClickMotionAndSound()
{
	if (InputManager::GetInstance()->GetKeyDown(VK_LBUTTON))
	{
		_sound->Play();
	}

	if (InputManager::GetInstance()->GetKey(VK_LBUTTON))
	{
		_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Clicked.png"));
	}
	else
		_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Basic.png"));
}