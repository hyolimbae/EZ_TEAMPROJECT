#include "stdafx.h"
#include "UI_ClickButton.h"
#include "WorkerControl.h"


void UI_ClickButton::Init()
{
	_sprite = object->GetComponent<Sprite>(); 
	//_isClicked = false; 
	collider = object->GetComponent<Collider>();
}

void UI_ClickButton::Update()
{
	//_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f));
	//if (!_isClicked) return;

	if(InputManager::GetInstance()->GetKeyUp(VK_LBUTTON))
		_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f));
}
//�⺻ ������ ���� ������ �ʱ� ������ ���� 

 
void UI_ClickButton::OnMouseStay()
{
	//_sprite->GetTransform()->SetScale(Vector2(0.9f, 0.9f)); //���콺 down ������ ���� ���� �� �۾����� 
}

void UI_ClickButton::OnMouseDown()
{
	if (_sprite)
	{
		_sprite->GetTransform()->SetScale(Vector2(0.9f, 0.9f));
	}
	
	if ((_workerControl->GetTotalPopulation() >= 0) && 
		(_workerControl->GetTotalPopulation() < 50))
	{
		if (object->GetTag() == "Button_Plus")
		{
			string b = object->GetName();
			_workerControl->PlusPopulation(object->GetName());
		}
		else if (object->GetTag() == "Button_Minus")
		{
			_workerControl->MinusPopulation(object->GetName());
		}
	}
}


void UI_ClickButton::OnMouseUp()
{
	//_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f)); //��ư ���� ������
}