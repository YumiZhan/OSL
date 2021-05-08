// matrix.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "matrix.h"
using osl::element;
using osl::vector;
using osl::matrix;

// Constructors & Destructor ------------------------------------------------------------

template<class elm>
matrix<elm>::matrix(int nrow, int ncol, agm_elm value) :
	_nrow(nrow), _ncol(ncol), pointer(NULL)
{
	if (_nrow > 0) {
		if (_ncol < 0) {
			throw exc::matrix(4U, "matrix(int nrow, int ncol, agm_elm value)");
		}
		pointer = new vector<elm>[_nrow];
		if (pointer == NULL) {
			throw exc::matrix(0U, "matrix(int nrow, int ncol, agm_elm value)");
		}
		if (_ncol == 0) {
			return;
		}
		for (int i(0); i < _nrow; i++) {
			try {
				pointer[i].append(ncol, value);
			}
			catch (exc::vector excv) {
				delete[] pointer;
				throw exc::matrix(excv.code, "matrix(int nrow, int ncol, agm_elm value)");
			}
		}
	}
	else if (_nrow < 0) {
		throw exc::matrix(3U, "matrix(int nrow, int ncol, agm_elm value)");
	}
}

template<class elm>
matrix<elm>::matrix(agm_mat origin) :
	_nrow(origin._nrow), _ncol(origin._ncol), pointer(NULL)
{
	if (_nrow > 0) {
		pointer = new vector<elm>[_nrow];
		if (pointer == NULL) {
			throw exc::matrix(0U, "matrix(agm_mat origin)");
		}
		if (_ncol == 0) {
			return;
		}
		for (int i(0); i < _nrow; i++) {
			try {
				pointer[i].append(origin.pointer[i]);
			}
			catch (exc::vector excv) {
				delete[] pointer;
				throw exc::matrix(excv.code, "matrix(agm_mat origin)");
			}
		}
	}
}

template<class elm>
matrix<elm>::matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col) :
	_nrow(end_row + 1 - start_row), _ncol(end_col + 1 - start_col), pointer(NULL)
{
	if (_nrow > 0) {
		if (_ncol < 0) {
			throw exc::matrix(5U, "matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col)");
		}
		pointer = new vector<elm>[_nrow];
		if (pointer == NULL) {
			throw exc::matrix(0U, "matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col)");
		}
		if (_ncol == 0) {
			return;
		}
		for (int i(0); i < _nrow; i++) {
			try {
				pointer[i].append(0.0, _ncol);
				pointer[i].cover(origin.pointer[i + start_row], start_col);
			}
			catch (exc::vector excv) {
				delete[] pointer;
				throw exc::matrix(excv.code, "matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col)");
			}
		}
	}
	else if (_nrow < 0) {
		throw exc::matrix(5U, "matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col)");
	}
}

template<class elm>
matrix<elm>::~matrix()
{
	if (pointer != NULL) {
		delete[] pointer;
	}
}

namespace {
	template <typename elm>
	void template_instantiate(const elm& value) {
		// Constructors & Destructor
		matrix<elm>* a = new matrix<elm>;
		matrix<elm>* b = new matrix<elm>(*a);
		matrix<elm>* c = new matrix<elm>(*b, 0, -1, 0, -1);
		delete a, b, c;
	}

	void instantiate() {
		template_instantiate(int(1));
		template_instantiate(double(1));
		template_instantiate(osl::rational(1));
		// template_instantiate(osl::complex(1));
	}
}