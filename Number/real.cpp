#include "pch.h"
#include "framework.h"
#include "number.h"
using namespace std;

inline real::real() :
	known(false), _denominator(1), _numerator(0)
{}

inline real::real(const real& origin) :
	known(origin.known), _denominator(origin._denominator), _numerator(origin._numerator)
{}

inline real::real(double num) :
	known(true), _denominator(1), _numerator(num)
{}

inline real::real(double numerator, double denominator) :
	known(true), _denominator(denominator), _numerator(numerator)
{}

real::real(const char* str, const int length) :
	known(true), _denominator(1), _numerator(0)
{
	int i, decimal = 0;
	for (i = 0; i < length; i++) {
		if (str[i] == '.') {
			i++;
			decimal = length - i;
			break;
		}
		_numerator *= 10;
		_numerator += double(str[i]) - '0';
	}
	for (i = 0; i < decimal; i++) {
		_numerator += (double(str[i + length - decimal]) - '0') * pow(10, i - decimal);
	}
}

inline real abs(const real& origin)
{
	return real(fabs(origin._numerator), fabs(origin._denominator));
}

inline real real::abs() const
{
	return real(::fabs(_numerator), ::fabs(_denominator));
}

inline double real::fabs() const
{
	return ::fabs(_numerator / _denominator);
}

inline double real::todouble() const
{
	return _numerator / _denominator;
}

inline bool real::zero(double reference) const
{
	if (::fabs(_numerator) < ::fabs(_denominator * reference * ZERO)) {
		return true;
	}
	return false;
}

inline bool real::zero(const real& reference) const
{
	if (::fabs(_numerator * reference._denominator)
		< ::fabs(_denominator * reference._numerator * ZERO)) {
		return true;
	}
	return false;
}

inline bool real::infinite(double reference) const
{
	if (::fabs(_numerator * ZERO) > ::fabs(_denominator * reference)) {
		return true;
	}
	return false;
}

inline bool real::infinite(const real& reference) const
{
	if (::fabs(_numerator * reference._denominator * ZERO)
		> ::fabs(_denominator * reference._numerator)) {
		return true;
	}
	return false;
}

inline double real::denominator() const
{
	return _denominator;
}

inline double real::numerator() const
{
	return _numerator;
}

inline void real::print() const
{
	cout << *this << endl;
}

inline void print(const real& num)
{
	cout << num << endl;
}

inline real real::to_radian() const
{
	return real(this->_numerator * PI, this->_denominator * 180);
}

inline real real::to_degree() const
{
	return real(this->_numerator * 180, this->_denominator * PI);
}