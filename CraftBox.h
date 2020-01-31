#pragma once
#include "GgaetIp.h"

class CraftTimeBar;
class WorkArea;
class CraftBox : public Script
{
private:
	Object* _workArea;

	// 박스 몸체 관련
	Transform* _transform;
	Physics* _physics;
	Sprite* _sprite;
	BoxCollider* _boxCollider;

	CraftTimeBar* _timeBar;

	Object* _craftResult;

	// 박스에 텍스트 관련
	Object* _infoText;
	Text* _text;
	map<string, int> _mCraftResources;
	map<string, int>::iterator _miCraftResources;
	map<string, int> _mValidCraftResources;
	int _craftTime;


public:
	virtual void Init() override;
	virtual void Update() override;

	map<string, int> GetmCraftResources() { return _mCraftResources; }
	map<string, int> GetmValidCraftResources() { return _mValidCraftResources; }

	virtual void SetTimeBarLink(CraftTimeBar* c) { _timeBar = c; }

	void SetLink(Object* ob) { _workArea = ob; }

	float GetCraftTime() { return _craftTime; }
};