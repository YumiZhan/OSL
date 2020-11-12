#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class matrix {
public:
	inline matrix();
	//matrix(ifstream& ifile, unsigned rows = 0, unsigned cols = 0);
	matrix(const matrix& origin);
	matrix(const char* file, unsigned rows = 0, unsigned cols = 0);
	template <typename Type> matrix(const Type num, const unsigned nsqare = 1);
	template <typename Type> matrix(const Type* num, const unsigned ncols);
	~matrix();

	inline double* operator[](const unsigned i);
	void print();
	friend matrix operator+(const matrix& matrix1, const matrix& matrix2);
	friend matrix operator-(const matrix& matrix1, const matrix& matrix2);
	friend matrix operator*(const matrix& matrix1, const matrix& matrix2);
	friend matrix operator/(const matrix& matrix1, const matrix& matrix2);
	
private:
	double** point;
	unsigned nrows, ncols;
};

inline matrix::matrix() :
	nrows(1), ncols(1), point(NULL)
{
	point = new double*;
	*point = new double;
	**point = 0.0;
}
/*
matrix::matrix(ifstream& ifile, unsigned rows, unsigned cols) :
	nrows(1), ncols(1), point(NULL)
{
	if (!ifile) {
		cout << "can't find file\n";
		point = new double*;
		*point = new double;
		**point = 0.0;
		return;
	}
	if (rows == 0)
		ifile >> nrows;
	else
		nrows = rows;
	if (cols == 0)
		ifile >> ncols;
	else
		ncols = cols;

	point = new double* [nrows];
	for (unsigned i = 0; i < nrows; i++) {
		*point = new double[ncols];
		for (unsigned j = 0; j < ncols; j++) {
			ifile >> point[i][j];
		}
	}
	ifile.close();
}*/

matrix::matrix(const matrix& origin) :
	nrows(origin.nrows), ncols(origin.ncols), point(NULL)
{
	point = new double* [nrows];
	for (unsigned i = 0; i < nrows; i++) {
		point[i] = new double[ncols];
		for (unsigned j = 0; j < ncols; j++) {
			point[i][j] = origin.point[i][j];
		}
	}
}

matrix::matrix(const char* pfile, unsigned rows, unsigned cols) :
	nrows(1), ncols(1), point(NULL)
{
	ifstream ifile(pfile);
	if (!ifile) {
		cout << "can't find file\n";
		point = new double*;
		*point = new double;
		**point = 0.0;
		return;
	}
	if (rows == 0)
		ifile >> nrows;
	else
		nrows = rows;
	if (cols == 0)
		ifile >> ncols;
	else
		ncols = cols;

	point = new double* [nrows];
	for (unsigned i = 0; i < nrows; i++) {
		*point = new double[ncols];
		for (unsigned j = 0; j < ncols; j++) {
			ifile >> point[i][j];
		}
	}
	ifile.close();
}

template<typename Type>
matrix::matrix(const Type num, const unsigned nsqare) :
	nrows(nsqare), ncols(nsqare), point(NULL)
{
	point = new double* [nrows];
	for (unsigned i = 0; i < nrows; i++) {
		point[i] = new double[ncols];
		for (unsigned j = 0; j < ncols; j++) {
			point[i][j] = 0;
		}
		point[i][i] = (double)num;
	}
}

template<typename Type>
matrix::matrix(const Type* num, const unsigned ncols) :
	nrows(1), ncols(ncols), point(NULL)
{
	point = new double*;
	*point = new double[ncols];
	for (unsigned j = 0; j < ncols; j++) {
		(*point)[j] = double(num[j]);
	}
}

matrix::~matrix()
{
	for (unsigned i = 0; i < nrows; i++) {
		delete[] point[i];
	}
	delete[] point;
	point = NULL;
}

inline double* matrix::operator[](const unsigned i)
{
	return point[i];
}

void matrix::print()
{
	for (unsigned i = 0; i < nrows; i++) {
		for (unsigned j = 0; j < ncols; j++) {
			cout << point[i][j];
			if (j != ncols - 1)cout << '\t';
		}
		cout << endl;
	}
}
