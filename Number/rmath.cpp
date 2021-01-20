#include "pch.h"
#include "framework.h"
#include "number.h"
#include <cmath>

inline double cos(const real& num)
{
	return cos(num.todouble());
}

inline double cosh(const real& num)
{
	return cosh(num.todouble());
}

inline double sin(const real& num)
{
	return sin(num.todouble());
}

inline double sinh(const real& num)
{
	return sinh(num.todouble());
}

inline double tan(const real& num)
{
	return tan(num.todouble());
}

inline double tanh(const real& num)
{
	return tanh(num.todouble());
}

inline double acos(const real& num)
{
	return acos(num.todouble());
}

inline double asin(const real& num)
{
	return asin(num.todouble());
}

inline double atan(const real& num)
{
	return atan(num.todouble());
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
	return atanh(num.todouble());
}

inline double exp(const real& num)
{
	return exp(num.todouble());
}

inline double exp2(const real& num)
{
	return exp2(num.todouble());
}

inline double expm1(const real& num)
{
	return expm1(num.todouble());
}

inline double frexp(const real& num, double* exponent)
{
	return frexp(num.todouble(), exponent);
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
	return frexp(num.todouble(), &(exponent._numerator));
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

inline double copysign(const real& num_1, const real& num_2)
{
	return copysign(num_1.todouble(), num_2.todouble());
}

inline double modf(const real& num, int* integer)
{
	return modf(num.todouble(), integer);
}

inline double pow(const real& num, double exponent)
{
	return pow(num.todouble(), exponent);
}

inline double pow(double num, const real& exponent)
{
	return pow(num, exponent.todouble());
}

inline double pow(const real& num, const real& exponent)
{
	return pow(num.todouble(), exponent.todouble());
}

inline double pow2(const real& num)
{
	return pow(num.todouble(), 2.0);
}

inline double pow10(const real& num)
{
	return pow10(num.todouble());
}

inline double sqrt(const real& num)
{
	return sqrt(num.todouble());
}

inline double hypot(const real& x, const real& y)
{
	return hypot(x.todouble(), y.todouble());
}

inline double poly(const real& x, int n, double* c)
{
	return poly(x.todouble(), n, c);
}

inline double ceil(const real& num)
{
	return ceil(num.todouble());
}

inline double floor(const real& num)
{
	return floor(num.todouble());
}

inline double trunc(const real& num)
{
	return trunc(num.todouble());
}

inline double fabs(const real& num)
{
	return fabs(num.todouble());
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
