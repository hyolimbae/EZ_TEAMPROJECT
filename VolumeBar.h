#pragma once
#include "GgaetIp.h"

 

class VolumeBar : public Script
{
private:

	float _soundVolume;
	float _mouseX; 
	float _mouseY; 

	float _startVolumeBarPosX; 
	float _maxVolumeBarPosX;
	float _topVolumeBarLength; 
	
	Object* _settingPanel;

	//volume Bar용 PolyDraw
	//꼭지점을 담는 벡터. 이 꼭지점들을 이어준다. 
	//선 담을거라서 시작지점, 끝지점 설정하고 이 두 점을 잇게 벡터로 담아두는 것
	vector<Vector2> _topPolygonPos;
	vector<Vector2> _bottomPolygonPos;

	Object* _polyDrawTop;
	Object* _polyDrawBotton;
	Object* _volumeControlButton; 

	/*PolygonDraw* _polyDrawTop;
	PolygonDraw* _polyDrawBottom; */

	Color _topColor;
	Color _bottomColor;

public: 

	virtual void Init() override; 
	virtual void Update() override; 

	//Link
	void SetLinkWithSettingPanel(Object* ob) { _settingPanel = ob; }
	//Getter
	float GetSoundVolume() { return _soundVolume; }
};

