#pragma once
#include "GgaetIp.h"


/*

�����ڰ� ���� ���ǿ� ���� 
��ȯ���� ���ڰ��� �ٲ��ִ� Ŭ���� 

*/
class CharacterMove : public Script
{
private:
	Animator* animator;
	Sprite* sprite;
public:
	virtual void Init() override;
	virtual void Update() override;
};

