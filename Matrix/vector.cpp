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
	_size(0), point(NULL)
{}

template<class elm>
vector<elm>::vector(agm_vct origin) :
	_size(origin._size), point(NULL)
{
	if (_size > 0) {
		point = new elm[_size];
		if (point == NULL) {
			throw exc_matrix(0U, "vector::vector(agm_vct origin)");
		}
	}
	for (int i(0); i < _size; i++) {
		point[i] = origin.point[i];
	}
}

template<class elm>
vector<elm>::vector(agm_vct origin, int begin, int end) :
	_size(end + 1 - begin), point(NULL)
{
	if (_size > 0) {
		point = new elm[_size];
		if (point == NULL) {
			throw exc_matrix(0U, "vector::vector(agm_vct origin)");
		}
		for (int i(0); i < _size; i++) {
			point[i] = origin.point[i + begin];
		}
	}
	else {
		throw exc_matrix(5U, "vector(agm_vct origin, int begin, int end)");
	}
}

template<class elm>
vector<elm>::vector(int n, agm_elm value) :
	_size(n), point(NULL)
{
	if (_size > 0) {
		point = new elm[_size];
		if (point == NULL) {
			throw exc_matrix(0U, "vector::vector(int _size, elm value)");
		}
	}
	for (int i(0); i < _size; i++) {
		point[i] = value;
	}
}

