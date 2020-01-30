#pragma once
#include "Object.h"

class BuildingManager;

class Building abstract
{
protected:
	Object* _thisObj;

	Transform* _transform;
	Sprite* _sprite;
	PolygonDraw* _polydraw;
	BuildingManager* _buildingManager;

	bool _houseClicked;

public:
	Building(Object* obj);

	virtual void Init();
	virtual void Update() {};

	virtual void OnMouseDown();
	virtual void OnMouse();
	virtual void OnMouseExit();

	void SetLinkWithManager(BuildingManager* manager) { _buildingManager = manager; }
	BuildingManager* GetManager() { return _buildingManager; }
};