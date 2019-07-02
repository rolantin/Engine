#pragma once

#include "ECommon.h"

namespace E3D{

	//矩阵 MATRIX4X4_TYP
	struct EMatrix44	
	{
		static EMatrix44 INDENTITY;

		EFloat m[4][4];

		//初始化内存
		EMatrix44(){
			memset(m, 0, sizeof(EFloat) * 16);
		}

		//带参数的构造函数
		EMatrix44(const EMatrix44 &right){
			m[0][0] = right.m[0][0], m[0][1] = right.m[0][1], m[0][2] = right.m[0][2], m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0], m[1][1] = right.m[1][1], m[1][2] = right.m[0][2], m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0], m[2][1] = right.m[2][1], m[2][2] = right.m[2][2], m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0], m[3][1] = right.m[3][1], m[3][2] = right.m[3][2], m[3][3] = right.m[3][3];
		}
		
		EMatrix44(  EFloat m0_0, EFloat m0_1, EFloat m0_2, EFloat m0_3,
		                	EFloat m1_0, EFloat m1_1, EFloat m1_2, EFloat m1_3,
		                	EFloat m2_0, EFloat m2_1, EFloat m2_2, EFloat m2_3,
		                 	EFloat m3_0, EFloat m3_1, EFloat m3_2, EFloat m3_3)
		{
		    	m[0][0] = m0_0, m[0][1] = m0_1, m[0][2] = m0_2, m[0][3] = m0_3;
				m[1][0] = m1_0, m[1][1] = m1_1, m[1][2] = m1_2, m[1][3] = m1_3;
				m[2][0] = m2_0, m[2][1] = m2_1, m[2][2] = m2_2, m[2][3] = m2_3;
				m[3][0] = m3_0, m[3][1] = m3_1, m[3][2] = m3_2, m[3][3] = m3_3;

		}


		//矩阵转置
		//在 c/c++ 中，为了解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题，特别的引入了 inline 修饰符，表示为内联函数。
		//栈空间就是指放置程序的局部数据（也就是函数内数据）的内存空间。
		//在系统下，栈空间是有限的，假如频繁大量的使用就会造成因栈空间不足而导致程序出错的问题，如，函数的死循环递归调用的最终结果就是导致栈内存空间枯竭。
		//inline 的使用是有所限制的，inline 只适合涵数体内代码简单的涵数使用，不能包含复杂的结构控制语句例如 while、switch，并且不能内联函数本身不能是直接递归函数（即，自己内部还调用自己的函数）。
		inline EMatrix44 transpose() const{
			EMatrix44 temp;
			for (EInt i =0;i<4;i++)
			{
				for (EInt j = 0; j < 4; j++)
					temp.m[i][j] = m[j][i];
			}
			return temp;
		}

		//获取矩阵中的某个值
		// 与int固定四个字节不同有所不同,size_t的取值range是目标平台下最大可能的数组尺寸,
		//一些平台下size_t的范围小于int的正数范围,又或者大于unsigned int. 使用Int既有可能浪费，又有可能范围不够大。
		//size_t在32位架构上是4字节，在64位架构上是8字节，在不同架构上进行编译时需要注意这个问题。而int在不同架构下都是4字节，与size_t不同；且int为带符号数，size_t为无符号数。
		inline EFloat at(size_t i , size_t j)const
		{
			return m[i][j]; 
		}

		//矩阵加法操作  inline 不压栈 类似宏 直接编译出来 文件会增大
		inline EMatrix44 operator+ (const EMatrix44 &right) const
		{
			return EMatrix44(
				m[0][0] + right.m[0][0], m[0][1] + right.m[0][1], m[0][2] + right.m[0][2], m[0][3] + right.m[0][3],
				m[1][0] + right.m[1][0], m[1][1] + right.m[1][1], m[1][2] + right.m[1][2], m[1][3] + right.m[1][3],
				m[2][0] + right.m[2][0], m[2][1] + right.m[2][1], m[2][2] + right.m[2][2], m[2][3] + right.m[2][3],
				m[3][0] + right.m[3][0], m[3][1] + right.m[3][1], m[3][2] + right.m[3][2], m[3][3] + right.m[3][3]
			);
		}

		//矩阵减法操作
		inline EMatrix44 operator- (const EMatrix44 &right) const
		{
			return EMatrix44(
				m[0][0] - right.m[0][0], m[0][1] - right.m[0][1], m[0][2] - right.m[0][2], m[0][3] - right.m[0][3],
				m[1][0] - right.m[1][0], m[1][1] - right.m[1][1], m[1][2] - right.m[1][2], m[1][3] - right.m[1][3],
				m[2][0] - right.m[2][0], m[2][1] - right.m[2][1], m[2][2] - right.m[2][2], m[2][3] - right.m[2][3],
				m[3][0] - right.m[3][0], m[3][1] - right.m[3][1], m[3][2] - right.m[3][2], m[3][3] - right.m[3][3]
			);
		}

		//矩阵与数乘法操作
		inline EMatrix44 operator* (const EFloat factor) const
		{
			return EMatrix44(
				m[0][0] * factor, m[0][1] * factor, m[0][2] * factor, m[0][3] * factor,
				m[1][0] * factor, m[1][1] * factor, m[1][2] * factor, m[1][3] * factor,
				m[2][0] * factor, m[2][1] * factor, m[2][2] * factor, m[2][3] * factor,
				m[3][0] * factor, m[3][1] * factor, m[3][2] * factor, m[3][3] * factor
			);
		}

		//矩阵与矩阵乘法操作
		inline EMatrix44 operator* (const EMatrix44 &right) const
		{
			return EMatrix44(
				m[0][0] * right.m[0][0], m[0][1] * right.m[0][1], m[0][2] * right.m[0][2], m[0][3] * right.m[0][3],
				m[1][0] * right.m[1][0], m[1][1] * right.m[1][1], m[1][2] * right.m[1][2], m[1][3] * right.m[1][3],
				m[2][0] * right.m[2][0], m[2][1] * right.m[2][1], m[2][2] * right.m[2][2], m[2][3] * right.m[2][3],
				m[3][0] * right.m[3][0], m[3][1] * right.m[3][1], m[3][2] * right.m[3][2], m[3][3] * right.m[3][3]
			);
		}

		//矩阵的赋值
		inline EMatrix44 &operator = (const EMatrix44 &right){
			m[0][0] = right.m[0][0], m[0][1] = right.m[0][1], m[0][2] = right.m[0][2], m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0], m[1][1] = right.m[1][1], m[1][2] = right.m[0][2], m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0], m[2][1] = right.m[2][1], m[2][2] = right.m[2][2], m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0], m[3][1] = right.m[3][1], m[3][2] = right.m[3][2], m[3][3] = right.m[3][3];

			return *this;
		}

		//判断两个矩阵是否相等
		inline bool operator == (const EMatrix44 &right) const {
		if( m[0][0] != right.m[0][0] || m[0][1] != right.m[0][1] || m[0][2] != right.m[0][2] || m[0][3] != right.m[0][3] ||
			m[1][0] != right.m[1][0] || m[1][1] != right.m[1][1] || m[1][2] != right.m[0][2] || m[1][3] != right.m[1][3] ||
			m[2][0] != right.m[2][0] || m[2][1] != right.m[2][1] || m[2][2] != right.m[2][2] || m[2][3] != right.m[2][3] ||
			m[3][0] != right.m[3][0] || m[3][1] != right.m[3][1] || m[3][2] != right.m[3][2] || m[3][3] != right.m[3][3])
		return false;

		return true;
		}

	};

}