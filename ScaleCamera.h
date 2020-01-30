#pragma once
#include "GgaetIp.h"

class ScaleCamera : public Script
{
private:
	Transform* transform;
	

	bool _isScaling = false;
	float _lerpCount = 0;
	float _moveTime = 0;

	Vector2 _endScale = Vector2(1,1);
	Vector2 _startScale = Vector2(1, 1);
	Vector2 _scale = Vector2(1, 1);

	Vector2 _startPosition;
	Vector2 _endPosition;
	Vector2 _position;


public:
	virtual void Init() override;
	virtual void Update() override;

	void Zoom(Vector2 scale, float moveTime);
	void Zoom(Vector2 position, Vector2 scale, float moveTime);
};

