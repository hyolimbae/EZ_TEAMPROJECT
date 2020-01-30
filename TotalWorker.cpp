#include "stdafx.h"
#include "TotalWorker.h"
#include "WorkerControl.h"
#include "ShowWorker.h"

void TotalWorker::Init()
{
	_sprite = object->GetComponent<Sprite>();

	_totalWorkerText = Object::CreateObject();
	_totalWorkerText->AddComponent<Text>();
	_totalWorkerText->GetComponent<Text>()->CreateText(to_wstring(_totalNum),
		L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
	_totalWorkerText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(- 150, 400));
}


void TotalWorker::Update()
{
	_totalWorkerText->GetComponent<Text>()->ChangeText(to_wstring(_totalNum));
}

void TotalWorker::OnMouseStay()
{
	_sprite->GetTransform()->SetScale(Vector2(0.98f, 0.98f));
}

void TotalWorker::OnMouseDown()
{
	_showWorker->SetIsActive(!_showWorker->GetIsActive());
	//cout << "눌렀다.\n";
}

void TotalWorker::OnMouseUp()
{
	_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f));
}

#pragma region 안쓰는 것들

/*if (_showWorker->GetIsActive())
		_showWorker->SetIsActive(false);*/
		/*else if (!_showWorker->GetIsActive()) _showWorker->SetIsActive(true);*/


//해당 컴포넌트 이미지를 클릭했다는 신호 받아오면 ShowWorker 패널 켜기
//_totalWorkerText->AddComponent<ShowWorker>(); 


//if (_showWorker->GetIsActive() && InputManager::GetInstance()->GetKeyDown(VK_LBUTTON) &&
//	!object->GetComponent<BoxCollider>()->PtInCollider(InputManager::GetInstance()->GetMousePosition()))
//{
//	_showWorker->SetIsActive(false);

//	cout << "눌렀다.\n";
//}
#pragma endregion