/* OSL/Matrix/vector.cpp
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

#include "pch.h"
#include "matrix.h"

using osl::element;
using osl::vector;

// Constructors & Destructor ----------------------------------------------------
template<class elm>
vector<elm>::vector() :
	_ncol(0), point(NULL)
{}

template<class elm>
vector<elm>::vector(agm_vct origin) :
	_ncol(origin._ncol), point(NULL)
{
	if (_ncol > 0) {
		point = new elm[_ncol];
		if (point == NULL) {
			throw exc_matrix(0U, "vector::vector(agm_vct origin)");
		}
	}
	for (int i(0); i < _ncol; i++) {
		point[i] = origin.point[i];
	}
}

template<class elm>
vector<elm>::vector(int _ncol, agm_elm value) :
	_ncol(_ncol), point(NULL)
{
	point = new elm[_ncol];
	if (point == NULL) {
		throw exc_matrix(0U, "vector::vector(int _ncol, elm value)");
	}
	for (int i(0); i < _ncol; i++) {
		point[i] = value;
	}
}

template<class elm>
vector<elm>::vector(const void* c_ary, int length) :
	_ncol(length)
{
	point = new elm[_ncol];
	if (point == NULL) {
		throw exc_matrix(0U, "vector::vector(const void* c_ary, int length)");
	}
	for (int i(0); i < _ncol; i++) {
		point[i] = ((elm*)c_ary)[i];
	}
}

template<class elm>
vector<elm>::~vector()
{
	if (point != NULL) {
		delete[] point;
		point = NULL;
	}
}

template<class elm>
bool vector<elm>::empty()
{
	return _ncol == 0;
}

template<class elm>
int vector<elm>::ncol()
{
	if (empty()) {
		return 0;
	}
	return _ncol;
}

// Element -----------------------------------------------------------------

template<class elm>
inline elm vector<elm>::at(int lct)
{
	if (lct < 0 || lct >= _ncol) {
		throw exc_matrix(2U, "vector::at(int lct)");
	}
	return point[lct];
}

template<class elm>
element<elm> vector<elm>::MAX()
{
	int col(0);
	elm value(at(0));
	for (int i(1); i < _ncol; i++) {
		elm ivalue(at(i));
		if (ivalue > value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

template<class elm>
element<elm> vector<elm>::MIN()
{
	int col(0);
	elm value(at(0));
	for (int i(1); i < _ncol; i++) {
		elm ivalue(at(i));
		if (ivalue < value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

template<class elm>
element<elm> vector<elm>::absmax()
{
	int col(0);
	elm value(abs(at(0)));
	for (int i(1); i < _ncol; i++) {
		elm ivalue(abs(at(i)));
		if (ivalue > value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

template<class elm>
element<elm> vector<elm>::absmin()
{
	int col(0);
	elm value(abs(at(0)));
	for (int i(1); i < _ncol; i++) {
		elm ivalue(abs(at(i)));
		if (ivalue < value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

// Modifiers ------------------------------------------------------------------

template<class elm>
void vector<elm>::cover(agm_elm value)
{
	for (int i(0); i < _ncol; i++) {
		point[i] = value;
	}
}

template<class elm>
void vector<elm>::insert(int lct, agm_elm value, int length)
{
	if (lct < 0 || lct > _ncol) {
		throw exc_matrix(2, "vector::insert(int lct, elm value, int length), 'lct' is out of range.");
	}
	_ncol += length;
	elm* newpoint = new elm[_ncol];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < lct + length; i++) {
		newpoint[i] = value;
	}
	for (; i < _ncol; i++) {
		newpoint[i] = point[i - length];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::insert(int lct, agm_vct ary)
{
	if (lct < 0 || lct > _ncol) {
		throw exc_matrix(2, "vector::insert(int lct, agm_vct ary), 'lct' is out of range.");
	}
	_ncol += ary._ncol;
	elm* newpoint = new elm[_ncol];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < lct + ary._ncol; i++) {
		newpoint[i] = ary[i - lct];
	}
	for (; i < _ncol; i++) {
		newpoint[i] = point[i - ary._ncol];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::append(agm_elm value, int length)
{
	insert(_ncol, value, length);
}

template<class elm>
void vector<elm>::append(agm_vct ary)
{
	insert(_ncol, ary);
}

template<class elm>
void vector<elm>::remove(int lct)
{
	if (lct < 0 || lct >= _ncol) {
		throw exc_matrix(2U, "remove(int lct), 'lct' is out of range.");
	}
	if (lct == 0 && lct == _ncol - 1) {
		_ncol = 0;
		delete[] point;
		point = NULL;
		return;
	}
	_ncol--;
	elm* newpoint = new elm[_ncol];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < _ncol; i++) {
		newpoint[i] = point[i + 1];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::remove(int start, int end)
{
	if (start > end) {
		throw exc_matrix(5U,
			"vector::remove(int start, int end)");
	}
	if (start < 0 || end >= _ncol) {
		throw exc_matrix(2U,
			"vector::remove(int start, int end), 'start' or 'end' is out of range.");
	}
	if (start == 0 && end == _ncol - 1) {
		_ncol = 0;
		delete[] point;
		point = NULL;
		return;
	}
	int length = end + 1 - start;
	_ncol -= length;
	elm* newpoint = new elm[_ncol];
	int i(0);
	for (; i < start; i++) {
		newpoint[i] = point[i];
	}
	for (; i < _ncol; i++) {
		newpoint[i] = point[i + length];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::cutoff(int length)
{
	remove(_ncol - length, _ncol - 1);
}

template<class elm>
void vector<elm>::add(agm_vct ary)
{
	if (_ncol != ary._ncol) {
		throw exc_matrix(3U, "vector::add(agm_vct ary), '_ncol' != 'ary._ncol'.");
	}
	for (int i(0); i < _ncol; i++) {
		point[i] += ary.point[i];
	}
}

template<class elm>
void vector<elm>::sub(agm_vct ary)
{
	if (_ncol != ary._ncol) {
		throw exc_matrix(3U, "vector::sub(agm_vct ary), '_ncol' != 'ary._ncol'.");
	}
	for (int i(0); i < _ncol; i++) {
		point[i] -= ary.point[i];
	}
}

template<class elm>
void vector<elm>::mul(agm_vct ary)
{
	if (_ncol != ary._ncol) {
		throw exc_matrix(3U, "vector::mul(agm_vct ary), '_ncol' != 'ary._ncol'.");
	}
	for (int i(0); i < _ncol; i++) {
		point[i] *= ary.point[i];
	}
}

template<class elm>
void vector<elm>::div(agm_vct ary)
{
	if (_ncol != ary._ncol) {
		throw exc_matrix(3U, "vector::div(agm_vct ary), '_ncol' != 'ary._ncol'.");
	}
	for (int i(0); i < _ncol; i++) {
		point[i] /= ary.point[i];
	}
}

// Operators ---------------------------------------------------------------

template<class elm>
inline elm vector<elm>::operator[](int lct)
{
	return at(lct);
}

namespace {
	template<typename elm>
	void instantiate_template(elm value)
	{
		// Constructors & Destructor
		vector<elm>* a = new vector<elm>;
		vector<elm>* b = new vector<elm>(*a);
		delete a, b;
		vector<elm>* c = new vector<elm>(1, value);
		delete c;
		elm ary[] = { value };
		vector<elm> d(ary, 1);

		// Properties


		// Element
		d.at(0);

	}

	void instantiate()
	{
		instantiate_template(int(1));
		instantiate_template(double(1));
		instantiate_template(osl::rational(1));
		// instantiate_template(osl::complex(1));
	}
}