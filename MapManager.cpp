#include "stdafx.h"
#include "MapManager.h"
#include <fstream>
#include "BuildingInfo.h"
#include "BuildingComponent.h"
#include "DefaultBuilding.h"
#include "ConstructionTimeBar.h"
#include "InfoBox.h"
#include "BuildingManager.h"

MapManager* MapManager::GetInstance()
{
	static MapManager* instance = new MapManager();
	return instance;
}

void MapManager::Load(string name, BuildingManager* manager)
{
    vector<ObjectData> data;
    vector<ObjectData> data2;

    ifstream stream;
    stream.open("Resources/Map/" + name + ".map", ios::binary);
    int size = 0;
    stream.read((char*)&size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        ObjectData newData;
        stream.read((char*)&newData, sizeof(ObjectData));
        data.push_back(newData);
    }

    Vector2 mapSize;
    stream.read((char*)&mapSize, sizeof(Vector2));

    Attribute** nowMap;
    nowMap = new Attribute * [mapSize.y];
    for (int i = 0; i < mapSize.y; i++)
        nowMap[i] = new Attribute[mapSize.x];

    for (int i = 0; i < mapSize.y; i++)
        for (int j = 0; j < mapSize.x; j++)
            stream.read((char*)&nowMap[i][j], sizeof(Attribute));

    int size2 = 0;
    stream.read((char*)&size2, sizeof(int));

    for (int i = 0; i < size2; i++)
    {
        ObjectData newData;
        stream.read((char*)&newData, sizeof(ObjectData));
        data2.push_back(newData);
    }

    stream.close();

    this->mapSize = mapSize;
    tileMap = nowMap;

    for (auto d : data)
    {
        Object* newObject = Object::CreateObject();
       // newObject->AddComponent<BoxCollider>();
        auto sprite = newObject->AddComponent<Sprite>();
        sprite->SetSprite(Image::CreateImage(d.name));
        sprite->SetDepth(d.depth);
        newObject->GetTransform()->SetAnchorPoint(Vector2(0, 1));
        newObject->GetTransform()->SetPosition(d.position);
    }
    for (auto d : data2)
    {
        Object* newObject = Object::CreateObject();
        newObject->AddComponent<BuildingInfo>();
        newObject->AddComponent<BuildingComponent>()->SetBuilding(new DefaultBuilding(newObject));
        auto houseCollider = newObject->AddComponent<BoxCollider>();
        houseCollider->SetSize(Vector2(90, 100));
        // newObject->AddComponent<BoxCollider>();
        auto sprite = newObject->AddComponent<Sprite>(); //25~31
        string tag = d.name;
        tag = tag.substr(25, 7);
        newObject->SetTag(tag);
        auto image = Image::CreateImage(d.name);
        auto imageSize = image->GetContentSize();
        sprite->SetSprite(image);
        sprite->SetDepth(d.depth);
        newObject->GetTransform()->SetAnchorPoint(Vector2(0.5f, 0.5f));
        newObject->GetTransform()->SetPosition(d.position + Vector2(imageSize.x/2,-imageSize.y/2 + 30));
        newObject->AddComponent<PolygonDraw>();

        // InfoBox
        Object* infoBox = Object::CreateObject();
        infoBox->AddComponent<InfoBox>();

        // ConstructionTimeBar
        Object* constructionTimeBar = Object::CreateObject();
        constructionTimeBar->AddComponent<ConstructionTimeBar>();
        constructionTimeBar->AddComponent<PolygonDraw>();
        constructionTimeBar->SetIsActive(true);
        constructionTimeBar->GetComponent<ConstructionTimeBar>()->SetLink(newObject);

        // House¶û InfoBox ¸µÅ©
        infoBox->GetComponent<InfoBox>()->SetLink(newObject);
        ((DefaultBuilding*)(newObject->GetComponent<BuildingComponent>()->GetBuilding()))->SetLink(infoBox);
        ((DefaultBuilding*)(newObject->GetComponent<BuildingComponent>()->GetBuilding()))->SetTimeBarLink(constructionTimeBar);
        ((DefaultBuilding*)(newObject->GetComponent<BuildingComponent>()->GetBuilding()))->SetLinkWithManager(manager);

    }
}

pair<Attribute**, Vector2> MapManager::GetTileMap()
{
    return make_pair(tileMap, mapSize);
}
