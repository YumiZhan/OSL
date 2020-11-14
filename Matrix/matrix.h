#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define NO false
typedef double elemtype;

class matrix {
	class particular {
	public:
		inline particular(const particular& origin) :
			row(origin.row), col(origin.col), value(origin.value) { absvalue = fabs(origin.value); }
		inline particular(unsigned row, unsigned col, elemtype value) :
			row(row), col(col), value(value) { absvalue = fabs(value); }
		unsigned row, col;
		elemtype value, absvalue;
	};

public:
	inline matrix();
	matrix(const matrix& origin);
	matrix(const matrix& origin,
		unsigned start_row, unsigned start_col,
		unsigned end_row_next, unsigned end_col_next);
	typedef const char* path;
	matrix(path file, unsigned nlines = 0U, unsigned nlists = 0U);
	matrix(elemtype num, unsigned nsquare = 1U);
	matrix(elemtype num, unsigned nrows, unsigned ncols);
	matrix(void* ary, unsigned n, bool transpose = NO);
	matrix(void** ary, unsigned nlines, unsigned nlists, bool transpose = NO);
	~matrix();

	inline elemtype* operator[](unsigned i);
	typedef int position;
	inline void insert(unsigned lct_i, unsigned lct_j, 
		unsigned inst_rows = 1U, unsigned inst_cols = 0U, elemtype fillnumber = 0.0);
	void insert_rows(unsigned lct_i, unsigned inst_rows = 0U, elemtype fillnumber = 0.0);
	void insert_cols(unsigned lct_j, unsigned inst_cols = 0U, elemtype fillnumber = 0.0);
	inline void remove(unsigned lct_i, unsigned lct_j, int rmv_rows = 1, int rmv_cols = 0);
	void remove_rows(unsigned lct_i, int rmv_rows = 1);
	void remove_cols(unsigned lct_j, int rmv_cols = 1);
	void print();

	friend void Add(
		const matrix& matrix1, const matrix& matrix2,
		matrix& result, unsigned start_row, unsigned start_col);
	friend void Subtract(
		const matrix& matrix1, const matrix& matrix2,
		matrix& result, unsigned start_row, unsigned start_col);
	friend void Multiply(
		const matrix& matrix1, const matrix& matrix2,
		matrix& result, unsigned start_row, unsigned start_col);
	friend void Invert(
		const matrix& origin,
		matrix& result, unsigned start_row, unsigned start_col);
	friend void Overwrite(const matrix& origin, matrix& result);

private:
	elemtype** point;
	unsigned nrows, ncols;
	particular max, min;
	inline void emptymatrix();
	void submatrix(
		const matrix& origin,
		unsigned start_row, unsigned start_col,
		unsigned end_row_next, unsigned end_col_next);
	void max_and_min();
};

inline matrix::matrix() :
	point(NULL), nrows(1U), ncols(1U), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	point = new elemtype*;
	*point = new elemtype;
	**point = 0.0;
}

matrix::matrix(const matrix& origin) :
	max(origin.max), min(origin.min)
{
	submatrix(origin, 0U, 0U, nrows, ncols);
}

matrix::matrix(const matrix& origin,
	unsigned start_row, unsigned start_col,
	unsigned end_row_next, unsigned end_col_next) :
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	submatrix(origin, start_row, start_col, end_row_next, end_col_next);
	max_and_min();
}

matrix::matrix(path file, unsigned nlines, unsigned nlists) :
	nrows(nlines), ncols(nlists), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	ifstream ifile(file);
	if (!ifile) {
		cout << "can't find file\n";
		emptymatrix();
		return;
	}
	if (!nrows)
		ifile >> nrows;
	if (!ncols)
		ifile >> ncols;

	if (nrows == 0 || ncols == 0) {
		cout << "nrows : " << nrows << "ncols : " << ncols << endl;
		emptymatrix();
		return;
	}
	point = new elemtype* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new elemtype[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
			ifile >> point[i][j];
		}
	}
	ifile.close();
	max_and_min();
}

matrix::matrix(elemtype num, unsigned nsquare) :
	point(NULL), nrows(nsquare), ncols(nsquare), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	if (nsquare == 0) {
		cout << "nsquare : 0\n";
		emptymatrix();
		return;
	}
	point = new elemtype* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new elemtype[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
			point[i][j] = 0;
		}
		point[i][i] = (elemtype)num;
	}
	max_and_min();
}

matrix::matrix(elemtype num, unsigned nlines, unsigned nlists) :
	max(0U, 0U, num), min(0U, 0U, num)
{
	if (nlines == 0 || nlists == 0) {
		cout << "nlines: " << nlines << ", nlists: " << nlists << endl;
		emptymatrix();
		return;
	}
	nrows = nlines, ncols = nlists;
	point = new elemtype* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new elemtype[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
			point[i][j] = (elemtype)num;
		}
	}
}