template<class elm>
vector<elm>::vector(c_ary ary, int len) :
	_size(len), point(NULL)
{
	if (_size > 0) {
		point = new elm[_size];
		if (point == NULL) {
			throw exc_matrix(0U, "vector::vector(c_ary c_ary, int length)");
		}
	}
	for (int i(0); i < _size; i++) {
		point[i] = ((elm*)ary)[i];
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
inline bool vector<elm>::empty() const
{
	return _size == 0;
}

template<class elm>
inline int vector<elm>::size() const
{
	return _size;
}

// Element -----------------------------------------------------------------

template<class elm>
inline elm vector<elm>::at(int lct) const
{
	if (lct < 0 || lct >= _size) {
		throw exc_matrix(2U, "vector::at(int lct)");
	}
	return point[lct];
}

template<class elm>
element<elm> vector<elm>::MAX() const
{
	int col(0);
	elm value(at(0));
	for (int i(1); i < _size; i++) {
		elm ivalue(at(i));
		if (ivalue > value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

template<class elm>
element<elm> vector<elm>::MIN() const
{
	int col(0);
	elm value(at(0));
	for (int i(1); i < _size; i++) {
		elm ivalue(at(i));
		if (ivalue < value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

template<class elm>
element<elm> vector<elm>::absmax() const
{
	int col(0);
	elm value(abs(at(0)));
	for (int i(1); i < _size; i++) {
		elm ivalue(abs(at(i)));
		if (ivalue > value) {
			value = ivalue;
			col = i;
		}
	}
	return element<elm>(0, col, value);
}

template<class elm>
element<elm> vector<elm>::absmin() const
{
	int col(0);
	elm value(abs(at(0)));
	for (int i(1); i < _size; i++) {
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
	for (int i(0); i < _size; i++) {
		point[i] = value;
	}
}

template<class elm>
void vector<elm>::cover(c_ary ary)
{
	for (int i(0); i < _size; i++) {
		point[i] = ((elm*)ary)[i];
	}
}

template<class elm>
void vector<elm>::cover(agm_vct vct)
{
	for (int i(0); i < _size; i++) {
		point[i] = vct.point[i];
	}
}

template<class elm>
void vector<elm>::insert(int lct, agm_elm value, int n)
{
	if (lct < 0 || lct > _size) {
		throw exc_matrix(2, "vector::insert(int lct, elm value, int n), 'lct' is out of range.");
	}
	_size += n;
	elm* newpoint = new elm[_size];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < lct + n; i++) {
		newpoint[i] = value;
	}
	for (; i < _size; i++) {
		newpoint[i] = point[i - n];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::insert(int lct, c_ary ary, int len)
{
	if (lct < 0 || lct > _size) {
		throw exc_matrix(2, "vector::insert(int lct, elm value, int n), 'lct' is out of range.");
	}
	_size += len;
	elm* newpoint = new elm[_size];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < lct + len; i++) {
		newpoint[i] = ((elm*)ary)[i];
	}
	for (; i < _size; i++) {
		newpoint[i] = point[i - len];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::insert(int lct, agm_vct vct)
{
	if (lct < 0 || lct > _size) {
		throw exc_matrix(2, "vector::insert(int lct, agm_vct vct), 'lct' is out of range.");
	}
	_size += vct._size;
	elm* newpoint = new elm[_size];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < lct + vct._size; i++) {
		newpoint[i] = vct.point[i - lct];
	}
	for (; i < _size; i++) {
		newpoint[i] = point[i - vct._size];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::append(agm_elm value, int len)
{
	insert(_size, value, len);
}

template<class elm>
void vector<elm>::append(c_ary ary, int len)
{
	insert(_size, ary, len);
}

template<class elm>
void vector<elm>::append(agm_vct vct)
{
	insert(_size, vct);
}

template<class elm>
void vector<elm>::remove(int lct)
{
	if (lct < 0 || lct >= _size) {
		throw exc_matrix(2U, "remove(int lct), 'lct' is out of range.");
	}
	if (lct == 0 && lct == _size - 1) {
		_size = 0;
		delete[] point;
		point = NULL;
		return;
	}
	_size--;
	elm* newpoint = new elm[_size];
	int i(0);
	for (; i < lct; i++) {
		newpoint[i] = point[i];
	}
	for (; i < _size; i++) {
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
	if (start < 0 || end >= _size) {
		throw exc_matrix(2U,
			"vector::remove(int start, int end), 'start' or 'end' is out of range.");
	}
	if (start == 0 && end == _size - 1) {
		_size = 0;
		delete[] point;
		point = NULL;
		return;
	}
	int length = end + 1 - start;
	_size -= length;
	elm* newpoint = new elm[_size];
	int i(0);
	for (; i < start; i++) {
		newpoint[i] = point[i];
	}
	for (; i < _size; i++) {
		newpoint[i] = point[i + length];
	}
	delete[] point;
	point = newpoint;
}

template<class elm>
void vector<elm>::cutoff(int n)
{
	remove(_size - n, _size - 1);
}

template<class elm>
void vector<elm>::add(agm_vct vct)
{
	if (_size != vct._size) {
		throw exc_matrix(3U, "vector::add(agm_vct vct), '_size' != 'vct._size'.");
	}
	for (int i(0); i < _size; i++) {
		point[i] += vct.point[i];
	}
}

template<class elm>
void vector<elm>::sub(agm_vct vct)
{
	if (_size != vct._size) {
		throw exc_matrix(3U, "vector::sub(agm_vct vct), '_size' != 'vct._size'.");
	}
	for (int i(0); i < _size; i++) {
		point[i] -= vct.point[i];
	}
}

template<class elm>
void vector<elm>::mul(agm_vct vct)
{
	if (_size != vct._size) {
		throw exc_matrix(3U, "vector::mul(agm_vct vct), '_size' != 'vct._size'.");
	}
	for (int i(0); i < _size; i++) {
		point[i] *= vct.point[i];
	}
}

template<class elm>
void vector<elm>::mul(agm_elm value)
{
	for (int i(0); i < _size; i++) {
		point[i] *= value;
	}
}

template<class elm>
void vector<elm>::div(agm_vct vct)
{
	if (_size != vct._size) {
		throw exc_matrix(3U, "vector::div(agm_vct vct), '_size' != 'vct._size'.");
	}
	for (int i(0); i < _size; i++) {
		point[i] /= vct.point[i];
	}
}

template<class elm>
void vector<elm>::div(agm_elm value)
{
	for (int i(0); i < _size; i++) {
		point[i] /= value;
	}
}

// Operators ---------------------------------------------------------------

template<class elm>
inline elm vector<elm>::operator[](int lct) const
{
	return at(lct);
}

BEGIN_OSL
template<typename elm>
MATRIX_API inline vector<elm> operator+(const vector<elm>& vct1, const vector<elm>& vct2)
{
	vector<elm> rst(vct1);
	rst.add(vct2);
	return rst;
}

template<typename elm>
MATRIX_API inline vector<elm> operator-(const vector<elm>& vct1, const vector<elm>& vct2)
{
	vector<elm> rst(vct1);
	rst.sub(vct2);
	return rst;
}

template<typename elm>
MATRIX_API elm operator*(const vector<elm>& vct1, const vector<elm>& vct2)
{
	elm rst(0.0);
	int size(vct1._size);
	for (int i(0); i < size; i++) {
		rst += vct1.at(i) * vct2.at(i);
	}
	return rst;
}

template<typename elm>
MATRIX_API std::ostream& operator<<(std::ostream& os, const vector<elm>& vct)
{
	os << "[ ";
	int size(vct._size);
	int i(0);
	for (; i < size - 1; i++) {
		os << vct.at(i) << ", ";
	}
	os << vct.at(size - 1) << " ]";
	return os;
}

template<typename elm>
MATRIX_API std::istream& operator>>(std::istream& is, vector<elm>& vct)
{
	for (int i(0); i < vct._size; i++) {
		is >> vct.point[i];
	}
	return is;
}
END_OSL

namespace {
	template<typename elm>
	void instantiate_template(elm value)
	{
		// Constructors & Destructor
		vector<elm>* a = new vector<elm>;
		vector<elm>* b = new vector<elm>(*a);
		vector<elm>* c = new vector<elm>(1, value);
		delete a, b, c; a = NULL; b = NULL; c = NULL;
		elm ary[] = { value };
		vector<elm>* d = new vector<elm>(ary, 1);

		// Properties
		d->empty();
		d->size();

		// Element
		d->at(0);
		d->MAX();
		d->MIN();
		d->absmax();
		d->absmin();

		// Modifiers
		d->cover(value);
		d->cover(ary);
		d->cover(*d);
		d->append(elm(1.0));
		d->append(ary, 1);
		d->append(*d);
		d->cutoff(d->size() - 1);
		d->add(*d);
		d->sub(*d);
		d->mul(*d);
		d->mul(elm(1.0));
		d->div(*d);
		d->div(elm(1.0));

		// Operators
		(*d)[0];
		*d + *d;
		*d - *d;
		(*d) * (*d);
		std::cout << *d;
		std::cin >> *d;
		delete d;
	}

	void instantiate()
	{
		instantiate_template(int(1));
		instantiate_template(double(1));
		instantiate_template(osl::rational(1));
		// instantiate_template(osl::complex(1));
	}
}