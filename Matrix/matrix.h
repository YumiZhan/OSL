#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class matrix {
public:
	inline matrix();
	template <typename Type> matrix(const Type num, const unsigned nsqare = 1);
	template <typename Type> matrix(const Type* num, const unsigned ncols);
	matrix(const string& str);
	matrix(const ifstream& ifile);

	void print();
	inline double* operator[](const unsigned i);
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
	point = new double*[1];
	point[0] = new double[1];
	point[0][0] = 1.0;
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

inline double* matrix::operator[](const unsigned i)
{
	return point[i];
}

matrix::matrix(const string& str)
{

}

matrix::matrix(const ifstream& ifile)
{
	
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
