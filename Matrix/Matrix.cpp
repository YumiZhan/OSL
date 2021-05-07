// matrix.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "matrix.h"

template<class elm>
inline osl::matrix<elm>::matrix() :
	nrow(0), ncol(0), point(NULL)
{}

template<class elm>
osl::matrix<elm>::matrix(agm_mtr origin) :
	nrow(origin.nrow), ncol(origin.ncol)
{
	point = new vector<elm>[nrow];
	if (point == NULL) {
		throw exception::matrix(0U, "matrix::matrix(agm_mtr origin)");
	}
	//!! try
	for (int i(0); i < nrow; i++) {
		point[i] = new vector<elm>(origin.point[i]);
	}
}

template<class elm>
osl::matrix<elm>::matrix(agm_mtr origin, int start_row, int start_col, int end_row, int end_col)
{
	if (start_row > end_row || start_col > end_col) {
		throw exception::matrix(5U, "matrix::matrix(agm_mtr origin, int start_row, int start_col, int end_row, int end_col)");
	}
	if (start_row < 0 || start_col < 0 || end_row > origin.nrow || end_col > origin.ncol) {
		throw exception::matrix(2U, "matrix::matrix(agm_mtr origin, int start_row, int start_col, int end_row, int end_col)");
	}
	nrow = end_row + 1 - start_row; ncol = end_col + 1 - start_col;
	point = new vector<elm>[nrow];
	for (int i(0); i < nrow; i++) {
		point[i] = new vector<elm>(ncol);
		for (int j(0); j < ncol; j++) {
			point[i][j] = origin.point[i + start_row][j + start_col];
		}
	}
}

template<class elm>
osl::matrix<elm>::~matrix()
{
	if (point != NULL) {
		for (int i(0); i < ncol; i++) {
			if (point[i] != NULL) {
				delete[] point[i];
			}
		}
		delete[] point;
	}
}
