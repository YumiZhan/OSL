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

	inline void real::add(argument num)
	{
		_numerator += num * _denominator;
		simplify();
	}

	inline void real::add(const real& num)
	{
		_numerator = _numerator * num._denominator + _denominator * num._denominator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::sub(argument num)
	{
		_numerator -= num * _denominator;
		simplify();
	}

	inline void real::sub(const real& num)
	{
		_numerator = _numerator * num._denominator - _denominator * num._numerator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::mul(argument num)
	{
		_numerator *= num;
	}

	inline void real::mul(const real& num)
	{
		_numerator *= num._numerator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::div(argument num)
	{
		_denominator *= num;
		simplify();
	}

	inline void real::div(const real& num)
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