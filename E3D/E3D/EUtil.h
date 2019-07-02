#pragma once

#include "ECommon.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include <stdarg.h>
#include <Windows.h>



namespace E3D{
	//全局的Log文件流 
	//extern  外部连接符号 -- 可以引用在当前项目的 变量  如 1.cpp int  a  2.cpp extern int a; 那么是相同的 
	//ofstream是从内存到硬盘，ifstream是从硬盘到内存，其实所谓的流缓冲就是内存空间;
	extern std::ofstream  *GlogStream;

	//初始化Log系统
	bool InitLog(const EString &fileName);

	//如果函数没有返回值，那么应声明为void类型； 2. 如果函数无参数，那么应声明其参数为void； 3. 如果函数的参数可以是任意类型指针，那么应声明其参数为void * ；4. void不能代表一个真实的变量；
	//void的字面意思是“无类型”，void *则为“无类型指针”，void *可以指向任何类型的数据。 
	//记录信息，使用前需要调用InitLog 初始化Log，并最后调用CLoseLog 关闭 Log系统
	void Log(const EChar *string , ...);

	//关闭Log系统(

	void CloseLog();

	//范围内的随机数
	//使用前需要手动播种 //rand()是产生随机int型数,%10的话就可以取0到9之间的随机整数了
	inline EInt	 RandomInt(EInt from = 0, EInt to = 10) {
		EInt ran = rand() % (to - from + 1) + from;
		return ran;
	}

	//整数转化为字符串
	inline EString IntToString(EFloat num){
		std::stringstream ss;
		ss << num;
		EString re;
		ss >> re;
		return re;
	}

	//字符串转化为整数
	//1atoi 函数是把字符串的数字转为数字型的数值，例如：int n = atoi("1234");那么结果是n的数值就为1234。
	//那么string的函数c_str()是获取这个字符串的首指针，例如： string str = "1234";那么 char* pStr = str.c_str(); 中 pStr就是指向"1234"字串的首地址 '1' 。
	inline EInt StringToInt(const EString &str){
		return atoi(str.c_str());
	}

	//字符串转化为浮点数
	inline EFloat StringToFloat(const EString &str) {
		return (EFloat)atof(str.c_str());
	}

	//转化成宽字符串
	inline EWSring ToEWString(const EString &str) {
	
		int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), NULL, 0);
		WCHAR *tString = new WCHAR(wcsLen + 1);

		::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), tString, wcsLen);

		//最后加上'\0'
		tString[wcsLen] = '\0';
		return EWSring(tString);
	}

	//检测两个浮点数是否相等
	inline EBool EqualFloat(EFloat l , EFloat r) {
		return abs(l - r) <= EPSILON_E6 ; 
	}

	//从路径里截取文件名称，如果只有文件名称，则直接返回（不包含后缀）
	inline EString GetNameFromPath(const EString &Path ){


	}



























































































		return ran;

	}


})
