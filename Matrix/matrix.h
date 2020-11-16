#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define NO false
#define YES true
typedef double elemtype;

class matrix {
private:
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
	inline matrix(const matrix& origin);
	inline matrix(const matrix& origin,
		unsigned start_row, unsigned start_col,
		unsigned nrows, unsigned ncols);
	typedef const char* path;
	matrix(path file, unsigned nrows, unsigned ncols);
	inline matrix(unsigned nsquare = 1U, elemtype num = 0.0);
	inline matrix(unsigned nrows, unsigned ncols, elemtype num = 0.0);
	matrix(void* ary, unsigned n, bool transpose = NO);
	matrix(void** ary, unsigned nlines, unsigned nlists, bool transpose = NO);
	~matrix();

	inline elemtype* operator[](unsigned i);
	typedef int position;
	inline void insert(unsigned lct_i, unsigned lct_j, 
		unsigned inst_rows = 1U, unsigned inst_cols = 0U, elemtype fillnumber = 0.0);
	void insert_rows(unsigned lct_i, unsigned inst_rows = 1U, elemtype fillnumber = 0.0);
	void insert_cols(unsigned lct_j, unsigned inst_cols = 1U, elemtype fillnumber = 0.0);
	inline void remove(unsigned lct_i, unsigned lct_j, int rmv_rows = 1, int rmv_cols = 0);
	void remove_rows(unsigned lct_i, int rmv_rows = 1);
	void remove_cols(unsigned lct_j, int rmv_cols = 1);
	void print(unsigned start_row = 0U, unsigned start_col = 0U,
		unsigned print_nrows = 0U, unsigned print_ncols = 0U);

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
	inline void empty_matrix(bool showtip = NO);
	void normal_matrix(unsigned nrows, unsigned ncols, elemtype num = 0.0);
	void submatrix(const matrix& origin, unsigned start_row, unsigned start_col, unsigned nrows, unsigned ncols);
	inline void expmatrix(unsigned nrows, unsigned ncols, const matrix& origin, 
		unsigned start_row, unsigned start_col, elemtype num = 0.0);
	void max_and_min();
};

inline matrix::matrix() :
	point(NULL), nrows(1U), ncols(1U), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	empty_matrix();
}

inline matrix::matrix(const matrix& origin) :
	max(origin.max), min(origin.min)
{
	submatrix(origin, 0U, 0U, origin.nrows, origin.ncols);
}

inline matrix::matrix(const matrix& origin,
	unsigned start_row, unsigned start_col,
	unsigned nrows, unsigned ncols) :
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	if (nrows <= origin.nrows) {
		submatrix(origin, start_row, start_col, nrows, ncols);
	}
	else {
		expmatrix(nrows, ncols, origin, start_row, start_col, 0.0);
	}
	max_and_min();
}

matrix::matrix(path file, unsigned nlines, unsigned nlists) :
	nrows(nlines), ncols(nlists), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	ifstream ifile(file);
	if (!ifile) {
		cout << "can't find file\n";
		empty_matrix();
		return;
	}
	if (!nrows)
		ifile >> nrows;
	if (!ncols)
		ifile >> ncols;

	if (nrows == 0 || ncols == 0) {
		cout << "nrows(" << nrows << "), ncols(" << ncols << ")\n";
		empty_matrix(YES);
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

inline matrix::matrix(unsigned nsquare, elemtype num) :
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	normal_matrix(nsquare, nsquare, num);
}

inline matrix::matrix(unsigned nrows, unsigned ncols, elemtype num) :
	max(0U, 0U, num), min(0U, 0U, num)
{
	normal_matrix(nrows, ncols, num);
}

