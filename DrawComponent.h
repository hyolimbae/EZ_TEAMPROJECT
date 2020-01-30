#pragma once
#include "Component.h"

enum class DrawType
{
	Sprite,
	Text
};

class Transform;

class DrawComponent : public Component
{
protected:
	Transform* transform;
	bool isCamearAffected = true;
	int depth = 0;
public:
	Transform* GetTransform() { return transform; };
	void SetCameraAffected(bool affected) { isCamearAffected = affected; };
	bool GetCameraAffected() { return isCamearAffected; };
	virtual void Awake() override;
	void SetDepth(int _depth) { depth = _depth; };
	int GetDepth() { return depth; };
};

