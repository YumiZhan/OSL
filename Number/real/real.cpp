//#include "pch.h"
#include "real.h"

inline real::real() :
	finite(true), known(false), _denominator(1), _numerator(0), name()
{}

inline real::real(const real& origin, string name) :
	finite(origin.finite), known(origin.known), name(name), _denominator(origin._denominator), _numerator(origin._numerator)
{
	if (!name.empty()) {
		return;
	}
	else if (!origin.name.empty()) {
		this->name = origin.name + "_copy";
	}
}

inline real::real(double num, string name) :
	finite(true), known(true), name(name), _denominator(1), _numerator(num)
{}

inline real::real(double numerator, double denominator, string name) :
	finite(true), known(true), _denominator(denominator), _numerator(numerator), name(name)
{
	finite = !infinite();
}

inline real abs(const real& origin)
{
	return real(fabs(origin._denominator), fabs(origin._numerator));
}

inline double real::fabs() const
{
	return ::fabs(_numerator / _denominator);
}

inline double real::to_double() const
{
	return _numerator / _denominator;
}

inline bool real::zero(double num) const
{
	if (::fabs(_numerator) < ::fabs(_denominator * num * ZERO)) {
		return true;
	}
	return false;
}

inline bool real::zero(const real& origin) const
{
	if (::fabs(_numerator * origin._denominator) < ::fabs(_denominator * origin._numerator * ZERO)) {
		return true;
	}
	return false;
}

inline bool real::infinite(double num) const
{
	if (::fabs(_numerator * ZERO) > ::fabs(_denominator * num)) {
		return true;
	}
	return false;
}

inline bool real::infinite(const real& real) const
{
	if (::fabs(_numerator * real._denominator * ZERO) > ::fabs(_denominator * real._numerator)) {
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
	if (finite) {
		cout << to_double() << endl;
	}
	else {
		cout << "INFINITE\n";
	}
}
