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

inline real::real(const char* c_str) :
	known(true), _denominator(1), _numerator(atof(c_str))
{
	/*
	int i, decimal = 0;
	for (i = 0; i < length; i++) {
		if (c_str[i] == '.') {
			i++;
			decimal = length - i;
			break;
		}
		_numerator *= 10;
		_numerator += double(c_str[i]) - '0';
	}
	for (i = 0; i < decimal; i++) {
		_numerator += (double(c_str[i + length - decimal]) - '0') * pow(10, i - decimal);
	}*/
}

inline real::real(const wchar_t* w_str) :
	known(true), _denominator(1), _numerator(_wtof(w_str))
{}

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