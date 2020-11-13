#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define Before -1 //resize position
#define After 1 //resize position
#define NO "no" //whether transpose

class matrix {
public:
	class location {
	public:
		unsigned row, col;
		location(const location& origin) :row(origin.row), col(origin.col) {}
		location(unsigned i, unsigned j) :row(i), col(j) {}
	};
	class particular {
	public:
		location loc;
		double value, absvalue;
		particular(const particular& origin) :loc(origin.loc), value(origin.value), absvalue(origin.absvalue) {}
		particular(location loc, double value) :loc(loc), value(value) { absvalue = fabs(value); }
		particular(unsigned i, unsigned j, double value) :loc(i, j), value(value) { absvalue = fabs(value); }
	};

	inline matrix();
	matrix(const matrix& origin);
	matrix(const matrix& origin,
		unsigned start_row, unsigned start_col,
		unsigned end_row_next, unsigned end_col_next);
	typedef const char* path;
	matrix(path file, unsigned nlines = 0U, unsigned nlists = 0U);
	matrix(double num, unsigned nsquare = 1U);
	matrix(double num, unsigned nrows, unsigned ncols);
	matrix(void* ary, unsigned n, bool transpose = false);
	matrix(void** ary, unsigned nlines, unsigned nlists, bool transpose = false);
	
	//template <typename Type> matrix(const Type[10] * ary, unsigned nlines, unsigned nlists, transpose trsp = false);
	~matrix();

	inline double* operator[](unsigned i);
	typedef int position;
	void append(location loc, position pos = After, unsigned nrows = 0U, unsigned ncols = 0U);
	void remove(location loc, position pos = After, unsigned nrows = 0U, unsigned ncols = 0U);
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
	double** point;
	unsigned nrows, ncols;
	particular max, min;
	void max_and_min();
	void create(
		const matrix& origin,
		unsigned start_row, unsigned start_col,
		unsigned end_row_next, unsigned end_col_next);
};

inline matrix::matrix() :
	point(NULL), nrows(1U), ncols(1U), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	point = new double*;
	*point = new double;
	**point = 0.0;
}

matrix::matrix(const matrix& origin) :
	point(NULL), nrows(origin.nrows), ncols(origin.ncols), max(origin.max), min(origin.min)
{
	create(origin, 0U, 0U, nrows, ncols);
}

matrix::matrix(const matrix& origin,
	unsigned start_row, unsigned start_col,
	unsigned end_row_next, unsigned end_col_next) :
	point(NULL), nrows(end_row_next - start_row), ncols(end_col_next - start_col),
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	create(origin, start_row, start_col, end_row_next, end_col_next);
	max_and_min();
}

matrix::matrix(path file, unsigned nlines, unsigned nlists) :
	nrows(nlines), ncols(nlists), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	ifstream ifile(file);
	if (!ifile) {
		cout << "can't find file\n";
		point = new double*;
		*point = new double;
		**point = 0.0;
		return;
	}
	if (!nrows)
		ifile >> nrows;
	if (!ncols)
		ifile >> ncols;

	point = new double* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new double[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
			//string temp;
			ifile >> point[i][j];
		}
	}
	ifile.close();
	max_and_min();
}

//template<typename Type>
matrix::matrix(double num, unsigned nsquare) :
	point(NULL), nrows(nsquare), ncols(nsquare), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	point = new double* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new double[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
			point[i][j] = 0;
		}
		point[i][i] = (double)num;
	}
	max_and_min();
}

//template<typename Type>
matrix::matrix(double num, unsigned nlines, unsigned nlists) :
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	nrows = nlines, ncols = nlists;
	point = new double* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new double[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
			point[i][j] = (double)num;
		}
	}
}

//template<typename Type>
matrix::matrix(void* ary, unsigned n, bool transpose) :
	nrows(1U), ncols(1U), max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	unsigned i, j;
	if (!transpose) {
		ncols = n;
		point = new double*;
		*point = new double[ncols];
		for (j = 0U; j < ncols; j++) {
			(*point)[j] = ((double*)ary)[j];
		}
	}
	else {
		nrows = n;
		point = new double* [nrows];
		for (i = 0U; i < n; i++) {
			point[i] = new double;
			*(point[i]) = ((double*)ary)[i];
		}
	}
	max_and_min();
}

//template<typename Type>
matrix::matrix(void** ary, unsigned nlines, unsigned nlists, bool transpose) :
	max(0U, 0U, 0.0), min(0U, 0U, 0.0)
{
	unsigned i, j;
	if (!transpose) {
		nrows = nlines, ncols = nlists;
		point = new double* [nrows];
		for (i = 0U; i < nrows; i++) {
			point[i] = new double[ncols];
			for (j = 0U; j < ncols; j++) {
				point[i][j] = ((double**)ary)[i][j];
			}
		}
	}
	else {
		nrows = nlists, ncols = nlines;
		point = new double* [nrows];
		for (i = 0U; i < nrows; i++) {
			point[i] = new double[ncols];
			for (j = 0U; j < ncols; j++) {
				point[i][j] = ((double**)ary)[j][i];
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

inline double* matrix::operator[](unsigned i)
{
	return point[i];
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

void matrix::create(const matrix& origin,
	unsigned start_row, unsigned start_col,
	unsigned end_row_next, unsigned end_col_next)
{
	point = new double* [nrows];
	for (unsigned i = 0U; i < nrows; i++) {
		point[i] = new double[ncols];
		for (unsigned j = 0U; j < ncols; j++) {
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
				max = particular(i, j, point[i][j]);
			}
			if (fabs(point[i][j]) < min.absvalue) {
				min = particular(i, j, point[i][j]);
			}
		}
	}
}
