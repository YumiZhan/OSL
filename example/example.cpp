#include <iostream>
#include "..\Number\number.h"
using namespace std;
using namespace osl;

int main()
{
	complex num("0.0");
	cout << cos(num) << endl;
	return 0;
}