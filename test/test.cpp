#include <iostream>
#include "..\Number\number.h"
#include "..\Matrix\matrix.h"
using namespace std;
using namespace osl;

int main()
{
	double b[] = { 1, 2, 3 };
	matrix<double> a(b, 3, 2);
	element<double> c(a.MAX());
	cout << c.value << c.row << c.col << endl;
	return 0;
}