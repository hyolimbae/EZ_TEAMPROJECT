#include "stdafx.h"
#include "Achievement.h"
#include "AchievementBox.h"
void Achievement::Init()
{

	auto sprite = object->AddComponent<Sprite>();
	sprite->SetSprite(Image::CreateImage("Sprite/AchievementUI.png"));
	sprite->SetDepth((int)ZORDER::UI);

	aList.push_back(aInfo{ L"수리의 귀재", L"마을의 건물을 4 채 수리하세요." , 1});
	aList.push_back(aInfo{ L"수리의 대가", L"마을의 건물을 8 채 수리하세요.", 8 });
	//aList.push_back(aInfo{ L"재료는 모든 것의 시작", L"재료를 300개 모으세요.",300 });
	//aList.push_back(aInfo{ L"한 단계 높게", L"2차 가공에 도전하세요." ,1});
	//aList.push_back(aInfo(L"더 큰 마을으로", L"마을의 인구가 50명으로 늘어났습니다."));

	

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
