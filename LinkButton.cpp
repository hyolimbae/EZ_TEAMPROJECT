#include "stdafx.h"
#include "LinkButton.h"

void LinkButton::Init()
{
	object->AddComponent<BoxCollider>();
}

void LinkButton::Update()
{
	if (linked->GetIsActive() && InputManager::GetInstance()->GetKeyDown(VK_LBUTTON) &&
		!object->GetComponent<BoxCollider>()->PtInCollider(InputManager::GetInstance()->GetMousePosition()))
	{
		linked->SetIsActive(false);
	}
}

void LinkButton::OnMouseDown()
{
	linked->SetIsActive(!linked->GetIsActive());
}
