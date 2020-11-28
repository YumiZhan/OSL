#include <iostream>
#include "..\Number\number.h"
using namespace std;

int main()
{
    real example(PI);
    cout << "example = " << example << endl
        << "fabs = " << fabs(example) << endl
        << "floor = " << floor(example) << endl
        << "numerator = " << example.numerator() << endl
        << "PI^2 = " << pow2(example) << endl;
    cout << "PI + 1 = " << example + 1.0 << endl
        << "known? = " << example.known << endl
        << "/0 = " << example / 0 << endl;
    return 0;
}
