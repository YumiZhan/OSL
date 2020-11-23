#include "real.h"

inline ostream& operator<<(ostream& os, const real& origin)
{
	os << origin.to_double();
	return os;
}

inline istream& operator>>(istream& is, real& origin)
{
	origin.finite = true;
	origin.known = true;
	is >> origin._numerator;
	origin._denominator = 1;
	return is;
}

inline real operator~(const real& origin)
{
	return real(origin._denominator, origin._numerator);
}

inline real operator&(const real& real_1, const real& real_2)
{
	return real(real_1._numerator + real_2._numerator, real_1._denominator + real_2._denominator);
}

inline real operator|(const real& real_1, const real& real_2)
{
	return real(real_1._numerator - real_2._numerator, real_1._denominator - real_2._denominator);
}

inline real operator+(const real& origin, double num)
{
	return real(origin._numerator + num * origin._denominator, origin._denominator);
}

inline real operator+(double num, const real& origin)
{
	return real(origin._numerator + num * origin._denominator, origin._denominator);
}

inline real operator+(const real& real_1, const real& real_2)
{
	return real(real_1._numerator * real_2._denominator + real_1._denominator + real_2._numerator,
		real_1._denominator * real_2._denominator);
}
