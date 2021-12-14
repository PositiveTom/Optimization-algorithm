#include "Incremental_heuristic.h"

IH::IH(double& x0_, double& h_, T Fun)
	:x0(x0_),step(h_)
{
	x(0) = x0;
	this->Fun = Fun;
}

IH::~IH()
{

}

void IH::Excute()
{
	int Iter = 1;
	double xk_2 = x0;
	double xk_1 = 0;
	double xk_puls_1 = 0;
	double xk = 0;
	xk_1 = xk_2 + Iter * step;
	if (Fun(xk_2) > Fun(xk_1))
	{
		for (;;)
		{
			Iter *= 2;
			xk = xk_1 + Iter * step;
			if (Fun(xk) > Fun(xk_1))break;
			xk_2 = xk_1;
			xk_1 = xk;
		}
		xk_puls_1 = (xk + xk_1) / 2;
		Eigen::Matrix<double, 1, 4> Mat_x;
		Mat_x << xk_2, xk_1, xk_puls_1, xk;

		Eigen::Matrix<double, 1, 4> Mat_Fun_x;
		Mat_Fun_x << Fun(xk_2), Fun(xk_1), Fun(xk_puls_1), Fun(xk);

		Eigen::MatrixXd::Index mincol,minrow;
		Mat_Fun_x.minCoeff(&minrow, &mincol);

		x << Mat_x(minrow, mincol - 1), Mat_x(minrow, mincol), Mat_x(minrow, mincol + 1);
	}
	else if (Fun(xk_2) < Fun(xk_1))
	{
		xk_1 = xk_2 - Iter * step;
		for (;;)
		{
			Iter *= 2;
			xk = xk_1 - Iter * step;
			if (Fun(xk) > Fun(xk_1))break;
			xk_2 = xk_1;
			xk_1 = xk;
		}
		xk_puls_1 = (xk + xk_1) / 2;
		Eigen::Matrix<double, 1, 4> Mat_x;
		Mat_x << xk_2, xk_1, xk_puls_1, xk;

		Eigen::Matrix<double, 1, 4> Mat_Fun_x;
		Mat_Fun_x << Fun(xk_2), Fun(xk_1), Fun(xk_puls_1), Fun(xk);

		Eigen::MatrixXd::Index mincol, minrow;
		Mat_Fun_x.minCoeff(&minrow, &mincol);

		x << Mat_x(minrow, mincol + 1), Mat_x(minrow, mincol), Mat_x(minrow, mincol - 1);
	}
	else
	{ 
		throw "请重新设置初值和步长";
	}
	std::cout << "搜索区间为[" << x(0) << "," << x(2) << "]" << std::endl;
	
}