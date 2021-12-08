#include<iostream>
#include "GSM.h"

using namespace std;

Inter_type Target_Fun(Inter_type x);

Inter_type Params[3] = {0.238, 0, 3};

int main(int argc, char* argv)
{
	GSM Person(Params);
	Person.Target_Fun = Target_Fun;
	Inter_type* Intervals = new Inter_type;
	Intervals = Person.Execute();
	return 0;
}

Inter_type Target_Fun(Inter_type x)
{
	return pow(x, 3) - 2 * x + 1;
}