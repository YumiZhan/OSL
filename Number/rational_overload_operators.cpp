/* OSL/Number/rational_overload_operators.cpp
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
#include <iostream>

namespace osl {
	inline rational::operator double() const
	{
		return _numerator / _denominator;
	}

	inline std::ostream& operator<<(std::ostream& os, agm_rational output_rational)
	{
		if (output_rational.known) {
			os << double(output_rational);
		}
		else {
			os << "unknow";
		}
		return os;
	}

	inline std::istream& operator >>(std::istream& is, rational& input_rational)
	{
		input_rational.known = true;
		is >> input_rational._numerator;
		input_rational._denominator = 1;
		return is;
	}

	inline rational operator ~(agm_rational num)
	{
		rational temp(num);
		temp.rec();
		return temp;
	}

	inline rational& rational::operator +=(agm num)
	{
		this->add(num);
		return *this;
	}

	inline rational& rational::operator +=(agm_rational num)
	{
		this->add(num);
		return *this;
	}

	inline rational& rational::operator -=(agm num)
	{
		this->sub(num);
		return *this;
	}

	inline rational& rational::operator -=(agm_rational num)
	{
		this->sub(num);
		return *this;
	}

	inline rational& rational::operator *=(agm num)
	{
		this->mul(num);
		return *this;
	}

	inline rational& rational::operator *=(agm_rational num)
	{
		this->mul(num);
		return *this;
	}

	inline rational& rational::operator /=(agm num)
	{
		this->sub(num);
		return *this;
	}

	inline rational& rational::operator /=(agm_rational num)
	{
		this->sub(num);
		return *this;
	}

	inline rational& rational::operator ^=(agm num)
	{
		return *this = pow(*this, num);
	}

	inline rational& rational::operator ^=(agm_rational num)
	{
		return *this = pow(*this, num);
	}

	inline rational& rational::operator ++()
	{
		this->add(1);
		return *this;
	}

	inline rational rational::operator ++(int)
	{
		rational temp(*this);
		this->add(1);
		return temp;
	}

	inline rational& rational::operator --()
	{
		this->sub(1);
		return *this;
	}

	inline rational rational::operator --(int)
	{
		rational temp(*this);
		this->sub(1);
		return temp;
	}

	inline rational operator +(agm_rational num)
	{
		return num;
	}

	inline rational operator -(agm_rational num)
	{
		rational temp(num);
		temp._numerator = -temp._numerator;
		return temp;
	}

	inline rational operator +(agm_rational num_1, agm num_2)
	{
		rational temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline rational operator +(agm num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline rational operator +(agm_rational num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline rational operator -(agm_rational num_1, agm num_2)
	{
		rational temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline rational operator -(agm num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline rational operator -(agm_rational num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline rational operator *(agm_rational num_1, agm num_2)
	{
		rational temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline rational operator *(agm num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline rational operator *(agm_rational num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline rational operator /(agm_rational num_1, agm num_2)
	{
		rational temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline rational operator /(agm num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline rational operator /(agm_rational num_1, agm_rational num_2)
	{
		rational temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline rational operator ^(agm_rational num_1, agm_rational num_2)
	{
		return pow(num_1, num_2);
	}

	inline rational operator ^(agm num_1, agm_rational num_2)
	{
		return pow(num_1, num_2);
	}

	inline rational operator ^(agm_rational num_1, agm num_2)
	{
		return pow(num_1, num_2);
	}

	inline bool operator ==(agm_rational num_1, agm num_2)
	{
		return num_1.equal_to(num_2);
	}

	inline bool operator ==(agm num_1, agm_rational num_2)
	{
		return num_2.equal_to(num_1);
	}

	inline bool operator ==(agm_rational num_1, agm_rational num_2)
	{
		return num_1.equal_to(num_2);
	}

	inline bool operator !=(agm_rational num_1, agm num_2)
	{
		return !num_1.equal_to(num_2);
	}

	inline bool operator !=(agm num_1, agm_rational num_2)
	{
		return !num_2.equal_to(num_1);
	}

	inline bool operator !=(agm_rational num_1, agm_rational num_2)
	{
		return !num_1.equal_to(num_2);
	}

	inline bool operator <(agm_rational num_1, agm num_2)
	{
		return num_1.less_than(num_2);
	}

	inline bool operator <(agm num_1, agm_rational num_2)
	{
		return num_2.larger_than(num_1);
	}

	inline bool operator <(agm_rational num_1, agm_rational num_2)
	{
		return num_1.less_than(num_2);
	}

	inline bool operator <=(agm_rational num_1, agm num_2)
	{
		return num_1.not_larger_than(num_2);
	}

	inline bool operator <=(agm num_1, agm_rational num_2)
	{
		return num_2.not_less_than(num_1);
	}

	inline bool operator <=(agm_rational num_1, agm_rational num_2)
	{
		return num_1.not_larger_than(num_2);
	}

	inline bool operator >(agm_rational num_1, agm num_2)
	{
		return num_1.larger_than(num_2);
	}

	inline bool operator >(agm num_1, agm_rational num_2)
	{
		return num_2.less_than(num_1);
	}

	inline bool operator >(agm_rational num_1, agm_rational num_2)
	{
		return num_1.larger_than(num_2);
	}

	inline bool operator >=(agm_rational num_1, agm num_2)
	{
		return num_1.not_less_than(num_2);
	}

	inline bool operator >=(agm num_1, agm_rational num_2)
	{
		return num_2.not_larger_than(num_1);
	}

	inline bool operator >=(agm_rational num_1, agm_rational num_2)
	{
		return num_1.not_less_than(num_2);
	}

	inline bool operator !(agm_rational num)
	{
		return !num.known;
	}
}