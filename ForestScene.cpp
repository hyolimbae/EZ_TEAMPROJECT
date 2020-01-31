#include "stdafx.h"
#include "ForestScene.h"
#include "WorkerAnimation.h"
#include "ForestWorkerMove.h"
#include "Bubble.h"

void ForestScene::Init()
{
	Object* background = Object::CreateObject();
	background->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Forest_Test.png"));
	background->GetTransform()->SetScale(Vector2(0.8f, 0.8f));

		// 직업들을 하나씩 돈다.

	// _miWorkers 이터레이터를 돌려서 찾으면 됨!

	//for (_miWorker = _mWorker.begin(); _miWorker != _mWorker.end(); _miWorker++)
	//{
	//	Object* worker = Object::CreateObject();
	//	worker->SetTag(_miWorker->first() 이름받아온다); it->first;
	//	string sumString = "H" + to_string(i);
	//	worker->SetName(sumString);
	//	직업마다 SetPosition 달라진다.
	//	if(second() == "직업 이름"
	//	{
	//		worker->GetTransform()->SetPosition(Vector2(200, 100));
	//	}
	//	worker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H1_Idle_Front.png"));
	//	//worker->GetComponent<Sprite>()->SetDepth(5);
	//	worker->AddComponent<BoxCollider>()->SetFixedRotation(true);
	//	worker->AddComponent<Animator>();
	//	worker->AddComponent<WorkerAnimation>();
	//	worker->AddComponent<Move>();
	//	worker->AddComponent<Physics>()->SetBodyType(BodyType::DynamicBody);
	//	worker->GetComponent<Physics>()->SetGravityScale(0.f);
	//	worker->GetComponent<Physics>()->SetIgnoreCollision(true);
	//	//worker->AddComponent<Bubble>();
	//	Object* bubble = Object::CreateObject();
	//	bubble->AddComponent<Bubble>();
	//	bubble->GetComponent<Bubble>()->SetLink(worker);
	//	bubble->AddComponent<Sprite>();
	//	bubble->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/" + worker->GetTag() + "_Bubble.png"));
	//}

	for (int i = 0; i < 12; i++)
	{
		Object* worker = Object::CreateObject();
		if (i < 3)				worker->SetTag("Water_Collector");
		if (i > 2 && i < 8)		worker->SetTag("Miner");
		if (i > 7 && i < 12)	worker->SetTag("Wood_Cutter");
		string sumString = "H" + to_string(i % 6);
		worker->SetName(sumString);
		if (worker->GetTag() == "Miner")			worker->GetTransform()->SetPosition(Vector2(120 + i * 30, 70));
		if (worker->GetTag() == "Wood_Cutter")		worker->GetTransform()->SetPosition(Vector2(-80 - i * 30, 70));
		if (worker->GetTag() == "Water_Collector")	worker->GetTransform()->SetPosition(Vector2(-100 + i * 60, -70 - i * 80));
		worker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + sumString + "_Idle_Front.png"));
		worker->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 0.7f));
		if (worker->GetTag() != "Water_Collector")	worker->AddComponent<Animator>();
		if (worker->GetTag() != "Water_Collector")  worker->AddComponent<ForestWorkerMove>();
		if (worker->GetTag() != "Water_Collector")	worker->AddComponent<WorkerAnimation>();

		Object* workerBubble = Object::CreateObject();
		workerBubble->AddComponent<Bubble>();
		workerBubble->GetComponent<Bubble>()->SetLink(worker);
		workerBubble->AddComponent<Sprite>();
		workerBubble->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/" + worker->GetTag() + "_Bubble.png"));
	}
}
