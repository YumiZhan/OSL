#include <iostream>
#include "..\Number\number.h"
#include "..\Matrix\matrix.h"
using namespace std;
using namespace osl;

int main()
{
	double b[] = { 1, 2, 3 };
	matrix<double> a(b, 3, 2);
	try {
		cout << a.at(1, 3) << endl;
	}
	catch (exc::matrix excm) {
		cout << excm.discription << endl << excm.overview() << endl;
	}
	return 0;
}