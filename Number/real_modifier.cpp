/* OSL/Number/real_modifier.cpp
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
#include "number.h"

namespace osl {
	inline void real::rec()
	{
		double temp = _denominator;
		_denominator = _numerator;
		_numerator = temp;
	}

	inline void real::absr()
	{
		_numerator = ::fabs(_numerator);
		_denominator = ::fabs(_denominator);
	}

	inline void real::add(agm num)
	{
		_numerator += num * _denominator;
		simplify();
	}

	inline void real::add(agm_real num)
	{
		_numerator = _numerator * num._denominator + _denominator * num._denominator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::sub(agm num)
	{
		_numerator -= num * _denominator;
		simplify();
	}

	inline void real::sub(agm_real num)
	{
		_numerator = _numerator * num._denominator - _denominator * num._numerator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::mul(agm num)
	{
		_numerator *= num;
	}

	inline void real::mul(agm_real num)
	{
		_numerator *= num._numerator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::div(agm num)
	{
		_denominator *= num;
		simplify();
	}

	inline void real::div(agm_real num)
	{
		_numerator *= num._denominator;
		_denominator *= num._numerator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::simplify()
	{
		simplify_fraction(_denominator, _numerator);
	}
}