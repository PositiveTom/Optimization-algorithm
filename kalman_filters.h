#pragma once
#include<Eigen/Core>
#include<iostream>
#include<random>

class Kalman_Filters
{
public:
	Kalman_Filters(Eigen::MatrixXd &A, Eigen::MatrixXd &B, Eigen::MatrixXd &H);
	void Modify_Noise_var_matrix(Eigen::MatrixXd &R, Eigen::MatrixXd &Q);
	void Input_u(Eigen::MatrixXd &u);
	void Initial_Value(Eigen::MatrixXd& Posterior_x, Eigen::MatrixXd& P);
	void Execute();

	~Kalman_Filters();

	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Real_x;//状态的实际值
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Measure_z;//状态的观测值

	/*迭代的5个增量*/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Posterior_x;//后验估计状态
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Priori_x;//先验估计状态
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> K_Gain;//卡尔曼增益
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> P_;//先验误差协方差矩阵
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> P;//后验误差协方差矩阵

	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> u;//控制输入

	/*系统的固定系数*/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A;//系统矩阵
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> B;//控制矩阵
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> H;//观测矩阵
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> W;//运动方程的随机噪声
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> V;//观测方程的随机噪声

	/*噪声的协方差矩阵*/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> R;//运动方程噪声协方差矩阵
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Q;//观测方程噪声协方差矩阵

	double R_Exp, Q_Exp;//噪声的期望
	int step;//迭代次数
};
