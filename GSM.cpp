#include "GSM.h"

GSM::GSM(Inter_type* pointer)
	: Precision(pointer[0]), Init_Inter_left(pointer[1]), Init_Inter_right(pointer[2])
{
	Cur_Inter_left = Init_Inter_left;
	Cur_Inter_right = Init_Inter_right;

	Gold_Point = Symmetry_Point = 0;

	iteration = 0;

	Target_Fun = NULL;//Ŀ�꺯��
}
/*
	����ƽ�ָ��ͶԳƵ�
*/
void GSM::Cal_Gold_Sym_Point()
{
	Gold_Point = Cur_Inter_left + (sqrt(5) - 1) / 2 * (Cur_Inter_right - Cur_Inter_left);
	Symmetry_Point = Cur_Inter_left + (3 - sqrt(5)) / 2 * (Cur_Inter_right - Cur_Inter_left);
	iteration++;
}
/*
	�Ƚϻƽ�ָ��ͶԳƵ�ĺ���ֵ�����Ҹ����������䳤��
*/
void GSM::Compare_Point()
{
	if (!Target_Fun)
	{
		throw "���ȶ���һ��Ŀ�꺯��" ;
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
	�ж����������Ƿ����㾫��Ҫ��
*/
bool GSM::Judge()
{
	return abs(Cur_Inter_right - Cur_Inter_left) / abs(Init_Inter_right - Init_Inter_left) < Precision ? true : false;
}

/*
	���г���
*/
Inter_type* GSM::Execute()
{
	Inter_type* r = new Inter_type;
	if (Judge())
	{
		std::cout << "��ʼ�����������㾫��Ҫ��" << std::endl;
		r[0] = Cur_Inter_left;
		r[1] = Cur_Inter_right;
		return r;
	}
	std::cout << "��ʼ�������䲻���㾫��Ҫ�󣬿�ʼһά����" << std::endl;
	for (;;)
	{
		Cal_Gold_Sym_Point();
		Compare_Point();
		std::cout << "��" << iteration << "�ε���" << std::endl;
		std::cout << "��������Ϊ" << "[" << Cur_Inter_left << "," << Cur_Inter_right << "]" << std::endl;
		std::cout << "����Ϊ:" << abs(Cur_Inter_right - Cur_Inter_left) / abs(Init_Inter_right - Init_Inter_left) << std::endl;
		if (Judge())
		{
			std::cout << "�������������㾫��Ҫ��" << std::endl;
			r[0] = Cur_Inter_left;
			r[1] = Cur_Inter_right;
			break;
		}
		std::cout<<std::endl;
	}
	return r;
}