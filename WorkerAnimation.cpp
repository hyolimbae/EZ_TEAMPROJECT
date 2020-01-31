#include "stdafx.h"
#include "WorkerAnimation.h"

void WorkerAnimation::Init()
{
	auto animator = object->GetComponent<Animator>();
	_sprite = object->GetComponent<Sprite>();
	//뒤에서 보니까 너무 잘생기셔서 번호 남기고 갑니다.
	//110으로 전화 주시면 사랑합니다 고객님을 들으 실수 있어요.
	//화이팅
	Animation LRMove;
	LRMove.SetFrameCount(Vector2(4, 1));
	LRMove.SetRepeat(true);
	LRMove.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Move_Left.png"));
	LRMove.SetTime(0.1f);
	animator->AddAnimation("Worker_LRMove", LRMove);

	Animation UpMove;
	UpMove.SetFrameCount(Vector2(4, 1));
	UpMove.SetRepeat(true);
	UpMove.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Move_Back.png"));
	UpMove.SetTime(0.1f);
	animator->AddAnimation("Worker_UpMove", UpMove);

	Animation DownMove;
	DownMove.SetFrameCount(Vector2(4, 1));
	DownMove.SetRepeat(true);
	DownMove.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Move_Front.png"));
	DownMove.SetTime(0.1f);
	animator->AddAnimation("Worker_DownMove", DownMove);

	//===========================================
	Animation Idle;
	Idle.SetFrameCount(Vector2(1, 1));
	Idle.SetRepeat(false);
	Idle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Front.png"));
	Idle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle", Idle);

	Animation LeftIdle;
	LeftIdle.SetFrameCount(Vector2(1, 1));
	LeftIdle.SetRepeat(false);
	LeftIdle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Left.png"));
	LeftIdle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle_Left", LeftIdle);

	Animation BackIdle;
	BackIdle.SetFrameCount(Vector2(1, 1));
	BackIdle.SetRepeat(false);
	BackIdle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Back.png"));
	BackIdle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle_Back", BackIdle);

	animator->AddParameter<int>("Move");

	auto m2u = animator->MakeTransition("Worker_LRMove", "Worker_UpMove");
	m2u->SetCondition("Move", 0, ConditionType::Greater);
	auto u2m = animator->MakeTransition("Worker_UpMove", "Worker_LRMove");
	u2m->SetCondition("Move", 0, ConditionType::Equal);

	auto m2d = animator->MakeTransition("Worker_LRMove", "Worker_DownMove");
	m2d->SetCondition("Move", 0, ConditionType::Less);
	auto d2m = animator->MakeTransition("Worker_DownMove", "Worker_LRMove");
	d2m->SetCondition("Move", 0, ConditionType::Equal);

	auto u2d = animator->MakeTransition("Worker_UpMove", "Worker_DownMove");
	u2d->SetCondition("Move", 0, ConditionType::Less);
	auto d2u = animator->MakeTransition("Worker_DownMove", "Worker_UpMove");
	d2u->SetCondition("Move", 0, ConditionType::Greater);

	//Move->Idle Setting
	auto m2i = animator->MakeTransition("Worker_LRMove", "Worker_Idle");
	m2i->SetCondition("Move", 3, ConditionType::Equal);
	auto i2m = animator->MakeTransition("Worker_Idle", "Worker_LRMove");
	i2m->SetCondition("Move", 0, ConditionType::Equal);
	//UpMove->Idle Setting
	auto u2i = animator->MakeTransition("Worker_UpMove", "Worker_Idle");
	u2i->SetCondition("Move", 3, ConditionType::Equal);
	auto i2u = animator->MakeTransition("Worker_Idle", "Worker_UpMove");
	i2u->SetCondition("Move", -1, ConditionType::Equal);
	//DownMove->Idle Setting
	auto d2i = animator->MakeTransition("Worker_DownMove", "Worker_Idle");
	d2i->SetCondition("Move", 3, ConditionType::Equal);
	auto i2d = animator->MakeTransition("Worker_Idle", "Worker_DownMove");
	i2d->SetCondition("Move", 1, ConditionType::Equal);

	
}

void WorkerAnimation::Update()
{

}

