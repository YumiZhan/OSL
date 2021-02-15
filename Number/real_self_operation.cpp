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