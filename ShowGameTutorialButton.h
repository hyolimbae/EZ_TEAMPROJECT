#pragma once
#include "Script.h"

class ShowGameTutorialButton : public Script
{
private:

public:

	virtual void Init();
	virtual void Update();

	virtual void OnMouseDown() override;
};

