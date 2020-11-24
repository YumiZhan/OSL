#include "real.h"

inline void real::reciprocal()
{
	finite = !zero();
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

inline void real::add(const real& real)
{
	_numerator = _numerator * real._denominator + _denominator * real._denominator;
	_denominator *= real._denominator;
}

inline void real::subtract(double num)
{
	_numerator -= num * _denominator;
}

inline void real::subtract(const real& real)
{
	_numerator = _numerator * real._denominator - _denominator * real._denominator;
	_denominator *= real._denominator;
}

inline void real::multiply(double num)
{
	_numerator *= num;
}

inline void real::multiply(const real& real)
{
	_numerator *= real._numerator;
	_denominator *= real._denominator;
	finite = real.finite;
}

inline void real::divide(double num)
{
	finite = !zero(num);
	_denominator *= num;
}

inline void real::divide(const real& real)
{
	finite = !real.zero(*this);
	_numerator *= real._numerator;
	_denominator *= real._denominator;
}
