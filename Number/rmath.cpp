#include "pch.h"
#include "framework.h"
#include "number.h"
#include <cmath>

inline double cos(const real& num)
{
	return cos(double(num));
}

inline double cosh(const real& num)
{
	return cosh(double(num));
}

inline double sin(const real& num)
{
	return sin(double(num));
}

inline double sinh(const real& num)
{
	return sinh(double(num));
}

inline double tan(const real& num)
{
	return tan(double(num));
}

inline double tanh(const real& num)
{
	return tanh(double(num));
}

inline double acos(const real& num)
{
	return acos(double(num));
}

inline double asin(const real& num)
{
	return asin(double(num));
}

inline double atan(const real& num)
{
	return atan(double(num));
}

inline double atan2(const real& num_1, double num_2)
{
	return atan2(num_1._numerator, num_2 * num_1._denominator);
}

inline double atan2(double num_1, const real& num_2)
{
	return atan2(num_1 * num_2._denominator, num_2._numerator);
}

inline double atan2(const real& num_1, const real& num_2)
{
	return atan2(num_1._numerator * num_2._denominator, num_1._denominator * num_2._numerator);
}

inline double atanh(const real& num)
{
	return atanh(double(num));
}

inline double exp(const real& num)
{
	return exp(double(num));
}

inline double exp2(const real& num)
{
	return exp2(double(num));
}

inline double expm1(const real& num)
{
	return expm1(double(num));
}

inline double frexp(const real& num, double* exponent)
{
	return frexp(double(num), exponent);
}

inline double frexp(double num, real& exponent)
{
	exponent.known = true;
	exponent._denominator = 1;
	return frexp(num, &(exponent._numerator));
}

inline double frexp(const real& num, real& exponent)
{
	exponent.known = true;
	exponent._denominator = 1;
	return frexp(double(num), &(exponent._numerator));
}

inline double ldexp(const real& num, int exponent)
{
	return ldexp(num._denominator, exponent);
}

inline double log(const real& num, double base)
{
	return (log(num._numerator) - log(num._denominator)) / log(base);
}

inline double log(double num, const real& base)
{
	return log(num) / (log(base._numerator) - log(base._denominator));
}

inline double log(const real& num, const real& base)
{
	return (log(num._numerator) - log(num._denominator))
		/ (log(base._numerator) - log(base._denominator));
}

inline double log(const real& num)
{
	return log(num._numerator) - log(num._denominator);
}

inline double ln(const real& num)
{
	return log(num);
}

inline double log2(const real& num)
{
	return log2(num._numerator) - log2(num._denominator);
}

inline double log10(const real& num)
{
	return log10(num._numerator) - log10(num._denominator);
}

inline double lg(const real& num)
{
	return log10(num);
}

inline double log1p(const real& num)
{
	return log1p(double(num));
}

inline double copysign(const real& num_1, const real& num_2)
{
	return copysign(double(num_1), double(num_2));
}

inline double modf(const real& num, int* integer)
{
	return modf(double(num), integer);
}

inline double pow(const real& num, double exponent)
{
	return pow(double(num), exponent);
}

inline double pow(double num, const real& exponent)
{
	return pow(num, double(exponent));
}

inline double pow(const real& num, const real& exponent)
{
	return pow(double(num), double(exponent));
}

inline double pow2(const real& num)
{
	return pow(double(num), 2.0);
}

inline double pow10(const real& num)
{
	return pow10(double(num));
}

inline double sqrt(const real& num)
{
	return sqrt(double(num));
}

inline double hypot(const real& x, const real& y)
{
	return hypot(double(x), double(y));
}

inline double poly(const real& x, int n, double* c)
{
	return poly(double(x), n, c);
}

inline double ceil(const real& num)
{
	return ceil(double(num));
}

inline double round(const real& num)
{
	return round(double(num));
}

inline double floor(const real& num)
{
	return floor(double(num));
}

inline double trunc(const real& num)
{
	return trunc(double(num));
}

inline double fabs(const real& num)
{
	return fabs(double(num));
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
