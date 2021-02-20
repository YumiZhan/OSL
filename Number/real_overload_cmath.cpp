/* OSL/Number/real_overload_cmath.cpp
 *
 * Copyright (C) 2021 YuminZhan
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this
 * program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "pch.h"
#include "number.h"
#include <cmath>

namespace osl {
	inline double cos(agm_real num)
	{
		return std::cos(double(num));
	}

	inline double cosh(agm_real num)
	{
		return std::cosh(double(num));
	}

	inline double sin(agm_real num)
	{
		return std::sin(double(num));
	}

	inline double sinh(agm_real num)
	{
		return std::sinh(double(num));
	}

	inline double tan(agm_real num)
	{
		return std::tan(double(num));
	}

	inline double tanh(agm_real num)
	{
		return std::tanh(double(num));
	}

	inline double acos(agm_real num)
	{
		return std::acos(double(num));
	}

	double acosh(agm_real num)
	{
		return std::acosh(double(num));
	}

	inline double asin(agm_real num)
	{
		return std::asin(double(num));
	}

	double asinh(agm_real num)
	{
		return std::asinh(double(num));
	}

	inline double atan(agm_real num)
	{
		return std::atan(double(num));
	}

	inline double atan2(agm_real num_1, agm num_2)
	{
		return std::atan2(num_1._numerator, num_2 * num_1._denominator);
	}

	inline double atan2(agm num_1, agm_real num_2)
	{
		return std::atan2(num_1 * num_2._denominator, num_2._numerator);
	}

	inline double atan2(agm_real num_1, agm_real num_2)
	{
		return std::atan2(num_1._numerator * num_2._denominator, num_1._denominator * num_2._numerator);
	}

	inline double atanh(agm_real num)
	{
		return std::atanh(double(num));
	}

	inline double exp(agm_real num)
	{
		return std::exp(double(num));
	}

	inline double exp2(agm_real num)
	{
		return std::exp2(double(num));
	}

	inline double expm1(agm_real num)
	{
		return std::expm1(double(num));
	}

	inline double frexp(agm_real num, int* exponent)
	{
		return std::frexp(double(num), exponent);
	}

	inline double ldexp(agm_real num, int exponent)
	{
		return std::ldexp(num._denominator, exponent);
	}

	inline double log(agm_real num, agm base)
	{
		return (std::log(num._numerator) - std::log(num._denominator)) / std::log(base);
	}

	inline double log(agm num, agm_real base)
	{
		return std::log(num) / (std::log(base._numerator) - std::log(base._denominator));
	}

	inline double log(agm_real num, agm_real base)
	{
		return (std::log(num._numerator) - std::log(num._denominator))
			/ (std::log(base._numerator) - std::log(base._denominator));
	}

	inline double log(agm_real num)
	{
		return std::log(num._numerator) - std::log(num._denominator);
	}

	inline double ln(agm_real num)
	{
		return log(num);
	}

	inline double log2(agm_real num)
	{
		return std::log2(num._numerator) - std::log2(num._denominator);
	}

	inline double log10(agm_real num)
	{
		return std::log10(num._numerator) - std::log10(num._denominator);
	}

	inline double lg(agm_real num)
	{
		return log10(num);
	}

	inline double log1p(agm_real num)
	{
		return std::log1p(double(num));
	}

	inline double copysign(agm_real num_1, agm_real num_2)
	{
		return std::copysign(double(num_1), double(num_2));
	}

	inline double modf(agm_real num, double* integer)
	{
		return std::modf(double(num), integer);
	}

	double modf(agm num, real& integer)
	{
		integer._denominator = 1;
		return std::modf(num, &integer._numerator);
	}

	double modf(agm_real num, real& integer)
	{
		integer._denominator = 1;
		return std::modf(double(num), &integer._numerator);
	}

	inline double pow(agm_real num, agm exponent)
	{
		return std::pow(double(num), exponent);
	}

	inline double pow(agm num, agm_real exponent)
	{
		return std::pow(num, double(exponent));
	}

	inline double pow(agm_real num, agm_real exponent)
	{
		return std::pow(double(num), double(exponent));
	}

	inline double pow2(agm_real num)
	{
		return std::pow(double(num), 2.0);
	}

	inline double pow10(agm_real num)
	{
		return std::pow(double(num), 10.0);
	}

	inline double sqrt(agm_real num)
	{
		return std::sqrt(double(num));
	}

	inline double hypot(agm_real x, agm_real y)
	{
		return std::hypot(double(x), double(y));
	}

	inline double ceil(agm_real num)
	{
		return std::ceil(double(num));
	}

	inline double round(agm_real num)
	{
		return std::round(double(num));
	}

	inline double floor(agm_real num)
	{
		return std::floor(double(num));
	}

	inline double trunc(agm_real num)
	{
		return std::trunc(double(num));
	}

	inline double fabs(agm_real num)
	{
		return std::fabs(double(num));
	}

	inline double fmod(agm_real num_1, agm num_2)
	{
		return std::fmod(num_1._numerator * num_2, num_1._denominator);
	}

	inline double fmod(agm num_1, agm_real num_2)
	{
		return std::fmod(num_1 * num_2._denominator, num_2._numerator);
	}

	inline double fmod(agm_real num_1, agm_real num_2)
	{
		return std::fmod(num_1._numerator * num_2._denominator, num_1._denominator * num_2._numerator);
	}
}