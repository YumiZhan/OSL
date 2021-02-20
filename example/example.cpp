#include <iostream>
#include "..\Number\number.h"
using namespace std;
using namespace osl;

int main()
{
	real num(3);
	num ^= 2;
	cout << num << endl;
	return 0;
}