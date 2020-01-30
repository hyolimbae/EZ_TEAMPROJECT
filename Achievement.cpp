#include "stdafx.h"
#include "Achievement.h"
#include "AchievementBox.h"
void Achievement::Init()
{

	auto sprite = object->AddComponent<Sprite>();
	sprite->SetSprite(Image::CreateImage("Sprite/AchievementUI.png"));
	sprite->SetDepth((int)ZORDER::UI);

	aList.push_back(aInfo{ L"������ ����", L"������ �ǹ��� 4 ä �����ϼ���." , 1});
	aList.push_back(aInfo{ L"������ �밡", L"������ �ǹ��� 8 ä �����ϼ���.", 8 });
	//aList.push_back(aInfo{ L"���� ��� ���� ����", L"��Ḧ 300�� ��������.",300 });
	//aList.push_back(aInfo{ L"�� �ܰ� ����", L"2�� ������ �����ϼ���." ,1});
	//aList.push_back(aInfo(L"�� ū ��������", L"������ �α��� 50������ �þ���ϴ�."));

	

	for (int i = 0; i < aList.size(); i++)
	{
		auto newAchievement = Object::CreateObject(object);
		newAchievement->GetTransform()->SetPosition(Vector2(0, 190 - i * 100));
		auto boxcompo = newAchievement->AddComponent<AchievementBox>();
		boxcompo->SetString(make_pair(aList[i].title,aList[i].content));
		boxcompo->SetNotifyNum(aList[i].notifyNum);
		aBox.push_back(newAchievement);
	}
}


void Achievement::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::INFORMATION)
		return;

	for (int i = 0; i < aList.size(); i++)
		if (aList[i].title == string_to_wstring(event))
			aBox[i]->GetComponent<AchievementBox>()->SetProgress();


		
}
