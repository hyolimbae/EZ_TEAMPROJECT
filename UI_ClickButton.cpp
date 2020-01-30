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
//기본 상태일 때는 사이즈 초기 설정과 같게 

 
void UI_ClickButton::OnMouseStay()
{
	//_sprite->GetTransform()->SetScale(Vector2(0.9f, 0.9f)); //마우스 down 상태일 때는 조금 더 작아지게 
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
	//_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f)); //버튼 원래 사이즈
}