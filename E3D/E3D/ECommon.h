#pragma once

#include <cmath>
#include <iostream>

#include "E3DHeader.h"

namespace	E3D
{
  //定义类型
	typedef char EChar;
	typedef short EShot;
	typedef float EFloat;
	typedef int EInt;
	typedef bool EBool;
	typedef long Elong;
	typedef double EDouble;
	typedef std::string EString;
	typedef std::wstring EWSring;

	typedef unsigned char EUChar;
	typedef unsigned short EUShort;
	typedef unsigned int EUInt;

	//窗口大小
	const EInt SCREEN_WIDTH = 800;
	const EInt SCREEN_HEIGHT = 600;

	//默认的名称
	const EString DEFAULT_NAME = "E3D_Default";
	const EString DefaultPath = "Media";


}
