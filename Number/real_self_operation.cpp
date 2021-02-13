#include "pch.h"
#include "number.h"

namespace osl {
	inline void real::reciprocal()
	{
		double temp = _denominator;
		_denominator = _numerator;
		_numerator = temp;
	}

	inline void real::rabs()
	{
		_numerator = ::fabs(_numerator);
		_denominator = ::fabs(_denominator);
	}

	inline void real::add(double num)
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

	inline void real::subtract(double num)
	{
		_numerator -= num * _denominator;
		simplify();
	}

	inline void real::subtract(const real& num)
	{
		_numerator = _numerator * num._denominator - _denominator * num._numerator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::multiply(double num)
	{
		_numerator *= num;
	}

	inline void real::multiply(const real& num)
	{
		_numerator *= num._numerator;
		_denominator *= num._denominator;
		if (!num.known) {
			known = false;
		}
		simplify();
	}

	inline void real::divide(double num)
	{
		_denominator *= num;
		simplify();
	}

	inline void real::divide(const real& num)
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