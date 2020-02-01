#include "stdafx.h"
#include "VolumeBar.h"
#include "SettingPanel.h"

void VolumeBar::Init()
{
	_soundVolume = 1.0f;

	//������ ���� = 100 �ȼ� 
	_startVolumeBarPosX = _settingPanel->GetTransform()->GetPosition().x - 50;
	_maxVolumeBarPosX = _settingPanel->GetTransform()->GetPosition().x + 50;

	//������ ��ü ���� 
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
	
	_topColor = { 0, 0, 0, 1 }; //������ 
	_bottomColor = { 0.5, 0.5, 0.5, 1 }; //ȸ��

	_polyDrawTop->GetComponent<PolygonDraw>()->SetColor(_topColor);
	_polyDrawBotton->GetComponent<PolygonDraw>()->SetColor(_bottomColor); 


	//����������ư
	_volumeControlButton = Object::CreateObject(object);
	_volumeControlButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/volumeControlButton.png"));
	//����������ư ���� ��ġ�� _polyDrawTop �� �������� ���� 
	_volumeControlButton->GetTransform()->SetPosition(Vector2(_topPolygonPos[1].x, 0));

}

void VolumeBar::Update()
{
	//_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
	//_polyDrawBotton->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);

	////���콺 ��ǥ ���
	//auto mousePosition = InputManager::GetInstance()->GetMouseWorldPosition();
	//Vector3 mousePosition_V3 = Vector3(mousePosition.x, mousePosition.y, 1);
	//Vector3 mouseWorldPosition = Matrix3x3::Mul(mousePosition_V3, CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetLocalToWorldMatrix().GetInverseMatrix());

	//_mouseX = mouseWorldPosition.x;
	//_mouseY = (-1) * mouseWorldPosition.y;

	////a = ���콺 ��ǥ�� ���� ������Ʈ�Ǵ� ������ ����
	//if (_topPolygonPos[1].x < _maxVolumeBarPosX) //�������� �ִ뺸�� Ŀ���� �ȵǴϱ� 
	//{
	//	_topPolygonPos[1].x = (_mouseX - _topPolygonPos[0].x) / _topVolumeBarLength;
	//	cout << _topPolygonPos[1].x; 
	//}
	// 
	////_soundVolume = (a) / ž ������ ��ü ����
	//_soundVolume = _topPolygonPos[1].x / _topVolumeBarLength; 

}
