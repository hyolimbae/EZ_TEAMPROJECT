#pragma once
#include "GgaetIp.h"
class LotExpansion: public Script
{
private:
	Object* map;
	vector<Object*> vTotal;
	vector<Object*> vExpansion;
	vector<Object*> vInfo;

	Text* dimensionText;
	Vector2 dimension;
	Vector2 startIndex;
	Vector2 maxIndex;	

	Object* confirmationWindow;

	int testDirt;
	int testStone;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

	void DrawExpansion();
	bool CostCheck();
	void SetLinkToMap(Object* map) { this->map = map; }
};

