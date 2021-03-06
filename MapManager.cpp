#include "stdafx.h"
#include "MapManager.h"
#include <fstream>
#include "BuildingInfo.h"
#include "BuildingComponent.h"
#include "DefaultBuilding.h"
#include "ConstructionTimeBar.h"
#include "InfoBox.h"
#include "BuildingManager.h"
#include "LinkButton.h"
#include "Inventory.h"
bool operator==(ObjectData a,ObjectData b)
{
    bool position = (a.position == b.position);
    string name1 = a.name;
    string name2 = b.name;
    return position && name1 == name2;
}

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
    ObjectData newData;
    stream.read((char*)&newData, sizeof(ObjectData));
    data.push_back(newData);
    for (int i = 0; i < size-1; i++)
    {
        ObjectData newData;
        stream.read((char*)&newData, sizeof(ObjectData));
        for (int j = 0; j < data.size(); j++)
        {
            if (newData == data[j])
                break;
            if (j == data.size() - 1)
            {
                data.push_back(newData);
                break;
            }
        }
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
    ObjectData newData2;
    stream.read((char*)&newData2, sizeof(ObjectData));
    data2.push_back(newData2);
    for (int i = 0; i < size2-1; i++)
    {
        ObjectData newData;
        stream.read((char*)&newData, sizeof(ObjectData));
        for (int j = 0; j < data2.size(); j++)
        {
            if (newData == data2[j])
                break;
            if (j == data2.size() - 1)
            {
                data2.push_back(newData);
                break;
            }
        }
    }

     stream.close();

    this->mapSize = mapSize;
    tileMap = nowMap;

    Object* testA = Object::CreateObject();
    testA->GetTransform()->SetDepth(-1);

    Object* testB = Object::CreateObject();
    testB->GetTransform()->SetDepth(999);

    for (auto d : data)
    {
        Object* newObject = Object::CreateObject(testA);
        // newObject->AddComponent<BoxCollider>();
        auto sprite = newObject->AddComponent<Sprite>();
        sprite->SetSprite(Image::CreateImage(d.name));
        sprite->SetDepth(d.depth);
        newObject->GetTransform()->SetAnchorPoint(Vector2(0, 1));
        newObject->GetTransform()->SetPosition(d.position);
    }
    for (auto d : data2)
    {
        Object* newObject = Object::CreateObject(testB);
        newObject->AddComponent<BuildingInfo>()->Init();
        newObject->AddComponent<BuildingComponent>()->SetBuilding(new DefaultBuilding(newObject));
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
        newObject->GetTransform()->SetPosition(d.position + Vector2(imageSize.x / 2, -imageSize.y / 2 + 30));
        newObject->AddComponent<PolygonDraw>();
        auto houseCollider = newObject->AddComponent<BoxCollider>();
        houseCollider->SetSize(Vector2(100, 130));

        // InfoBox
        Object* infoBox = Object::CreateObject(testB);
        infoBox->AddComponent<InfoBox>();
        /*�����������������*/        infoBox->GetComponent<InfoBox>()->SetInventoryLink(_inventory);

        // ConstructionTimeBar
        Object* constructionTimeBar = Object::CreateObject(testB);
        constructionTimeBar->AddComponent<ConstructionTimeBar>();
        constructionTimeBar->AddComponent<PolygonDraw>()->SetDepth(100);
        constructionTimeBar->SetIsActive(true);
        constructionTimeBar->GetComponent<ConstructionTimeBar>()->SetLink(newObject);

        // House�� InfoBox ��ũ
        infoBox->GetComponent<InfoBox>()->SetLink(newObject);
        ((DefaultBuilding*)(newObject->GetComponent<BuildingComponent>()->GetBuilding()))->SetLink(infoBox);
        ((DefaultBuilding*)(newObject->GetComponent<BuildingComponent>()->GetBuilding()))->SetTimeBarLink(constructionTimeBar);
        ((DefaultBuilding*)(newObject->GetComponent<BuildingComponent>()->GetBuilding()))->SetLinkWithManager(manager);


        vBuilding.push_back(newObject);

    }
}

pair<Attribute**, Vector2> MapManager::GetTileMap()
{
    return make_pair(tileMap, mapSize);
}