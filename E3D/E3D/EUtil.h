#pragma once

#include "ECommon.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include <stdarg.h>
#include <Windows.h>



namespace E3D{
	//ȫ�ֵ�Log�ļ��� 
	//extern  �ⲿ���ӷ��� -- ���������ڵ�ǰ��Ŀ�� ����  �� 1.cpp int  a  2.cpp extern int a; ��ô����ͬ�� 
	//ofstream�Ǵ��ڴ浽Ӳ�̣�ifstream�Ǵ�Ӳ�̵��ڴ棬��ʵ��ν������������ڴ�ռ�;
	extern std::ofstream  *GlogStream;

	//��ʼ��Logϵͳ
	bool InitLog(const EString &fileName);

	//�������û�з���ֵ����ôӦ����Ϊvoid���ͣ� 2. ��������޲�������ôӦ���������Ϊvoid�� 3. ��������Ĳ�����������������ָ�룬��ôӦ���������Ϊvoid * ��4. void���ܴ���һ����ʵ�ı�����
	//void��������˼�ǡ������͡���void *��Ϊ��������ָ�롱��void *����ָ���κ����͵����ݡ� 
	//��¼��Ϣ��ʹ��ǰ��Ҫ����InitLog ��ʼ��Log����������CLoseLog �ر� Logϵͳ
	void Log(const EChar *string , ...);

	//�ر�Logϵͳ(

	void CloseLog();

	//��Χ�ڵ������
	//ʹ��ǰ��Ҫ�ֶ����� //rand()�ǲ������int����,%10�Ļ��Ϳ���ȡ0��9֮������������
	inline EInt	 RandomInt(EInt from = 0, EInt to = 10) {
		EInt ran = rand() % (to - from + 1) + from;
		return ran;
	}

	//����ת��Ϊ�ַ���
	inline EString IntToString(EFloat num){
		std::stringstream ss;
		ss << num;
		EString re;
		ss >> re;
		return re;
	}

	//�ַ���ת��Ϊ����
	//1atoi �����ǰ��ַ���������תΪ�����͵���ֵ�����磺int n = atoi("1234");��ô�����n����ֵ��Ϊ1234��
	//��ôstring�ĺ���c_str()�ǻ�ȡ����ַ�������ָ�룬���磺 string str = "1234";��ô char* pStr = str.c_str(); �� pStr����ָ��"1234"�ִ����׵�ַ '1' ��
	inline EInt StringToInt(const EString &str){
		return atoi(str.c_str());
	}

	//�ַ���ת��Ϊ������
	inline EFloat StringToFloat(const EString &str) {
		return (EFloat)atof(str.c_str());
	}

	//ת���ɿ��ַ���
	inline EWSring ToEWString(const EString &str) {
	
		int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), NULL, 0);
		WCHAR *tString = new WCHAR(wcsLen + 1);

		::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), tString, wcsLen);

		//������'\0'
		tString[wcsLen] = '\0';
		return EWSring(tString);
	}

	//��������������Ƿ����   
	inline EBool EqualFloat(EFloat l , EFloat r) {
		return abs(l - r) <= EPSILON_E6 ; 
	}

	//��·�����ȡ�ļ����ƣ����ֻ���ļ����ƣ���ֱ�ӷ��أ���������׺��
	inline EString GetNameFromPath(const EString &path){
		std::size_t beg = path.find_last_of("\\/"); //����·��  a/b/t.exe ���ҵ�t  /�� 4  ��ô+1 �� 5 ��end �� 6 -4 -1����ô����t
		std::size_t end = path.find_last_of(".");


		if (beg == EString::npos)
			beg = -1;
		return path.substr(beg + 1, end - beg - 1);

		//std::string  aa = "c/dd/tdd.exe";
		//std::size_t bed = aa.find_last_of("\\/");
		//std::size_t end = aa.find_last_of(".");

		//printf(std::to_string(bed + 1).c_str());
		//printf(std::to_string(end).c_str());
		//printf(std::string(aa.substr(bed + 1, end - bed - 1)).c_str());  //substr() ���������ַ����г�ȡ�� start �±꿪ʼ��ָ����Ŀ���ַ�
	}

   //���������ַ������˵Ŀհ��ַ�ɾ��
	inline EString Trim (const EString &msg){
		const static EString SPACE_CHAR = " \t\f\v\n\r";
		std::size_t beg = msg.find_first_not_of(SPACE_CHAR);

		//��ֹ���ַ�������
		if (beg > msg.length())
			return EString();

		EString result = msg.substr(beg);
		std::size_t end = result.find_last_not_of(SPACE_CHAR);

		if (end != EString::npos)
			end++;

		return result.substr(0, end);

	}

}