matrix::matrix(void* ary, unsigned n, bool transpose) :
	nrows(1U), ncols(1U), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	if (n == 0) {
		cout << "n : 0\n";
		emptymatrix();
		return;
	}
	unsigned i, j;
	if (!transpose) {
		ncols = n;
		point = new elemtype*;
		*point = new elemtype[ncols];
		for (j = 0U; j < ncols; j++) {
			(*point)[j] = ((elemtype*)ary)[j];
		}
	}
	else {
		nrows = n;
		point = new elemtype* [nrows];
		for (i = 0U; i < n; i++) {
			point[i] = new elemtype;
			*(point[i]) = ((elemtype*)ary)[i];
		}
	}
	max_and_min();
}

matrix::matrix(void** ary, unsigned nlines, unsigned nlists, bool transpose) :
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	/**/
	if (nlines == 0 || nlists == 0) {
		cout << "nlines : " << nlines << "nlists : " << nlists << endl;
		emptymatrix();
		return;
	}
	unsigned i, j;
	if (!transpose) {
		nrows = nlines, ncols = nlists;
		point = new elemtype* [nrows];
		for (i = 0U; i < nrows; i++) {
			point[i] = new elemtype[ncols];
			for (j = 0U; j < ncols; j++) {
				point[i][j] = ((elemtype**)ary)[i][j];
			}
		}
	}
	else {
		nrows = nlists, ncols = nlines;
		point = new elemtype* [nrows];
		for (i = 0U; i < nrows; i++) {
			point[i] = new elemtype[ncols];
			for (j = 0U; j < ncols; j++) {
				point[i][j] = ((elemtype**)ary)[j][i];
			}
		}
	}
	max_and_min();
}

matrix::~matrix()
{
	for (unsigned i = 0U; i < nrows; i++) {
		delete[] point[i];
	}
	delete[] point;
	point = NULL;
}

inline elemtype* matrix::operator[](unsigned i)
{
	return point[i];
}

inline void matrix::insert(unsigned lct_i, unsigned lct_j, unsigned inst_rows, unsigned inst_cols, elemtype fillnumber)
{
	if (inst_rows) {
		insert_rows(lct_i, inst_rows, fillnumber);
	}
	if (inst_cols) {
		insert_cols(lct_j, inst_cols, fillnumber);
	}
	return;
}

void matrix::insert_rows(unsigned lct_i, unsigned inst_rows, elemtype fillnumber)
{
	if (inst_rows == 0)return;
	if (lct_i > nrows) {
		cout << "lct_i : " << lct_i << ", is larger than nrows: " << nrows << endl;
		cout << "let lct_i = " << nrows << endl;
		lct_i = nrows;
	}
	nrows += inst_rows;
	elemtype** newpoint = new elemtype* [nrows];
	unsigned i, j;
	for (i = 0; i < inst_rows; i++) {
		newpoint[i] = new elemtype[ncols];
		for (j = 0; j < ncols; j++) {
			newpoint[i][j] = point[i][j];
		}
		delete[] point[i];
	}
	for (i = inst_rows; i < lct_i + inst_rows; i++) {
		newpoint[i] = new elemtype[ncols];
		for (j = 0; j < ncols; j++) {
			newpoint[i][j] = fillnumber;
		}
		delete[] point[i];
	}
	for (i = lct_i + inst_rows; i < nrows; i++) {
		newpoint[i] = new elemtype[ncols];
		for (j = 0; j < ncols; j++) {
			newpoint[i][j] = point[i - inst_rows][j];
		}
		delete[] point[i];
	}
	delete[] point;
	point = newpoint;
	newpoint = NULL;
	max_and_min();
	return;
}

void matrix::insert_cols(unsigned lct_j, unsigned inst_cols, elemtype fillnumber)
{
	if (inst_cols == 0)return;
	if (lct_j > ncols) {
		cout << "lct_j : " << lct_j << ", is larger than ncols: " << ncols << endl;
		cout << "let lct_j = " << ncols << endl;
		lct_j = ncols;
	}
	ncols += inst_cols;
	unsigned i, j;
	for (i = 0; i < nrows; i++) {
		elemtype* newpoint = new elemtype[ncols];
		for (j = 0; j < lct_j; j++) {
			newpoint[j] = point[i][j];
		}
		for (j = lct_j; j < lct_j + inst_cols; j++) {
			newpoint[j] = fillnumber;
		}
		for (j = lct_j + inst_cols; j < ncols; j++) {
			newpoint[j] = point[i][j - inst_cols];
		}
		delete[] point[i];
		point[i] = newpoint;
		newpoint = NULL;
	}
	max_and_min();
	return;
}

inline void matrix::remove(unsigned lct_i, unsigned lct_j, int rmv_rows, int rmv_cols)
{
	if (rmv_rows) {
		remove_rows(lct_i, rmv_rows);
	}
	if (rmv_cols) {
		remove_cols(lct_i, rmv_cols);
	}
	return;
}

