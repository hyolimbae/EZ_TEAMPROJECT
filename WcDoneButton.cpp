#include "stdafx.h"
#include "WcDoneButton.h"
#include "WorkerControl.h"

void WcDoneButton::Init()
{
}

void WcDoneButton::Update()
{
}

void WcDoneButton::OnMouseDown()
{
	_workerControl->ControlOnOff(false);
}
