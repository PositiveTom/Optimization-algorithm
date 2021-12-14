#include<iostream>
#include "GSM.h"
#include<cmath>
#include "Incremental_heuristic.h"


using namespace std;

Inter_type Target_Fun(Inter_type x);

Inter_type Params[3] = {0.238, 0, 3};

int main(int argc, char* argv)
{
	GSM Person(Params);
	Person.Target_Fun = Target_Fun;
	Inter_type* Intervals = new Inter_type;
	Intervals = Person.Execute();

	double x0 = 0;
	double h = 1;
	IH dog(x0, h, Target_Fun);

	dog.Excute();

	system("pause");
	return 0;
}

Inter_type Target_Fun(Inter_type x)
{
	return pow(x, 3) - 2 * x + 1;
}