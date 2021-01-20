#include "pch.h"
#include "framework.h"
#include "number.h"

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
}

inline void real::add(const real& num)
{
	_numerator = _numerator * num._denominator + _denominator * num._denominator;
	_denominator *= num._denominator;
	if (!num.known) {
		known = false;
	}
}

inline void real::subtract(double num)
{
	_numerator -= num * _denominator;
}

inline void real::subtract(const real& num)
{
	_numerator = _numerator * num._denominator - _denominator * num._numerator;
	_denominator *= num._denominator;
	if (!num.known) {
		known = false;
	}
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
}

inline void real::divide(double num)
{
	_denominator *= num;
}

inline void real::divide(const real& num)
{
	_numerator *= num._denominator;
	_denominator *= num._numerator;
	if (!num.known) {
		known = false;
	}
}