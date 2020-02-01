#include "stdafx.h"
#include "VolumeBar.h"
#include "SettingPanel.h"

void VolumeBar::Init()
{
	_soundVolume = 1.0f;

	//볼륨바 길이 = 100 픽셀 
	_startVolumeBarPosX = _settingPanel->GetTransform()->GetPosition().x - 50;
	_maxVolumeBarPosX = _settingPanel->GetTransform()->GetPosition().x + 50;

	//볼륨바 전체 길이 
	_topVolumeBarLength = _maxVolumeBarPosX - _startVolumeBarPosX; 

	_topPolygonPos.push_back(Vector2(_startVolumeBarPosX, 0));
	_topPolygonPos.push_back(Vector2(_maxVolumeBarPosX, 0));

	_bottomPolygonPos.push_back(Vector2(_startVolumeBarPosX, 0));
	_bottomPolygonPos.push_back(Vector2(_maxVolumeBarPosX, 0));

	_polyDrawTop = Object::CreateObject(object);
	_polyDrawTop->AddComponent<PolygonDraw>();
	_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
	_polyDrawTop->GetComponent<PolygonDraw>()->SetStrokeWidth(7.f);
	_polyDrawTop->AddComponent<BoxCollider>();


	_polyDrawBotton = Object::CreateObject(object);
	_polyDrawBotton->AddComponent<PolygonDraw>();
	_polyDrawBotton->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);
	_polyDrawBotton->GetComponent<PolygonDraw>()->SetStrokeWidth(7.f);
	
	_topColor = { 0, 0, 0, 1 }; //검은색 
	_bottomColor = { 0.5, 0.5, 0.5, 1 }; //회색

	_polyDrawTop->GetComponent<PolygonDraw>()->SetColor(_topColor);
	_polyDrawBotton->GetComponent<PolygonDraw>()->SetColor(_bottomColor); 


	//볼륨조절버튼
	_volumeControlButton = Object::CreateObject(object);
	_volumeControlButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/volumeControlButton.png"));
	//볼륨조절버튼 생성 위치를 _polyDrawTop 끝 지점으로 설정 
	_volumeControlButton->GetTransform()->SetPosition(Vector2(_topPolygonPos[1].x, 0));

}

void VolumeBar::Update()
{
	//_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
	//_polyDrawBotton->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);

	////마우스 좌표 계산
	//auto mousePosition = InputManager::GetInstance()->GetMouseWorldPosition();
	//Vector3 mousePosition_V3 = Vector3(mousePosition.x, mousePosition.y, 1);
	//Vector3 mouseWorldPosition = Matrix3x3::Mul(mousePosition_V3, CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetLocalToWorldMatrix().GetInverseMatrix());

	//_mouseX = mouseWorldPosition.x;
	//_mouseY = (-1) * mouseWorldPosition.y;

	////a = 마우스 좌표에 따라 업데이트되는 볼륨바 길이
	//if (_topPolygonPos[1].x < _maxVolumeBarPosX) //포지션이 최대보다 커지면 안되니까 
	//{
	//	_topPolygonPos[1].x = (_mouseX - _topPolygonPos[0].x) / _topVolumeBarLength;
	//	cout << _topPolygonPos[1].x; 
	//}
	// 
	////_soundVolume = (a) / 탑 볼륨바 전체 길이
	//_soundVolume = _topPolygonPos[1].x / _topVolumeBarLength; 

}
