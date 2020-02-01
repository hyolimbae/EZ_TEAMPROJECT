#pragma once
#include "GgaetIp.h"
#include "Tile.h"

#define TILENUM_X 20
#define TILENUM_Y 20

//ISOMETRIC 
//#define TILEWIDTH 128
//#define TILEHEIGHT 32

//GENERAL
#define TILEWIDTH 48
#define TILEHEIGHT 48

class TilePick;

struct testInfo
{
	string name;
	float r;
	float g;
	float b;
	int depth;
};

class TileMap : public Script
{
private:
	vector<Object*> vTotal;
	map<ATTRIBUTE, testInfo> attributeInfo;
	Object* tilePick;
	Object* tileView;

	bool _isStart = false;

public:
	virtual void Init() override;

	void SetTile(Vector2 index, ATTRIBUTE attribute);
	void SetLink(Object* tilePick) { this->tilePick = tilePick; }

	void SetTileView(bool tileView) {this->tileView->SetIsActive(tileView);}
	bool GetTileView() { return this->tileView->GetIsActive(); }

	vector<Object*> GetVTotal() { return vTotal; }
};

