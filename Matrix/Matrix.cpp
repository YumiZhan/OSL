// Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "matrix.h"
#include <typeinfo>

int main()
{
	if (-1)cout << -1;
	return 0;
}

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