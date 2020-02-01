#pragma once
#include "GgaetIp.h"

class BuildingManager;

struct ObjectData
{
    char name[50];
    Vector2 position;
    int depth;
};

enum class Attribute
{
    None,
    Wall,
    Undiscovered
};

class MapManager : public Script
{
private:
    Attribute** tileMap;
    Vector2 mapSize;
public:
	static MapManager* GetInstance();
    void Load(string name, BuildingManager* manager);

    pair<Attribute**,Vector2> GetTileMap();
};

