#include "GSM.h"

GSM::GSM(Inter_type* pointer)
	: Precision(pointer[0]), Init_Inter_left(pointer[1]), Init_Inter_right(pointer[2])
{
	Cur_Inter_left = Init_Inter_left;
	Cur_Inter_right = Init_Inter_right;

	Gold_Point = Symmetry_Point = 0;

	iteration = 0;

	Target_Fun = NULL;//目标函数
}
/*
	计算黄金分割点和对称点
*/
void GSM::Cal_Gold_Sym_Point()
{
	Gold_Point = Cur_Inter_left + (sqrt(5) - 1) / 2 * (Cur_Inter_right - Cur_Inter_left);
	Symmetry_Point = Cur_Inter_left + (3 - sqrt(5)) / 2 * (Cur_Inter_right - Cur_Inter_left);
	iteration++;
}
/*
	比较黄金分割点和对称点的函数值，并且更新搜索区间长度
*/
void GSM::Compare_Point()
{
	if (!Target_Fun)
	{
		throw "请先定义一个目标函数" ;
	}
	double Gold_Output = Target_Fun(Gold_Point);
	double Symmetry_Output = Target_Fun(Symmetry_Point);

	if (Symmetry_Output < Gold_Output)
	{
		Cur_Inter_right = Gold_Point;
	}
	else if (Symmetry_Output > Gold_Output)
	{
		Cur_Inter_left = Symmetry_Point;
	}
}

/*
	判断搜索区间是否满足精度要求
*/
bool GSM::Judge()
{
	return abs(Cur_Inter_right - Cur_Inter_left) / abs(Init_Inter_right - Init_Inter_left) < Precision ? true : false;
}

/*
	运行程序
*/
Inter_type* GSM::Execute()
{
	Inter_type* r = new Inter_type;
	if (Judge())
	{
		std::cout << "初始搜索区间满足精度要求" << std::endl;
		r[0] = Cur_Inter_left;
		r[1] = Cur_Inter_right;
		return r;
	}
	std::cout << "初始搜索区间不满足精度要求，开始一维搜索" << std::endl;
	for (;;)
	{
		Cal_Gold_Sym_Point();
		Compare_Point();
		std::cout << "第" << iteration << "次迭代" << std::endl;
		std::cout << "搜索区间为" << "[" << Cur_Inter_left << "," << Cur_Inter_right << "]" << std::endl;
		std::cout << "精度为:" << abs(Cur_Inter_right - Cur_Inter_left) / abs(Init_Inter_right - Init_Inter_left) << std::endl;
		if (Judge())
		{
			std::cout << "此搜索区间满足精度要求" << std::endl;
			r[0] = Cur_Inter_left;
			r[1] = Cur_Inter_right;
			break;
		}
		std::cout<<std::endl;
	}
	return r;
}