#pragma once
#include "GgaetIp.h"


/*

개발자가 정한 조건에 따라 
전환식의 인자값을 바꿔주는 클래스 

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

