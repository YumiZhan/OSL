/* OSL/Number/real_comparation.cpp
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
	inline bool real::larger_than(agm num) const
	{
		return _numerator > _denominator * num;
	}

	inline bool real::larger_than(agm_real num) const
	{
		return _numerator * num._denominator > _denominator * num._denominator;
	}

	inline bool real::not_less_than(agm num) const
	{
		return _numerator >= _denominator * num;
	}

	inline bool real::not_less_than(agm_real num) const
	{
		return _numerator * num._denominator > _denominator * num._denominator;
	}

	inline bool real::less_than(agm num) const
	{
		return _numerator < _denominator* num;
	}

	inline bool real::less_than(agm_real num) const
	{
		return _numerator * num._denominator < _denominator* num._numerator;
	}

	inline bool real::not_larger_than(agm num) const
	{
		return _numerator <= _denominator * num;
	}

	inline bool real::not_larger_than(agm_real num) const
	{
		return _numerator * num._denominator < _denominator* num._numerator;
	}

	inline bool real::equal_to(agm num, agm precision) const
	{
		if (::fabs(this->_numerator - num * this->_denominator) < ::fabs(this->_denominator * precision)) {
			return true;
		}
		return false;
	}

	inline bool real::equal_to(agm_real num, agm_real precision) const
	{
		if (::fabs(this->_numerator * num._denominator - this->_denominator - num._numerator)
			< ::fabs(ZERO * this->_denominator * num._denominator)) {
			return true;
		}
		return false;
	}
}