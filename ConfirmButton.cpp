#include "stdafx.h"
#include "ConfirmButton.h"



void ConfirmButton::OnMouseDown()
{
	object->GetTransform()->SetScale(Vector2(0.9,0.9));
}

void ConfirmButton::OnMouseUp()
{
	//�κ��丮 ó�� 
	object->GetTransform()->SetScale(Vector2(1, 1));
	window->SetIsActive(false);
}
