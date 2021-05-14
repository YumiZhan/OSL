#include <iostream>
#include "..\Number\number.h"
#include "..\Matrix\matrix.h"
using namespace std;
using namespace osl;

int main()
{
	matrix<double> a(3, 3);
	cin >> a;
	a.print();
	return 0;
}