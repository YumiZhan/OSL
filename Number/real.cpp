#include "pch.h"
#include "number.h"

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

inline double real::to_double() const
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

inline void real::print(double reference) const
{
	if (infinite(reference)) {
		cout << "INFINITE\n";
	}
	else {
		cout << to_double() << endl;
	}
}
