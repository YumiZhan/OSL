#include <iostream>
#include "..\Number\number.h"
#include "..\Matrix\matrix.h"
using namespace std;
using namespace osl;

int main()
{
	vector<> b(2, 3);
	try {
		b.at(2);
	} catch(const exc_matrix& exc){
		cout << exc.overview() << endl << exc.discription << endl;
	}
	return 0;
}