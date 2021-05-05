#include <iostream>
#include "..\Number\number.h"
#include "..\Matrix\matrix.h"
using namespace std;
using namespace osl;

int main()
{
	rational a[] = { 1, 2, 3 }, b[] = { 1, 2, 3 };
	vector<rational> c(a, 3);
	vector<rational> d(b, 3);
	cout << c * d << endl;
	return 0;
}