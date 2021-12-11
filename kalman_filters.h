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

	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Real_x;//״̬��ʵ��ֵ
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Measure_z;//״̬�Ĺ۲�ֵ

	/*������5������*/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Posterior_x;//�������״̬
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Priori_x;//�������״̬
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> K_Gain;//����������
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> P_;//�������Э�������
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> P;//�������Э�������

	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> u;//��������

	/*ϵͳ�Ĺ̶�ϵ��*/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A;//ϵͳ����
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> B;//���ƾ���
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> H;//�۲����
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> W;//�˶����̵��������
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> V;//�۲ⷽ�̵��������

	/*������Э�������*/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> R;//�˶���������Э�������
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Q;//�۲ⷽ������Э�������

	double R_Exp, Q_Exp;//����������
	int step;//��������
};
