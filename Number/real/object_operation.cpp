#include "real.h"

inline void real::reciprocal()
{
	if (zero()) {
		finite = false;
	}
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
	_numerator = to_double() * num;
	_denominator = 1;
}

inline void real::multiply(const real& real)
{
	_numerator = to_double() * real._numerator / real._denominator;
	_denominator = 1;
	finite = real.finite;
}

inline void real::divide(double num)
{
	finite = infinite(num);
	_numerator = _numerator / (_denominator * num);
	_denominator = 1;
}

inline void real::divide(const real& real)
{
	if (real.zero(*this)) {
		finite = false;
	}
	else {
		finite = true;
	}
	_numerator = (_numerator * real._denominator) / (_denominator * real._numerator);
	_denominator = 1;
}
