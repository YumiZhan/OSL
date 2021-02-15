#include "pch.h"
#include "number.h"
#include <iostream>
using std::ostream;
using std::istream;

namespace osl {
	inline real::operator double() const
	{
		return _numerator / _denominator;
	}

	inline ostream& operator <<(ostream& os, const real& num)
	{
		if (num.known) {
			os << double(num);
		}
		else {
			os << "unknow";
		}
		return os;
	}

	inline istream& operator >>(istream& is, real& num)
	{
		num.known = true;
		is >> num._numerator;
		num._denominator = 1;
		return is;
	}

	inline real operator ~(const real& num)
	{
		real temp(num);
		temp.rec();
		return temp;
	}

	inline real& real::operator +=(argument num)
	{
		this->add(num);
		return *this;
	}

	inline real& real::operator +=(const real& num)
	{
		this->add(num);
		return *this;
	}

	inline real& real::operator -=(argument num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator -=(const real& num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator *=(argument num)
	{
		this->mul(num);
		return *this;
	}

	inline real& real::operator *=(const real& num)
	{
		this->mul(num);
		return *this;
	}

	inline real& real::operator /=(argument num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator /=(const real& num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator ++()
	{
		this->add(1);
		return *this;
	}

	inline real real::operator ++(int)
	{
		real temp(*this);
		this->add(1);
		return temp;
	}

	inline real& real::operator --()
	{
		this->sub(1);
		return *this;
	}

	inline real real::operator --(int)
	{
		real temp(*this);
		this->sub(1);
		return temp;
	}

	inline real operator +(const real& num_1, argument num_2)
	{
		real temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline real operator +(argument num_1, const real& num_2)
	{
		real temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline real operator +(const real& num_1, const real& num_2)
	{
		real temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline real operator -(const real& num_1, argument num_2)
	{
		real temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline real operator -(argument num_1, const real& num_2)
	{
		real temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline real operator -(const real& num_1, const real& num_2)
	{
		real temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline real operator -(const real& num)
	{
		real temp(num);
		temp._numerator = -temp._numerator;
		return temp;
	}

	inline real operator *(const real& num_1, argument num_2)
	{
		real temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline real operator *(argument num_1, const real& num_2)
	{
		real temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline real operator *(const real& num_1, const real& num_2)
	{
		real temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline real operator /(const real& num_1, argument num_2)
	{
		real temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline real operator /(argument num_1, const real& num_2)
	{
		real temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline real operator /(const real& num_1, const real& num_2)
	{
		real temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline bool operator ==(const real& num_1, argument num_2)
	{
		return num_1.equal_to(num_2);
	}

	inline bool operator ==(argument num_1, const real& num_2)
	{
		return num_2.equal_to(num_1);
	}

	inline bool operator ==(const real& num_1, const real& num_2)
	{
		return num_1.equal_to(num_2);
	}

	inline bool operator !=(const real& num_1, argument num_2)
	{
		return !num_1.equal_to(num_2);
	}

	inline bool operator !=(argument num_1, const real& num_2)
	{
		return !num_2.equal_to(num_1);
	}

	inline bool operator !=(const real& num_1, const real& num_2)
	{
		return !num_1.equal_to(num_2);
	}

	inline bool operator <(const real& num_1, argument num_2)
	{
		return num_1.less_than(num_2);
	}

	inline bool operator <(argument num_1, const real& num_2)
	{
		return num_2.larger_than(num_1);
	}

	inline bool operator <(const real& num_1, const real& num_2)
	{
		return num_1.less_than(num_2);
	}

	inline bool operator <=(const real& num_1, argument num_2)
	{
		return num_1.not_larger_than(num_2);
	}

	inline bool operator <=(argument num_1, const real& num_2)
	{
		return num_2.not_less_than(num_1);
	}

	inline bool operator <=(const real& num_1, const real& num_2)
	{
		return num_1.not_larger_than(num_2);
	}

	inline bool operator >(const real& num_1, argument num_2)
	{
		return num_1.larger_than(num_2);
	}

	inline bool operator >(argument num_1, const real& num_2)
	{
		return num_2.less_than(num_1);
	}

	inline bool operator >(const real& num_1, const real& num_2)
	{
		return num_1.larger_than(num_2);
	}

	inline bool operator >=(const real& num_1, argument num_2)
	{
		return num_1.not_less_than(num_2);
	}

	inline bool operator >=(argument num_1, const real& num_2)
	{
		return num_2.not_larger_than(num_1);
	}

	inline bool operator >=(const real& num_1, const real& num_2)
	{
		return num_1.not_less_than(num_2);
	}

	inline bool operator !(const real& num)
	{
		return !num.known;
	}
}