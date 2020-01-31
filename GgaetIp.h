#pragma once
#include "Scene.h"
#include "Animator.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "Physics.h"
#include "Script.h"
#include "Sound.h"
#include "Sprite.h"
#include "Text.h"
#include "Transform.h"
#include "Animation.h"
#include "AnimationTransition.h"
#include "CameraManager.h"
#include "Direct2D.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Matrix2x2.h"
#include "PhysicsManager.h"
#include "SoundListenerManager.h"
#include "Vector3.h"
#include "TimeManager.h"
#include "ApplicationManager.h"
#include "DebugDraw.h"
#include "Direct3D.h"
#include "ImGui/imgui.h"
#include "ImGui/imconfig.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGuiManager.h"
#include "ImGuiWindow.h"
#include "ImGuiButton.h"
#include "UI.h"
#include "ImGuiText.h"
#include "PolygonDraw.h"
#include "WorkerControlManager.h"
//#include "WorkerControlManager.h"


#define FrameRate 60
#define Lerp_Float(a,b,i) (1 - i)*a + i * b
#define Clamp(l,h,x) max(min(x,h),l)
#define Deg2Rad 3.1415f/180
#define Rad2Deg 180.f/3.1415f