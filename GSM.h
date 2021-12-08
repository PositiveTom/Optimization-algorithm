#pragma once

#ifndef GSM_H
#define GSM_H

#include <cmath>
#include <iostream>

typedef double Inter_type;//�������������
typedef double (*T) (double);//ָ������ָ���һ�����ͣ����ֺ�������ֵ��double���������������Ϊdouble

class GSM
{
public:
	GSM(Inter_type* pointer);//�вι��캯��
	void Cal_Gold_Sym_Point();//�����Ե�
	void Compare_Point();//������������
	bool Judge();//�ж����������Ƿ���������
	Inter_type* Execute();//����ʾ������

	T Target_Fun;//Ŀ�꺯��

private:
	Inter_type Init_Inter_left, Init_Inter_right;//��ʼ�������˵���Ҷ˵�
	Inter_type Cur_Inter_left, Cur_Inter_right;//��ǰ�������˵���Ҷ˵�

	Inter_type Gold_Point;//�ƽ�ָ��
	Inter_type Symmetry_Point;//�ƽ�ָ�ĶԳƵ�

	float Precision;//��������ﵽ�ľ���

	int iteration;//��������
};


#endif

