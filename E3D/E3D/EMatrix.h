#pragma once

#include "ECommon.h"

namespace E3D{

	//���� MATRIX4X4_TYP
	struct EMatrix44	
	{
		static EMatrix44 INDENTITY;

		EFloat m[4][4];

		//��ʼ���ڴ�
		EMatrix44(){
			memset(m, 0, sizeof(EFloat) * 16);
		}

		//�������Ĺ��캯��
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


		//����ת��
		//�� c/c++ �У�Ϊ�˽��һЩƵ�����õ�С������������ջ�ռ䣨ջ�ڴ棩�����⣬�ر�������� inline ���η�����ʾΪ����������
		//ջ�ռ����ָ���ó���ľֲ����ݣ�Ҳ���Ǻ��������ݣ����ڴ�ռ䡣
		//��ϵͳ�£�ջ�ռ������޵ģ�����Ƶ��������ʹ�þͻ������ջ�ռ䲻������³����������⣬�磬��������ѭ���ݹ���õ����ս�����ǵ���ջ�ڴ�ռ�ݽߡ�
		//inline ��ʹ�����������Ƶģ�inline ֻ�ʺϺ������ڴ���򵥵ĺ���ʹ�ã����ܰ������ӵĽṹ����������� while��switch�����Ҳ�������������������ֱ�ӵݹ麯���������Լ��ڲ��������Լ��ĺ�������
		inline EMatrix44 transpose() const{
			EMatrix44 temp;
			for (EInt i =0;i<4;i++)
			{
				for (EInt j = 0; j < 4; j++)
					temp.m[i][j] = m[j][i];
			}
			return temp;
		}

		//��ȡ�����е�ĳ��ֵ
		// ��int�̶��ĸ��ֽڲ�ͬ������ͬ,size_t��ȡֵrange��Ŀ��ƽ̨�������ܵ�����ߴ�,
		//һЩƽ̨��size_t�ķ�ΧС��int��������Χ,�ֻ��ߴ���unsigned int. ʹ��Int���п����˷ѣ����п��ܷ�Χ������
		//size_t��32λ�ܹ�����4�ֽڣ���64λ�ܹ�����8�ֽڣ��ڲ�ͬ�ܹ��Ͻ��б���ʱ��Ҫע��������⡣��int�ڲ�ͬ�ܹ��¶���4�ֽڣ���size_t��ͬ����intΪ����������size_tΪ�޷�������
		inline EFloat at(size_t i , size_t j)const
		{
			return m[i][j]; 
		}

		//����ӷ�����  inline ��ѹջ ���ƺ� ֱ�ӱ������ �ļ�������
		inline EMatrix44 operator+ (const EMatrix44 &right) const
		{
			return EMatrix44(
				m[0][0] + right.m[0][0], m[0][1] + right.m[0][1], m[0][2] + right.m[0][2], m[0][3] + right.m[0][3],
				m[1][0] + right.m[1][0], m[1][1] + right.m[1][1], m[1][2] + right.m[1][2], m[1][3] + right.m[1][3],
				m[2][0] + right.m[2][0], m[2][1] + right.m[2][1], m[2][2] + right.m[2][2], m[2][3] + right.m[2][3],
				m[3][0] + right.m[3][0], m[3][1] + right.m[3][1], m[3][2] + right.m[3][2], m[3][3] + right.m[3][3]
			);
		}

		//�����������
		inline EMatrix44 operator- (const EMatrix44 &right) const
		{
			return EMatrix44(
				m[0][0] - right.m[0][0], m[0][1] - right.m[0][1], m[0][2] - right.m[0][2], m[0][3] - right.m[0][3],
				m[1][0] - right.m[1][0], m[1][1] - right.m[1][1], m[1][2] - right.m[1][2], m[1][3] - right.m[1][3],
				m[2][0] - right.m[2][0], m[2][1] - right.m[2][1], m[2][2] - right.m[2][2], m[2][3] - right.m[2][3],
				m[3][0] - right.m[3][0], m[3][1] - right.m[3][1], m[3][2] - right.m[3][2], m[3][3] - right.m[3][3]
			);
		}

		//���������˷�����
		inline EMatrix44 operator* (const EFloat factor) const
		{
			return EMatrix44(
				m[0][0] * factor, m[0][1] * factor, m[0][2] * factor, m[0][3] * factor,
				m[1][0] * factor, m[1][1] * factor, m[1][2] * factor, m[1][3] * factor,
				m[2][0] * factor, m[2][1] * factor, m[2][2] * factor, m[2][3] * factor,
				m[3][0] * factor, m[3][1] * factor, m[3][2] * factor, m[3][3] * factor
			);
		}

		//���������˷�����
		inline EMatrix44 operator* (const EMatrix44 &right) const
		{
			return EMatrix44(
				m[0][0] * right.m[0][0], m[0][1] * right.m[0][1], m[0][2] * right.m[0][2], m[0][3] * right.m[0][3],
				m[1][0] * right.m[1][0], m[1][1] * right.m[1][1], m[1][2] * right.m[1][2], m[1][3] * right.m[1][3],
				m[2][0] * right.m[2][0], m[2][1] * right.m[2][1], m[2][2] * right.m[2][2], m[2][3] * right.m[2][3],
				m[3][0] * right.m[3][0], m[3][1] * right.m[3][1], m[3][2] * right.m[3][2], m[3][3] * right.m[3][3]
			);
		}

		//����ĸ�ֵ
		inline EMatrix44 &operator = (const EMatrix44 &right){
			m[0][0] = right.m[0][0], m[0][1] = right.m[0][1], m[0][2] = right.m[0][2], m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0], m[1][1] = right.m[1][1], m[1][2] = right.m[0][2], m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0], m[2][1] = right.m[2][1], m[2][2] = right.m[2][2], m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0], m[3][1] = right.m[3][1], m[3][2] = right.m[3][2], m[3][3] = right.m[3][3];

			return *this;
		}

		//�ж����������Ƿ����
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