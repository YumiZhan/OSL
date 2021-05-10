#include <iostream>
#include "..\Number\number.h"
#include "..\Matrix\matrix.h"
using namespace std;
using namespace osl;

int main()
{
	double b[] = { 1, 2, 3 };
	matrix<double> a(b, 3, 2);
	cout << a[1] << endl;
	return 0;
}