#define Forward 1
#define Backward -1
void matrix::remove_rows(unsigned lct_i, int rmv_rows)
{
	if (rmv_rows == 0)return;
	int Direction = Backward;
	if (rmv_rows > 0) {
		Direction = Forward;
	}
	rmv_rows = abs(rmv_rows);
	nrows -= rmv_rows;
	elemtype** newpoint = new elemtype* [nrows];
	unsigned i, j;
	if (Direction == Backward) {
		if (unsigned(rmv_rows) > lct_i) {
			cout << "rmv_rows : " << rmv_rows <<
				" is larger than the number of element before lct_i" << lct_i;
			rmv_rows = lct_i - 1;
			cout << "\nset rmv_rows = " << rmv_rows << endl;
		}
		for (i = 0; i < lct_i - rmv_rows; i++) {
			for (j = 0; j < ncols; j++) {
				newpoint[i][j] = point[i][j];
			}
			delete[] point[i];
		}
		for (i = lct_i - rmv_rows; i < lct_i; i++) {
			delete[] point[i];
		}
		for (i = lct_i; i < nrows; i++) {
			for (j = 0; j < ncols; j++) {
				newpoint[i][j] = point[i + rmv_rows][j];
			}
			delete[] point[i + rmv_rows];
		}
	}
	else {
		if (unsigned(rmv_rows) > nrows - lct_i) {
			cout << "rmv_rows : " << rmv_rows <<
				" is larger than the number of element after(inlude) lct_i " << nrows - lct_i;
			rmv_rows = nrows - lct_i;
			cout << "\nset rmv_rows = " << rmv_rows << endl;
		}
		for (i = 0; i < lct_i; i++) {
			newpoint[i] = new elemtype[ncols];
			for (j = 0; j < ncols; j++) {
				newpoint[i][j] = point[i][j];
			}
			delete[] point[i];
		}
		for (i = lct_i; i < lct_i + rmv_rows; i++) {
			delete[] point[i];
		}
		for (i = lct_i + rmv_rows; i < nrows; i++) {
			for (j = 0; j < ncols; j++) {
				newpoint[i][j] = point[i + rmv_rows][j];
			}
			delete[] point[i - rmv_rows];
		}
	}
	delete[] point;
	point = newpoint;
	newpoint = NULL;
	max_and_min();
}

void matrix::remove_cols(unsigned lct_j, int rmv_cols)
{
	if (rmv_cols == 0)return;
	int Direction = Backward;
	if (rmv_cols > 0) {
		Direction = Forward;
	}
	rmv_cols = abs(rmv_cols);
	ncols -= rmv_cols;
	elemtype** newpoint = new elemtype* [ncols];
	unsigned i, j;
	for (i = 0; i < nrows; i++) {
		for (j = 0; j < lct_j; j++) {
			newpoint[i][j] = point[i][j];
		}
		for (j = lct_j + rmv_cols; j < ncols; j++) {
			newpoint[i][j] = point[i][j + rmv_cols];
		}
		delete[] point[i];
	}
	delete[] point;
	point = newpoint;
	newpoint = NULL;
	max_and_min();
	return;
}

void matrix::print()
{
	for (unsigned i = 0U; i < nrows; i++) {
		for (unsigned j = 0U; j < ncols; j++) {
			cout << point[i][j];
			if (j != ncols - 1)cout << '\t';
		}
		cout << endl;
	}
}

inline void matrix::emptymatrix()
{
	cout << "the matrix is created as a 1¡Á1 matrix\n";
	point = new elemtype*;
	*point = new elemtype;
	**point = 0.0;
	nrows = 1, ncols = 1;
	max = particular(0, 0, 0.0);
	min = particular(0, 0, 0.0);
}

void matrix::submatrix(const matrix& origin,
	unsigned start_row, unsigned start_col,
	unsigned end_row_next, unsigned end_col_next)
{
	if (end_row_next == start_row || end_col_next == start_col) {
		cout << "end == start, ";
		emptymatrix();
		return;
	}
	nrows = end_row_next - start_row;
	ncols = end_col_next - start_col;
	point = new elemtype* [nrows];
	for (unsigned i = 0; i < nrows; i++) {
		point[i] = new elemtype[ncols];
		for (unsigned j = 0; j < ncols; j++) {
			point[i][j] = (origin.point)[i + start_row][j + start_col];
		}
	}
}

void matrix::max_and_min()
{
	max = particular(0U, 0U, point[0][0]);
	min = particular(0U, 0U, point[0][0]);
	for (unsigned i = 0U; i < nrows; i++) {
		for (unsigned j = 0U; j < ncols; j++) {
			if (fabs(point[i][j]) > max.absvalue) {
				max.row = i, max.col = j;
				max.value = point[i][j];
				max.absvalue = abs(max.value);
			}
			if (fabs(point[i][j]) < min.absvalue) {
				min.row = i, min.col = j;
				min.value = point[i][j];
				min.absvalue = abs(min.value);
			}
		}
	}
}