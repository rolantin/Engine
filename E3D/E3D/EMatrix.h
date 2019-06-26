#pragma once

#include "ECommon.h"

namespace E3D{

	//¾ØÕó MATRIX4X4_TYP
	struct EMatrix44	
	{
		static EMatrix44 INDENTITY;

		EFloat m[4][4];

		EMatrix44(){
			//³õÊ¼»¯ÄÚ´æ
			memset(m, 0, sizeof(EFloat) * 16);
		}

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

	};

}