matrix::matrix(void* ary, unsigned n, bool transpose) :
	nrows(1U), ncols(1U), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	if (n == 0) {
		cout << "n(0)\n";
		empty_matrix(YES);
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
		cout << "nlines(" << nlines << "), nlists(" << nlists << ")\n";
		empty_matrix(YES);
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
		cout << "lct_i(" << lct_i << ") > nrows(" << nrows << ")\n";
		inst_rows += lct_i - nrows;
		lct_i = nrows;
		cout << "set lct_i = " << lct_i << ", inst_rows = " << inst_rows << endl;
	}
	nrows += inst_rows;
	elemtype** newpoint = new elemtype* [nrows];
	unsigned i, j;
	for (i = 0; i < lct_i; i++) {
		newpoint[i] = new elemtype[ncols];
		for (j = 0; j < ncols; j++) {
			newpoint[i][j] = point[i][j];
		}
		delete[] point[i];
	}
	for (i = lct_i; i < lct_i + inst_rows; i++) {
		newpoint[i] = new elemtype[ncols];
		for (j = 0; j < ncols; j++) {
			newpoint[i][j] = fillnumber;
		}
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
		cout << "lct_j(" << lct_j << ") > ncols(" << ncols << ")\n";
		inst_cols += lct_j - ncols;
		lct_j = ncols;
		cout << "set lct_j = " << ncols << ", inst_cols = " << inst_cols << endl;
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

void matrix::remove_rows(unsigned lct_i, int rmv_rows)
{
	if (rmv_rows == 0)
		return;
	int Direction = -1;
	if (rmv_rows > 0) {
		Direction = 1;
	}
	rmv_rows = abs(rmv_rows);
	nrows -= rmv_rows;
	elemtype** newpoint = new elemtype* [nrows];
	unsigned i, j;
	if (Direction == -1) {
		if (unsigned(rmv_rows) > lct_i) {
			cout << "rmv_rows(" << rmv_rows << ") > lct_i(" << lct_i << ")\n";
			rmv_rows = lct_i - 1;
			cout << "set rmv_rows = " << rmv_rows << endl;
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
			cout << "rmv_rows(" << rmv_rows << " > nrows - lct_i(" << nrows - lct_i << ")\n";
			rmv_rows = nrows - lct_i;
			cout << "set rmv_rows = " << rmv_rows << endl;
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
	int Direction = -1;
	if (rmv_cols > 0) {
		Direction = 1;
	}
	rmv_cols = abs(rmv_cols);
	ncols -= rmv_cols;
	elemtype** newpoint = new elemtype* [ncols];
	unsigned i, j;
	if (Direction == -1) {
		if (unsigned(rmv_cols) > lct_j) {
			cout << "rmv_cols(" << rmv_cols << ") > lct_j(" << lct_j << ")\n";
			rmv_cols = lct_j - 1;
			cout << "set rmv_cols = " << rmv_cols << endl;
		}
		for (i = 0; i < nrows; i++) {
			for (j = 0; j < lct_j; j++) {
				newpoint[i][j] = point[i][j];
			}
			for (j = lct_j + rmv_cols; j < ncols; j++) {
				newpoint[i][j] = point[i][j + rmv_cols];
			}
			delete[] point[i];
		}
	}
	else {
		if (unsigned(rmv_cols) > nrows - lct_j) {
			cout << "rmv_cols(" << rmv_cols << " > nrows - lct_j(" << nrows - lct_j << ")\n";
			rmv_cols = nrows - lct_j;
			cout << "set rmv_cols = " << rmv_cols << endl;
		}
		for (i = 0; i < nrows; i++) {
			for (j = 0; j < lct_j - rmv_cols; j++) {
				newpoint[i][j] = point[i][j];
			}
			for (j = lct_j; j < ncols; j++) {
				newpoint[i][j] = point[i][j + rmv_cols];
			}
			delete[] point[i];
		}
	}
	delete[] point;
	point = newpoint;
	newpoint = NULL;
	max_and_min();
	return;
}

void matrix::print(unsigned start_row, unsigned start_col, unsigned print_nrows, unsigned print_ncols)
{
	if (start_row >= nrows) {
		start_row = nrows - 1;
	}
	if (start_col >= ncols) {
		start_col = ncols - 1;
	}
	if (print_nrows == 0 || start_row + print_nrows > nrows) {
		print_nrows = nrows - start_row;
	}
	if (print_ncols == 0 || start_col + print_ncols > ncols) {
		print_ncols = ncols - start_col;
	}
	for (unsigned i = start_row; i < start_row + print_nrows; i++) {
		for (unsigned j = start_col; j < start_col + print_ncols; j++) {
			cout << point[i][j];
			if (j != start_col + print_ncols - 1)
				cout << '\t';
		}
		cout << endl;
	}
}

inline void matrix::empty_matrix(bool showtip)
{
	if (showtip == YES)
		cout << "the matrix is created as a 1¡Á1 matrix\n";
	point = new elemtype*;
	*point = new elemtype;
	**point = 0.0;
	nrows = 1, ncols = 1;
	max = particular(0, 0, 0.0);
	min = particular(0, 0, 0.0);
}

void matrix::normal_matrix(unsigned nrows, unsigned ncols, elemtype num)
{
	if (nrows == 0 || ncols == 0) {
		cout << "nrows(" << nrows << "), ncols(" << nrows << ")\n";
		empty_matrix(YES);
		return;
	}
	this->nrows = nrows, this->ncols = ncols;
	point = new elemtype * [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new elemtype[this->ncols];
		for (unsigned j = 0U; j < this->ncols; j++) {
			point[i][j] = num;
		}
	}
}

void matrix::submatrix(const matrix& origin, unsigned start_row, unsigned start_col, unsigned nrows, unsigned ncols)
{
	if (nrows == 0 || ncols == 0) {
		cout << "nrows(" << nrows << "), ncols(" << ncols << ")\n";
		empty_matrix(YES);
		return;
	}
	if (start_row >= origin.nrows) {
		cout << "start_row(" << start_row << ") >= origin.nrows(" << origin.nrows << ")\n";
		empty_matrix(YES);
		return;
	}
	if (start_col >= origin.ncols) {
		cout << "start_col(" << start_col << ") >= origin.ncols(" << origin.ncols << ")\n";
		empty_matrix(YES);
	}
	if (start_row + nrows > origin.nrows) {
		cout << "start_row + nrows(" << start_row + nrows << ") >= origin.nrows(" << origin.nrows << ")\n";
		nrows = origin.nrows - start_row - 1;
		cout << "set nrows = " << nrows << endl;
	}
	if (start_col + ncols > origin.ncols) {
		cout << "start_col + ncols(" << start_col + ncols << ") >= origin.ncols(" << origin.ncols << ")\n";
		ncols = origin.ncols - start_col - 1;
		cout << "set ncols = " << ncols << endl;
	}
	this->nrows = nrows;
	this->ncols = ncols;
	point = new elemtype* [nrows];
	for (unsigned i = 0; i < nrows; i++) {
		point[i] = new elemtype[ncols];
		for (unsigned j = 0; j < ncols; j++) {
			point[i][j] = (origin.point)[i + start_row][j + start_col];
		}
	}
	max_and_min();
}

inline void matrix::expmatrix(unsigned nrows, unsigned ncols, const matrix& origin,
	unsigned lct_i, unsigned lct_j, elemtype num)
{
	normal_matrix(nrows, ncols, num);
	insert(lct_i, lct_j, origin.nrows, origin.ncols, num);
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