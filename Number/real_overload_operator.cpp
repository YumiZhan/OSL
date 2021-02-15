#include "pch.h"
#include "number.h"
#include <iostream>

namespace osl {
	inline real::operator double() const
	{
		return _numerator / _denominator;
	}

	inline std::ostream& operator<<(std::ostream& os, agm_real output_real)
	{
		if (output_real.known) {
			os << double(output_real);
		}
		else {
			os << "unknow";
		}
		return os;
	}

	inline std::istream& operator >>(std::istream& is, real& input_real)
	{
		input_real.known = true;
		is >> input_real._numerator;
		input_real._denominator = 1;
		return is;
	}

	inline real operator ~(agm_real num)
	{
		real temp(num);
		temp.rec();
		return temp;
	}

	inline real& real::operator +=(agm num)
	{
		this->add(num);
		return *this;
	}

	inline real& real::operator +=(agm_real num)
	{
		this->add(num);
		return *this;
	}

	inline real& real::operator -=(agm num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator -=(agm_real num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator *=(agm num)
	{
		this->mul(num);
		return *this;
	}

	inline real& real::operator *=(agm_real num)
	{
		this->mul(num);
		return *this;
	}

	inline real& real::operator /=(agm num)
	{
		this->sub(num);
		return *this;
	}

	inline real& real::operator /=(agm_real num)
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

	inline real operator +(agm_real num_1, agm num_2)
	{
		real temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline real operator +(agm num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline real operator +(agm_real num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.add(num_2);
		return temp;
	}

	inline real operator -(agm_real num_1, agm num_2)
	{
		real temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline real operator -(agm num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline real operator -(agm_real num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.sub(num_2);
		return temp;
	}

	inline real operator -(agm_real num)
	{
		real temp(num);
		temp._numerator = -temp._numerator;
		return temp;
	}

	inline real operator *(agm_real num_1, agm num_2)
	{
		real temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline real operator *(agm num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline real operator *(agm_real num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.mul(num_2);
		return temp;
	}

	inline real operator /(agm_real num_1, agm num_2)
	{
		real temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline real operator /(agm num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline real operator /(agm_real num_1, agm_real num_2)
	{
		real temp(num_1);
		temp.div(num_2);
		return temp;
	}

	inline bool operator ==(agm_real num_1, agm num_2)
	{
		return num_1.equal_to(num_2);
	}

	inline bool operator ==(agm num_1, agm_real num_2)
	{
		return num_2.equal_to(num_1);
	}

	inline bool operator ==(agm_real num_1, agm_real num_2)
	{
		return num_1.equal_to(num_2);
	}

	inline bool operator !=(agm_real num_1, agm num_2)
	{
		return !num_1.equal_to(num_2);
	}

	inline bool operator !=(agm num_1, agm_real num_2)
	{
		return !num_2.equal_to(num_1);
	}

	inline bool operator !=(agm_real num_1, agm_real num_2)
	{
		return !num_1.equal_to(num_2);
	}

	inline bool operator <(agm_real num_1, agm num_2)
	{
		return num_1.less_than(num_2);
	}

	inline bool operator <(agm num_1, agm_real num_2)
	{
		return num_2.larger_than(num_1);
	}

	inline bool operator <(agm_real num_1, agm_real num_2)
	{
		return num_1.less_than(num_2);
	}

	inline bool operator <=(agm_real num_1, agm num_2)
	{
		return num_1.not_larger_than(num_2);
	}

	inline bool operator <=(agm num_1, agm_real num_2)
	{
		return num_2.not_less_than(num_1);
	}

	inline bool operator <=(agm_real num_1, agm_real num_2)
	{
		return num_1.not_larger_than(num_2);
	}

	inline bool operator >(agm_real num_1, agm num_2)
	{
		return num_1.larger_than(num_2);
	}

	inline bool operator >(agm num_1, agm_real num_2)
	{
		return num_2.less_than(num_1);
	}

	inline bool operator >(agm_real num_1, agm_real num_2)
	{
		return num_1.larger_than(num_2);
	}

	inline bool operator >=(agm_real num_1, agm num_2)
	{
		return num_1.not_less_than(num_2);
	}

	inline bool operator >=(agm num_1, agm_real num_2)
	{
		return num_2.not_larger_than(num_1);
	}

	inline bool operator >=(agm_real num_1, agm_real num_2)
	{
		return num_1.not_less_than(num_2);
	}

	inline bool operator !(agm_real num)
	{
		return !num.known;
	}
}