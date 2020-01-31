#include "stdafx.h"
#include "CharacterAnimation.h"

void CharacterAnimation::Init()
{
	auto animator = object->GetComponent<Animator>();

	
	//1. �ʿ��� �������̹���(�ִϸ��̼�) ADD

	Animation idle;
	//������ ���� (X,Y)
	idle.SetFrameCount(Vector2(2, 1));
	//�ݺ� ���� 
	idle.SetRepeat(true);
	idle.SetImage(Image::CreateImage("Sprite/ErikIdle.png"));
	//������ ������ �ӵ� (1�� ������� ���� ������)
	idle.SetTime(0.1f);
	animator->AddAnimation("Erik_Idle", idle); 

	Animation jump;
	jump.SetFrameCount(Vector2(4, 1));
	jump.SetRepeat(false);
	jump.SetImage(Image::CreateImage("Sprite/ErikJump.png"));
	jump.SetTime(0.2f);
	animator->AddAnimation("Erik_Jump", jump);

	Animation run;
	run.SetFrameCount(Vector2(8, 1));
	run.SetRepeat(true);
	run.SetImage(Image::CreateImage("Sprite/ErikRun.png"));
	run.SetTime(0.1f);
	animator->AddAnimation("Erik_Run", run);

	//2. �ٸ� �������̹����� ��ȯ ���� ����� 
	//   ���ڰ����� int,bool,float�� ����.
	animator->AddParameter<int>("Run");
	animator->AddParameter<bool>("Jump");


	//(1). INT�� ���ڰ����� ���� ��


	//IDLE���� RUN���� ���� Ʈ������ 
	//RUN ������ 0�� �ٸ��� ��ȯ
	auto itor = animator->MakeTransition("Erik_Idle", "Erik_Run");
	itor->SetCondition("Run", 0,ConditionType::NotEqual);

	//RUN���� IDLE�� ���� Ʈ������
	//RUN ������ 0�� ������ ��ȯ
	//���� ���ʹ� �޸� �̷������� ������ �༭ ������,���� ���� ������ IDLE ���� ����. 
	auto rtoi = animator->MakeTransition("Erik_Run", "Erik_Idle");
	rtoi->SetCondition("Run", 0,ConditionType::Equal);

	//(2) BOOL�� ���ڰ����� ���� ��

	//IDLE���� ������ ���� Ʈ������ 
	//JUMP ������ true�϶� 
	auto itoj = animator->MakeTransition("Erik_Idle", "Erik_Jump");
	itoj->SetCondition("Jump", true);

	//�������� IDLE�� ���� Ʈ������
	//JUMP ������ false�϶� 
	auto jtoi = animator->MakeTransition("Erik_Jump", "Erik_Idle");
	jtoi->SetCondition("Jump", false);


}