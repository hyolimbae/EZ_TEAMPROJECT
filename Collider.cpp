#include "stdafx.h"
#include "GgaetIp.h"

Collider::Collider()
{
	filter.maskBits = 0xFFFF;
	filter.categoryBits = 0x0001;
}

b2Body* Collider::GetBody()
{
	return body;
}

void Collider::Update()
{
	if (!object->GetIsActive())
		return;
	Vector2 mousePosition = InputManager::GetInstance()->GetMousePosition();
	if (PtInCollider(mousePosition) && InputManager::GetInstance()->GetKeyDown(VK_LBUTTON))
		OnMouseDown();
	else if (PtInCollider(mousePosition))
	{
		OnMouse();
		isColliding = true;
	}
	else if (isColliding)
	{
		OnMouseExit();
		isColliding = false;
	}

	if (PtInCollider(mousePosition) && InputManager::GetInstance()->GetKeyUp(VK_LBUTTON))
		OnMouseUp();
}
void Collider::Awake()
{
	transform = object->GetTransform();
}

void Collider::Init()
{
	physicsComponent = object->GetComponent<Physics>();
}

void Collider::OnMouseDown()
{
	for (auto c : transform->GetGameObject()->GetComponents<Script>())
		c->OnMouseDown();
}

void Collider::OnMouse()
{
	for (auto c : transform->GetGameObject()->GetComponents<Script>())
		c->OnMouse();
}

void Collider::OnMouseUp()
{
	for (auto c : transform->GetGameObject()->GetComponents<Script>())
		c->OnMouseUp();
}

void Collider::OnMouseExit()
{
	for (auto c : transform->GetGameObject()->GetComponents<Script>())
		c->OnMouseExit();
}

void Collider::SetFilter(b2Filter _filter)
{
	filter = _filter;
	if (fixture)
		fixture->SetFilterData(filter);
}

void Collider::Release()
{
	if (physicsComponent)
		physicsComponent->SetBody(nullptr);
	Component::Release();
}