/* OSL/Matrix/matrix.h
 *
 * Copyright (C) 2021 YuminZhan
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this
 * program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#ifdef MATRIX_EXPORTS
#define MATRIX_API __declspec(dllexport)
#else
#define MATRIX_API __declspec(dllimport)
#pragma	comment(lib, "matrix")
#endif

#include <iostream>
#include "../Number/number.h"

#ifndef BEGIN_OSL
	#define BEGIN_OSL namespace osl {
	#define END_OSL }
	BEGIN_OSL
	typedef const double& argument, agm;
	typedef const char* c_str;
	typedef int error;
	END_OSL
#endif // !BEGIN_OSL

BEGIN_OSL // namespace osl {

template<class elm = double>
class MATRIX_API element {
public:
	element();
	element(int row, int col, const elm& value);
	element(const element& origin);
	int row();
	int col();
	elm value();
private:
	int _row, _col;
	elm _value;
};

template<class elm = double>
class MATRIX_API vector {
	typedef const vector& agm_vct;
	typedef const elm& agm_elm;
public:
	// Constructors & Destructor
	vector();
	vector(agm_vct origin);
	vector(int ncol, agm_elm value = 0);
	vector(const void* c_ary, int length);
	~vector();

	// Properties
	bool empty();
	int ncol();

	// Element
	inline elm at(int lct);
	element<elm> MAX();
	element<elm> MIN();
	element<elm> absmax();
	element<elm> absmin();

	// Modifiers
	void cover(agm_elm value = 0);
	void insert(int lct, agm_elm value = 0, int length = 1);
	void insert(int lct, agm_vct ary);
	void append(agm_elm value = 0, int length = 1);
	void append(agm_vct ary);
	void remove(int lct);
	void remove(int start, int end);
	void cutoff(int length);
	void add(agm_vct ary);
	void sub(agm_vct ary);
	void mul(agm_vct ary);
	void div(agm_vct ary);

	// Operators
	inline elm operator[](int lct);

private:
	int _ncol;
	elm* point;
};

template<class elm = double>
class MATRIX_API matrix {
	typedef const matrix& agm_mtr;
public:
	// matrix.cpp
	inline matrix();
	matrix(agm_mtr origin);
	matrix(agm_mtr origin, int start_row, int start_col, int end_row, int end_col);
	//matrix(const char* file, int nrow, int ncol);
	//matrix(int nrow, int ncol, elm num = 0.0);
	//matrix(void* ary, int n, bool transpose = false);
	//matrix(void** ary, int nrow, int ncol);
	~matrix();

	//inline elm* operator[](int i);
	//typedef int position;
	//inline void insert(int lct_i, int lct_j,
	//	int inst_rows = 1U, int inst_cols = 0U, elm fillnumber = 0.0);
	//void insert_rows(int lct_i, int inst_rows = 1U, elm fillnumber = 0.0);
	//void insert_cols(int lct_j, int inst_cols = 1U, elm fillnumber = 0.0);
	//inline void remove(int lct_i, int lct_j, int rmv_rows = 1, int rmv_cols = 0);
	//void remove_rows(int lct_i, int rmv_rows = 1);
	//void remove_cols(int lct_j, int rmv_cols = 1);
	//void print(int start_row = 0U, int start_col = 0U,
	//	int print_nrows = 0U, int print_ncols = 0U);

	//void add(agm_mtr matrix);
	//void subtract(agm_mtr matrix);
	//void multiply(agm_mtr matrix);
	//void invert();

private:
	int nrow, ncol;
	vector<elm>* point;
	//inline void empty_matrix(bool showtip = NO);
	//void normal_matrix(int nrows, int ncols, elm num = 0.0);
	//inline void expmatrix(int nrows, int ncols, agm_mtr origin,
	//	int start_row, int start_col, elm num = 0.0);
	//void max_and_min();
};

class MATRIX_API exc_matrix {
public:
	const unsigned num;
	c_str const discription;
	static c_str overview_list[];
	inline exc_matrix(unsigned num, c_str discription);
	inline c_str overview()const;
};

END_OSL // }