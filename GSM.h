#pragma once

#ifndef GSM_H
#define GSM_H

#include <cmath>
#include <iostream>

typedef double Inter_type;//区间的数据类型
typedef double (*T) (double);//指向函数的指针的一种类型，这种函数返回值是double，输入参数的类型为double

class GSM
{
public:
	GSM(Inter_type* pointer);//有参构造函数
	void Cal_Gold_Sym_Point();//计算试点
	void Compare_Point();//更新搜索区间
	bool Judge();//判断搜索区间是否满足需求
	Inter_type* Execute();//运行示例程序

	T Target_Fun;//目标函数

private:
	Inter_type Init_Inter_left, Init_Inter_right;//初始区间的左端点和右端点
	Inter_type Cur_Inter_left, Cur_Inter_right;//当前区间的左端点和右端点

	Inter_type Gold_Point;//黄金分割点
	Inter_type Symmetry_Point;//黄金分割的对称点

	float Precision;//期望区间达到的精度

	int iteration;//迭代次数
};


#endif

