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

// Constructors & Destructor ---------------------------------------------------------------

template<class elm>
vector<elm>::vector(int n, agm_elm value) :
	_size(n), pointer(NULL)
{
	if (_size < 0) {
		throw exc::vector(5U, "vector(int n, agm_elm value)");
	}
	if (_size == 0) {
		return;
	}
	pointer = new elm[_size];
	if (pointer == NULL) {
		throw exc::vector(0U, "vector(int n, agm_elm value)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] = value;
	}
}

template<class elm>
vector<elm>::vector(agm_vec origin) :
	_size(origin._size), pointer(NULL)
{
	if (_size == 0) {
		return;
	}
	pointer = new elm[_size];
	if (pointer == NULL) {
		throw exc::vector(0U, "vector::vector(agm_vec origin)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] = origin.pointer[i];
	}
}

template<class elm>
vector<elm>::vector(agm_vec origin, int begin, int end) :
	_size(end + 1 - begin), pointer(NULL)
{
	if (_size == 0) {
		return;
	}
	if (_size < 0) {
		throw exc::vector(6U, "vector(agm_vec origin, int begin, int end)");
	}
	if (begin < 0 || end >= origin._size) {
		throw exc::vector(3U, "vector(agm_vec origin, int begin, int end)");
	}
	pointer = new elm[_size];
	for (int i(0); i < _size; i++) {
		pointer[i] = origin.pointer[i + begin];
	}
}

template<class elm>
vector<elm>::vector(c_ary ary, int len) :
	_size(len), pointer(NULL)
{
	if (_size < 0) {
		throw exc::vector(5U, "vector(c_ary ary, int len)");
	}
	if (_size == 0) {
		return;
	}
	if (ary == NULL) {
		throw exc::vector(1U, "vector(c_ary ary, int len)");
	}
	pointer = new elm[_size];
	if (pointer == NULL) {
		throw exc::vector(0U, "vector::vector(c_ary ary, int len)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] = ((elm*)ary)[i];
	}
}

template<class elm>
vector<elm>::~vector()
{
	if (pointer != NULL) {
		delete[] pointer;
		pointer = NULL;
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

// Element -------------------------------------------------------------------------------

template<class elm>
inline elm& vector<elm>::at(int lct) const
{
	if (lct < 0 || lct >= _size) {
		throw exc::vector(3U, "vector::at(int lct)");
	}
	return pointer[lct];
}

template<class elm>
element<elm> vector<elm>::MAX() const
{
	if (empty()) {
		throw exc::vector(1U, "MAX()");
	}
	element<elm> _max(0, 0, pointer[0]);
	for (int i(1); i < _size; i++) {
		if (pointer[i] > _max.value) {
			_max.col = i;
			_max.value = pointer[i];
		}
	}
	return _max;
}

template<class elm>
element<elm> vector<elm>::MIN() const
{
	if (empty()) {
		throw exc::vector(1U, "MIN()");
	}
	element<elm> _min(0, 0, pointer[0]);
	for (int i(1); i < _size; i++) {
		if (pointer[i] < _min.value) {
			_min.col = i;
			_min.value = pointer[i];
		}
	}
	return _min;
}

template<class elm>
element<elm> vector<elm>::absmax() const
{
	if (empty()) {
		throw exc::vector(1U, "absmax()");
	}
	element<elm> _absmax(0, 0, abs(pointer[0]));
	for (int i(1); i < _size; i++) {
		if (abs(pointer[i]) > _absmax.value) {
			_absmax.col = i;
			_absmax.value = abs(pointer[i]);
		}
	}
	return _absmax;
}

template<class elm>
element<elm> vector<elm>::absmin() const
{
	if (empty()) {
		throw exc::vector(1U, "absmin()");
	}
	element<elm> _absmin(0, 0, abs(pointer[0]));
	for (int i(1); i < _size; i++) {
		if (abs(pointer[i]) < _absmin.value) {
			_absmin.col = i;
			_absmin.value = abs(pointer[i]);
		}
	}
	return _absmin;
}

// Modifiers ------------------------------------------------------------------------------

template<class elm>
void vector<elm>::cover(agm_elm value)
{
	for (int i(0); i < _size; i++) {
		pointer[i] = value;
	}
}

template<class elm>
void vector<elm>::cover(c_ary ary)
{
	if (ary == NULL) {
		throw exc::vector(1U, "cover(c_ary ary)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] = ((elm*)ary)[i];
	}
}

template<class elm>
void vector<elm>::cover(agm_vec vec, int begin)
{
	if (begin < 0 || begin + _size - 1 >= vec._size) {
		throw exc::vector(3U, "cover(agm_vec vec, int begin)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] = vec.pointer[i + begin];
	}
}

template<class elm>
void vector<elm>::insert(int lct, int n, agm_elm value)
{
	if (n == 0) {
		return;
	}
	if (n < 0) {
		throw exc::vector(5U, "insert(int lct, int n, agm_elm value)");
	}
	if (lct < 0 || lct > _size) {
		throw exc::vector(3U, "insert(int lct, int n, agm_elm value)");
	}
	_size += n;
	elm* newpointer = new elm[_size];
	if (newpointer == NULL) {
		throw exc::vector(0U, "insert(int lct, int n, agm_elm value)");
	}
	int i(0);
	for (; i < lct; i++) {
		newpointer[i] = pointer[i];
	}
	for (; i < lct + n; i++) {
		newpointer[i] = value;
	}
	for (; i < _size; i++) {
		newpointer[i] = pointer[i - n];
	}
	delete[] pointer;
	pointer = newpointer;
}

template<class elm>
void vector<elm>::insert(int lct, c_ary ary, int len)
{
	if (len == 0) {
		return;
	}
	if (len < 0) {
		throw exc::vector(5U, "insert(int lct, c_ary ary, int len)");
	}
	if (ary == NULL) {
		throw exc::vector(1U, "insert(int lct, c_ary ary, int len)");
	}
	if (lct < 0 || lct > _size) {
		throw exc::vector(3U, "insert(int lct, c_ary ary, int len)");
	}
	_size += len;
	elm* newpointer = new elm[_size];
	if (newpointer == NULL) {
		throw exc::vector(0U, "insert(int lct, c_ary ary, int len)");
	}
	int i(0);
	for (; i < lct; i++) {
		newpointer[i] = pointer[i];
	}
	for (; i < lct + len; i++) {
		newpointer[i] = ((elm*)ary)[i];
	}
	for (; i < _size; i++) {
		newpointer[i] = pointer[i - len];
	}
	delete[] pointer;
	pointer = newpointer;
}

template<class elm>
void vector<elm>::insert(int lct, agm_vec vec)
{
	if (vec.empty()) {
		return;
	}
	if (lct < 0 || lct > _size) {
		throw exc::vector(3U, "insert(int lct, agm_vec vec)");
	}
	_size += vec._size;
	elm* newpointer = new elm[_size];
	if (newpointer == NULL) {
		throw exc::vector(0U, "insert(int lct, agm_vec vec)");
	}
	int i(0);
	for (; i < lct; i++) {
		newpointer[i] = pointer[i];
	}
	for (; i < lct + vec._size; i++) {
		newpointer[i] = vec.pointer[i - lct];
	}
	for (; i < _size; i++) {
		newpointer[i] = pointer[i - vec._size];
	}
	delete[] pointer;
	pointer = newpointer;
}

template<class elm>
inline void vector<elm>::append(int n, agm_elm value)
{
	try {
		insert(_size, n, value);
	}
	catch (exc::vector excv) {
		throw exc::vector(excv.code, "append(agm_elm value, int n)");
	}
}

template<class elm>
inline void vector<elm>::append(c_ary ary, int len)
{
	try {
		insert(_size, ary, len);
	}
	catch (exc::vector excv) {
		throw exc::vector(excv.code, "append(c_ary ary, int len)");
	}
}

template<class elm>
inline void vector<elm>::append(agm_vec vec)
{
	try {
		insert(_size, vec);
	}
	catch (exc::vector excv) {
		throw exc::vector(excv.code, "append(agm_vec vec)");
	}
}

template<class elm>
void vector<elm>::remove(int lct)
{
	if (lct < 0 || lct >= _size) {
		throw exc::vector(3U, "remove(int lct)");
	}
	if (lct == 0 && lct == _size - 1) {
		_size = 0;
		delete[] pointer;
		pointer = NULL;
		return;
	}
	_size--;
	elm* newpointer = new elm[_size];
	if (newpointer == NULL) {
		throw exc::vector(0U, "remove(int lct)");
	}
	int i(0);
	for (; i < lct; i++) {
		newpointer[i] = pointer[i];
	}
	for (; i < _size; i++) {
		newpointer[i] = pointer[i + 1];
	}
	delete[] pointer;
	pointer = newpointer;
}

template<class elm>
void vector<elm>::remove(int start, int end)
{
	if (start > end) {
		throw exc::vector(6U, "remove(int start, int end)");
	}
	if (start < 0 || end >= _size) {
		throw exc::vector(3U, "remove(int start, int end)");
	}
	if (start == end) {
		return;
	}
	if (start == 0 && end == _size - 1) {
		_size = 0;
		delete[] pointer;
		pointer = NULL;
		return;
	}
	int length(end + 1 - start);
	_size -= length;
	elm* newpointer = new elm[_size];
	if (newpointer == NULL) {
		throw exc::vector(0U, "remove(int start, int end)");
	}
	int i(0);
	for (; i < start; i++) {
		newpointer[i] = pointer[i];
	}
	for (; i < _size; i++) {
		newpointer[i] = pointer[i + length];
	}
	delete[] pointer;
	pointer = newpointer;
}

template<class elm>
inline void vector<elm>::cutoff(int n)
{
	if (n < 0) {
		throw exc::vector(5U, "cutoff(int n)");
	}
	remove(_size - n, _size - 1);
}

template<class elm>
void vector<elm>::add(agm_vec vec)
{
	if (_size != vec._size) {
		throw exc::vector(8U, "add(agm_vec vec)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] += vec.pointer[i];
	}
}

template<class elm>
void vector<elm>::sub(agm_vec vec)
{
	if (_size != vec._size) {
		throw exc::vector(8U, "sub(agm_vec vec)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] -= vec.pointer[i];
	}
}

template<class elm>
void vector<elm>::mul(agm_vec vec)
{
	if (_size != vec._size) {
		throw exc::vector(8U, "mul(agm_vec vec)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] *= vec.pointer[i];
	}
}

template<class elm>
void vector<elm>::mul(agm_elm value)
{
	for (int i(0); i < _size; i++) {
		pointer[i] *= value;
	}
}

template<class elm>
void vector<elm>::div(agm_vec vec)
{
	if (_size != vec._size) {
		throw exc::vector(8U, "div(agm_vec vec)");
	}
	for (int i(0); i < _size; i++) {
		pointer[i] /= vec.pointer[i];
	}
}

template<class elm>
void vector<elm>::div(agm_elm value)
{
	for (int i(0); i < _size; i++) {
		pointer[i] /= value;
	}
}

// Operators ---------------------------------------------------------------------------

template<class elm>
inline elm& vector<elm>::operator[](int lct) const
{
	return at(lct);
}

namespace osl {
	template<typename elm>
	MATRIX_API inline vector<elm> operator+(const vector<elm>& vec1, const vector<elm>& vec2)
	{
		vector<elm> rst(vec1);
		rst.add(vec2);
		return rst;
	}

	template<typename elm>
	MATRIX_API inline vector<elm> operator-(const vector<elm>& vec1, const vector<elm>& vec2)
	{
		vector<elm> rst(vec1);
		rst.sub(vec2);
		return rst;
	}

	template<typename elm>
	MATRIX_API elm operator*(const vector<elm>& vec1, const vector<elm>& vec2)
	{
		elm rst(0.0);
		if (vec1._size != vec2._size) {
			throw exc::vector(8U, "operator*(const vector<elm>& vec1, const vector<elm>& vec2)");
		}
		for (int i(0); i < vec1._size; i++) {
			rst += vec1.at(i) * vec2.at(i);
		}
		return rst;
	}

	template<typename elm>
	MATRIX_API std::ostream& operator<<(std::ostream& os, const vector<elm>& vec)
	{
		os << "[ ";
		vec._size;
		if (vec._size > 0) {
			for (int i(0); i < vec._size; i++) {
				os << vec.at(i) << " ";
			}
		}
		os << "]";
		return os;
	}

	template<typename elm>
	MATRIX_API std::istream& operator>>(std::istream& is, vector<elm>& vec)
	{
		for (int i(0); i < vec._size; i++) {
			is >> vec.pointer[i];
		}
		return is;
	}
}

// Practical Tools ------------------------------------------------------------------------

template<class elm>
void vector<elm>::print(c_str separator, char end)
{
	std::cout << "[ ";
	if (_size > 0) {
		for (int i(0); i < _size - 1; i++) {
			std::cout << at(i) << separator;
		}
		std::cout << at(_size - 1);
	}
	std::cout << " ]" << end;
}

// Instantiate ----------------------------------------------------------------------------

namespace {
	template<typename elm>
	void template_instantiate(const elm& value)
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
		d->MAX();
		d->MIN();
		d->absmax();
		d->absmin();

		// Modifiers
		d->cover(value);
		d->cover(ary);
		d->cover(*d);
		d->append(1, elm(1.0));
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

		// Practical Tools
		d->print();

		delete d;
	}

	void instantiate()
	{
		template_instantiate(int(1));
		template_instantiate(double(1));
		template_instantiate(osl::rational(1));
		// template_instantiate(osl::complex(1));
	}
}