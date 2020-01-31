#pragma once
#include "Object.h"

class BuildingManager;

enum BUILDINGTYPE
{
	DEFAULT,
	NEW,
	ROAD
};

class Building abstract
{
protected:
	Object* _thisObj;
	
	Transform* _transform;
	Sprite* _sprite;
	PolygonDraw* _polydraw;
	BuildingManager* _buildingManager;

	BUILDINGTYPE buildingType = DEFAULT;
	bool _houseClicked;

public:
	Building(Object* obj);

	virtual void Init();
	virtual void Update();

	virtual void OnMouseDown();
	

	BUILDINGTYPE GetBuildingType() { return buildingType; }


	void SetLinkWithManager(BuildingManager* manager) { _buildingManager = manager; }
	BuildingManager* GetManager() { return _buildingManager; }
};