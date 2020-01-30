﻿#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include "Vector2.h"

using namespace std;

#define DesignResolution Vector2(1600,900) 
#define WINSTYLE WS_VISIBLE || WS_BORDER || WS_CAPTION

enum class MSGTYPE
{
	INFORMATION,
	NOTIFICATION,
	TIME
};

//enum class TIMETYPE
//{
//	DAYEND,  //낮이 끝났다 ->밤 시작
//	NIGHTEND //밤이 끝났다 -> 낮 시작 
//};
//

//==========================================
// ## 19.10.31 ## Extern
//==========================================
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;

#include "GgaetIp.h"