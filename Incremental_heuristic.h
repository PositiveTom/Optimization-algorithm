#pragma once
#include "Incremental_heuristic.h"
#include<Eigen/Core>
#include<iostream>

/*
	�Ӳ�̽������һά����������ȷ��0.618����һά�������İ�����Сֵ�ĳ�ʼ��������
*/

typedef double(*T) (double);
class IH
{
public:
	IH(double& x0_, double& h_,T Fun);
	~IH();
	T Fun,diff_Fun,diff_2_Fun;
	void Excute();
	double x0;//������ʼ��
	double step;//��������

	/*�ĵ�*/
	Eigen::Vector<double,3> x;


private:
	
};

