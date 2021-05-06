/* OSL/Matrix/element.cpp
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

template<class elm>
inline element<elm>::element() :
	_row(0), _col(0), _value(0.0)
{}

template<class elm>
inline element<elm>::element(const element & origin) :
	_row(origin._row), _col(origin._col), _value(origin._value)
{}

template<class elm>
inline element<elm>::element(int row, int col, const elm& value) :
	_row(row), _col(col), _value(value)
{}

template<class elm>
inline int element<elm>::row()
{
	return _row;
}

template<class elm>
inline int element<elm>::col()
{
	return _col;
}

template<class elm>
inline elm element<elm>::value()
{
	return _value;
}

namespace {
	template<typename elm>
	void instantiate_template(const elm& value)
	{
		element<elm>* a = new element<elm>;
		element<elm>* b = new element<elm>(*a);
		element<elm>* c = new element<elm>(0, 0, 0.0);
		c->row();
		c->col();
		c->value();
		delete a, b, c;
	}

	void instantiate()
	{
		instantiate_template(int(1));
		instantiate_template(double(1));
		instantiate_template(osl::rational());
		instantiate_template(osl::complex());
	}
}