#include "stdafx.h"
#include "GgaetIp.h"

void DrawComponent::Awake()
{
	this->transform = object->GetTransform();
}