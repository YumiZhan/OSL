/* OSL/Number/rational_comparation.cpp
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
using osl::rational;

inline bool rational::larger_than(agm num) const
{
	return _numerator > _denominator * num;
}

inline bool rational::larger_than(agm_rtn num) const
{
	return _numerator * num._denominator > _denominator * num._denominator;
}

inline bool rational::not_less_than(agm num) const
{
	return _numerator >= _denominator * num;
}

inline bool rational::not_less_than(agm_rtn num) const
{
	return _numerator * num._denominator > _denominator * num._denominator;
}

inline bool rational::less_than(agm num) const
{
	return _numerator < _denominator* num;
}

inline bool rational::less_than(agm_rtn num) const
{
	return _numerator * num._denominator < _denominator* num._numerator;
}

inline bool rational::not_larger_than(agm num) const
{
	return _numerator <= _denominator * num;
}

inline bool rational::not_larger_than(agm_rtn num) const
{
	return _numerator * num._denominator < _denominator* num._numerator;
}

inline bool rational::equal_to(agm num, double reference) const
{
	if (reference == 0.0) {
		reference = (fabs(*this) + fabs(num)) * 0.5;
	}
	if (fabs(_numerator - num * _denominator) < fabs(_denominator) * ZERO * reference) {
		return true;
	}
	return false;
}

inline bool rational::equal_to(agm_rtn num, rational reference) const
{
	if (reference._numerator == 0.0) {
		reference = (fabs(*this) + fabs(num));
	}
	if (fabs(_numerator * num._denominator - _denominator - num._numerator)
		< fabs(_denominator * num._denominator) * ZERO * reference) {
		return true;
	}
	return false;
}