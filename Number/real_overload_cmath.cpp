#include "pch.h"
#include "number.h"
#include <cmath>

namespace osl {
	inline double cos(const real& num)
	{
		return std::cos(double(num));
	}

	inline double cosh(const real& num)
	{
		return std::cosh(double(num));
	}

	inline double sin(const real& num)
	{
		return std::sin(double(num));
	}

	inline double sinh(const real& num)
	{
		return std::sinh(double(num));
	}

	inline double tan(const real& num)
	{
		return std::tan(double(num));
	}

	inline double tanh(const real& num)
	{
		return std::tanh(double(num));
	}

	inline double acos(const real& num)
	{
		return std::acos(double(num));
	}

	double acosh(const real& num)
	{
		return std::acosh(double(num));
	}

	inline double asin(const real& num)
	{
		return std::asin(double(num));
	}

	double asinh(const real& num)
	{
		return std::asinh(double(num));
	}

	inline double atan(const real& num)
	{
		return std::atan(double(num));
	}

	inline double atan2(const real& num_1, number num_2)
	{
		return std::atan2(num_1._numerator, num_2 * num_1._denominator);
	}

	inline double atan2(number num_1, const real& num_2)
	{
		return std::atan2(num_1 * num_2._denominator, num_2._numerator);
	}

	inline double atan2(const real& num_1, const real& num_2)
	{
		return std::atan2(num_1._numerator * num_2._denominator, num_1._denominator * num_2._numerator);
	}

	inline double atanh(const real& num)
	{
		return std::atanh(double(num));
	}

	inline double exp(const real& num)
	{
		return std::exp(double(num));
	}

	inline double exp2(const real& num)
	{
		return std::exp2(double(num));
	}

	inline double expm1(const real& num)
	{
		return std::expm1(double(num));
	}

	inline double frexp(const real& num, int* exponent)
	{
		return std::frexp(double(num), exponent);
	}

	inline double ldexp(const real& num, int exponent)
	{
		return std::ldexp(num._denominator, exponent);
	}

	inline double log(const real& num, number base)
	{
		return (std::log(num._numerator) - std::log(num._denominator)) / std::log(base);
	}

	inline double log(number num, const real& base)
	{
		return std::log(num) / (std::log(base._numerator) - std::log(base._denominator));
	}

	inline double log(const real& num, const real& base)
	{
		return (std::log(num._numerator) - std::log(num._denominator))
			/ (std::log(base._numerator) - std::log(base._denominator));
	}

	inline double log(const real& num)
	{
		return std::log(num._numerator) - std::log(num._denominator);
	}

	inline double ln(const real& num)
	{
		return log(num);
	}

	inline double log2(const real& num)
	{
		return std::log2(num._numerator) - std::log2(num._denominator);
	}

	inline double log10(const real& num)
	{
		return std::log10(num._numerator) - std::log10(num._denominator);
	}

	inline double lg(const real& num)
	{
		return log10(num);
	}

	inline double log1p(const real& num)
	{
		return std::log1p(double(num));
	}

	inline double copysign(const real& num_1, const real& num_2)
	{
		return std::copysign(double(num_1), double(num_2));
	}

	inline double modf(const real& num, double* integer)
	{
		return std::modf(double(num), integer);
	}

	double modf(number num, real& integer)
	{
		integer._denominator = 1;
		return std::modf(num, &integer._numerator);
	}

	double modf(const real& num, real& integer)
	{
		integer._denominator = 1;
		return std::modf(double(num), &integer._numerator);
	}

	inline double pow(const real& num, number exponent)
	{
		return std::pow(double(num), exponent);
	}

	inline double pow(number num, const real& exponent)
	{
		return std::pow(num, double(exponent));
	}

	inline double pow(const real& num, const real& exponent)
	{
		return std::pow(double(num), double(exponent));
	}

	inline double pow2(const real& num)
	{
		return std::pow(double(num), 2.0);
	}

	inline double pow10(const real& num)
	{
		return std::pow(double(num), 10.0);
	}

	inline double sqrt(const real& num)
	{
		return std::sqrt(double(num));
	}

	inline double hypot(const real& x, const real& y)
	{
		return std::hypot(double(x), double(y));
	}

	inline double ceil(const real& num)
	{
		return std::ceil(double(num));
	}

	inline double round(const real& num)
	{
		return std::round(double(num));
	}

	inline double floor(const real& num)
	{
		return std::floor(double(num));
	}

	inline double trunc(const real& num)
	{
		return std::trunc(double(num));
	}

	inline double fabs(const real& num)
	{
		return std::fabs(double(num));
	}

	inline double fmod(const real& num_1, number num_2)
	{
		return std::fmod(num_1._numerator * num_2, num_1._denominator);
	}

	inline double fmod(number num_1, const real& num_2)
	{
		return std::fmod(num_1 * num_2._denominator, num_2._numerator);
	}

	inline double fmod(const real& num_1, const real& num_2)
	{
		return std::fmod(num_1._numerator * num_2._denominator, num_1._denominator * num_2._numerator);
	}
}