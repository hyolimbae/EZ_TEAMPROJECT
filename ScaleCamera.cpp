#include "stdafx.h"
#include "ScaleCamera.h"

void ScaleCamera::Init()
{
	transform = CameraManager::GetInstance()->GetRenderCamera()->GetTransform();
}

void ScaleCamera::Update()
{
	if (!_isScaling) return;

	_lerpCount += 1.f / (ApplicationManager::GetInstance()->GetFrameRate() * _moveTime);
	_scale = Vector2::Lerp(_startScale, _endScale, _lerpCount);
	_position = Vector2::Lerp(_startPosition, _endPosition, _lerpCount);

	if (_lerpCount >= 1)
	{
		_lerpCount = 0;
		_isScaling = false;
	}

	transform->SetScale(_scale);
	transform->SetPosition(_position);
}


void ScaleCamera::Zoom(Vector2 scale, float moveTime)
{
	_isScaling = true;
	_startScale = _scale;
	_endScale = scale;
	_moveTime = moveTime;
}

void ScaleCamera::Zoom(Vector2 position, Vector2 scale, float moveTime)
{
	_isScaling = true;
	_startScale = _scale;
	_endScale = scale;
	_moveTime = moveTime;

	_startPosition = transform->GetPosition();
	_endPosition = position*-1 + DesignResolution*Vector2(0.5f,-0.5f);
}
