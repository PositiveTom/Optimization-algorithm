#pragma once
#include "Incremental_heuristic.h"
#include<Eigen/Core>
#include<iostream>

/*
	加步探索法，一维函数，用于确定0.618法等一维搜索法的包含极小值的初始搜索区间
*/

typedef double(*T) (double);
class IH
{
public:
	IH(double& x0_, double& h_,T Fun);
	~IH();
	T Fun,diff_Fun,diff_2_Fun;
	void Excute();
	double x0;//搜索初始点
	double step;//搜索步长

	/*四点*/
	Eigen::Vector<double,3> x;


private:
	
};

