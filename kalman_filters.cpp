#include"kalman_filters.h"


/*
	初始化传入系统的运动方程和观测方程系数
*/
Kalman_Filters::Kalman_Filters(Eigen::MatrixXd &A, Eigen::MatrixXd &B, Eigen::MatrixXd &H):R_Exp(0),Q_Exp(0),step(0)
{
	this->A = A;
	this->B = B;
	this->H = H;
}

/*
	修改噪声的协方差矩阵
*/
void Kalman_Filters::Modify_Noise_var_matrix(Eigen::MatrixXd &R, Eigen::MatrixXd &Q)
{
	this->R = R;
	this->Q = Q;
}

/*
	输入
*/
void Kalman_Filters::Input_u(Eigen::MatrixXd &u)
{
	this->u = u;
}

/*
	传入初值
*/
void Kalman_Filters::Initial_Value(Eigen::MatrixXd &Posterior_x, Eigen::MatrixXd &P)
{
	this->Real_x = this->Posterior_x = Posterior_x;
	this->P = P;
}

/*
	Kalman滤波器迭代开始
*/
void Kalman_Filters::Execute()
{
	static std::default_random_engine generator((unsigned long)(time(NULL)));//创建随机数引擎
	static std::normal_distribution<double> normal_w(0.0, sqrt(0.1));//正态分布随机数生成器
	static std::normal_distribution<double> normal_v(0.0, 1.0);//正态分布随机数生成器

	int rows = Posterior_x.rows();

	Real_x = A * Real_x;
	for (int i = 0; i < rows; i++)
	{
		Real_x(i, 0) += normal_w(generator);//加上随机噪声
	}
	Measure_z = H * Real_x;
	for (int j = 0; j < rows; j++)
	{
		Measure_z(j, 0) += normal_v(generator);//实际传感器观测的值
	}

	/*预测方程*/
	Priori_x = A * Posterior_x + B * u;
	P_ = A * P * A.transpose() + Q;

	/*观测方程*/
	K_Gain = P_ * H.transpose() * (H * P_ * H.transpose() + R).inverse();
	int rows = K_Gain.rows();
	int cols = K_Gain.cols();
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Unit = Eigen::MatrixXd::Identity(rows,cols);
	Posterior_x = Priori_x + K_Gain * (Measure_z - H * Priori_x);
	P = (Unit - K_Gain * H) * P_;

}


Kalman_Filters::~Kalman_Filters()
{
}