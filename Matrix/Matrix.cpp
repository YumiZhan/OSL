// Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "matrix.h"
#include <typeinfo>

int main()
{
	
	double** a = new double* [3];
	for (unsigned i = 0; i < 3; i++) {
		a[i] = new double[3];
		for (unsigned j = 0; j < 3; j++) {
			a[i][j] = (i + 1) * (j + 1);
		}
	}
	matrix m1((void**)a, 3U, 3U, NO);
	for (unsigned i = 0; i < 3; i++) {
		delete[] a[i];
	}
	delete[] a;
	matrix m2(3.0, 3U, 3U);
	matrix m3("matrix.txt");
	matrix m4("matrix.txt", 1, 2);
	double* p = new double[4];
	for (unsigned i = 0; i < 4; i++) {
		p[i] = i + 1;
	}
	matrix m5(p, 4);
	m1.print();
	m2.print();
	m3.print();
	m4.print();
	m5.print();
	return 0;
}
/*
double string_to_double(const string& str)
{
	char sign = '+';
	if(str[0])
	size_t length = str.length();
	size_t i;
	double result = 0;
	for (i = 0; i < length; i++) {
		if (str[length - 1 - i] == '.') {
			i++;
			goto Intiger;
		}
		result += str[length - 1 - i] - '0' + 0.1 * result;
	}
	return result;
Intiger:
	double integer;
	for(integer = 0;)
}*/
/*
void Add(const matrix& matrix1, const matrix& matrix2, matrix& result)
{
	unsigned max_nrows = matrix1.nrows > matrix2.nrows ? matrix1.nrows : matrix2.nrows;
	unsigned max_ncols = matrix1.ncols > matrix2.ncols ? matrix1.ncols : matrix2.ncols;
	for (unsigned i = 0; i < N_ROW; i++) {
		for (unsigned j = 0; j < N_COL; j++) {
			(result.point)[i][j] = (matrix1.point)[i][j] + (matrix2.point)[i][j];
		}
	}
}

inline matrix operator+(const matrix& matrix1, const matrix& matrix2)
{
	matrix result;
	Add(matrix1, matrix2, result);
	return result;
}

void Subtract(const matrix& matrix1, const matrix& matrix2, matrix& result)
{
}

inline matrix operator-(const matrix& matrix1, const matrix& matrix2)
{}

void Multiply(const matrix& matrix1, const matrix& matrix2, matrix& result)
{
}

inline matrix operator*(const matrix& matrix1, const matrix& matrix2)
{}

void Inverse(const matrix& origin, matrix& result)
{
}

inline matrix operator/(const matrix& matrix1, const matrix& matrix2)
{}
*/