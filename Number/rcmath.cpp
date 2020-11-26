#include "pch.h"
#include "number.h"
#include <cmath>

inline double acos(const real& origin)
{
	return acos(origin.to_double());
}

inline double asin(const real& origin)
{
	return asin(origin.to_double());
}

inline double atan(const real& origin)
{
	if (origin.infinite()) {
		return PI / 2;
	}
	return atan(origin.to_double());
}

inline double atan2(const real& origin, double num)
{
	if (origin.infinite(num)) {
		return PI / 2;
	}
	return atan2(origin._numerator, num * origin._denominator);
}

inline double atan2(double num, const real& origin)
{
	if (origin.zero(num)) {
		return PI / 2;
	}
	return atan2(num * origin._denominator, origin._numerator);
}

inline double atan2(const real& real_1, const real& real_2)
{
	if (real_2.zero(real_1)) {
		return PI / 2;
	}
	return atan2(real_1._numerator * real_2._denominator, real_1._denominator * real_2._numerator);
}

inline double cos(const real& origin)
{
	return cos(origin.to_double());
}

inline double cosh(const real& origin)
{
	return cosh(origin.to_double());
}

inline double sin(const real& origin)
{
	return sin(origin.to_double());
}

inline double sinh(const real& origin)
{
	return sinh(origin.to_double());
}

inline double tan(const real& origin)
{
	if (origin.infinite()) {
		return 0;
	}
	return 0.0;
}

inline double tanh(const real& origin)
{
	return tanh(origin.to_double());
}

inline double exp(const real& origin)
{
	return exp(origin.to_double());
}

inline double frexp(const real& origin, double* exponent)
{
	return frexp(origin.to_double(), exponent);
}

inline double frexp(double num, real& exponent)
{
	exponent.known = true;
	exponent._denominator = 1;
	return frexp(num, &(exponent._numerator));
}

inline double frexp(const real& origin, real& exponent)
{
	exponent.known = true;
	exponent._denominator = 1;
	return frexp(origin.to_double(), &(exponent._numerator));
}

inline double ldexp(const real& origin, int exponent)
{
	return ldexp(origin._denominator, exponent);
}

inline double log(const real& origin, double base)
{
	return (log(origin._numerator) - log(origin._denominator)) / log(base);
}

inline double log(double origin, const real& base)
{
	return log(origin) / (log(base._numerator) - log(base._denominator));
}

inline double log(const real& origin, const real& base)
{
	return (log(origin._numerator) - log(origin._denominator))
		/ (log(base._numerator) - log(base._denominator));
}

inline double ln(const real& origin)
{
	return log(origin._numerator) - log(origin._denominator);
}

inline double log2(const real& origin)
{
	return log2(origin._numerator) - log2(origin._denominator);
}

inline double log10(const real& origin)
{
	return log10(origin._numerator) - log10(origin._denominator);
}

inline double modf(const real& origin, int* integer)
{
	return modf(origin.to_double(), integer);
}

inline double pow(const real& origin, double exponent)
{
	return pow(origin.to_double(), exponent);
}

inline double pow(double num, const real& exponent)
{
	return pow(num, exponent.to_double());
}

inline double pow(const real& origin, const real& exponent)
{
	return pow(origin.to_double(), exponent.to_double());
}

inline double pow2(const real& origin)
{
	return pow(origin.to_double(), 2.0);
}

inline double sqrt(const real& origin)
{
	return sqrt(origin.to_double());
}

inline double ceil(const real& origin)
{
	return ceil(origin.to_double());
}

inline double floor(const real& origin)
{
	return floor(origin.to_double());
}

inline double fabs(const real& real)
{
	return fabs(real.to_double());
}

inline double fmod(const real& num_1, double num_2)
{
	return fmod(num_1._numerator * num_2, num_1._denominator);
}

inline double fmod(double num_1, const real& num_2)
{
	return fmod(num_1 * num_2._denominator, num_2._numerator);
}

inline double fmod(const real& num_1, const real& num_2)
{
	return fmod(num_1._numerator * num_2._denominator, num_1._denominator * num_2._numerator);
}
