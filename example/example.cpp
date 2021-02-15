#include <iostream>
#include "..\Number\number.h"
using namespace std;
using namespace osl;

int main()
{
	real hello(1);
	hello.console_print();
	complex cpl(1, -1);
	cpl.mul(1, 1);
	cpl.console_print_rect();
	return 0;
}