#include <iostream>
#include "..\Number\number.h"
using namespace std;
using namespace osl;
// double PI = 3.14;

int main()
{
	double denominator(1000.0), numerator(0.0);
	simplify_fraction(denominator, numerator);
	cout << denominator << '\t' << numerator << endl;
	return 0;
}