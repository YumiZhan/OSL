/* OSL/Number/number.cpp
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
#include "framework.h"
#include "number.h"
#include <cmath>
using namespace osl;

#define LIFTING 0x3FFU // 1023U
#define ALLOW_DEVIATION 0x40U // 64U

namespace osl {
	NUMBER_API double PI = 3.1415926535897932;
	NUMBER_API double ZERO = 1E-10;
}

c_str exc::rational::overview_list[] = {
	"numerator is NaN",		// 0
	"denominator is NaN",	// 1
	"both numerator and denominator are infinite"	// 2
};

inline exc::rational::rational(unsigned code, c_str discription) :
	code(code), discription(discription)
{}

inline c_str exc::rational::overview() const
{
	return overview_list[code];
}

void osl::simplify_fraction(double& denominator, double& numerator)
{
	union {
		double db;
		unsigned long long ull;
		unsigned short ush;
	}exp_of_numerator, exp_of_denominator, numerator_copy, denominator_copy;

	if (numerator == 0 || denominator == 0) {
		return;
	}
	if (isinf(numerator) && isinf(denominator)) {
		throw exc::rational(2U, "simplify_fraction(double& denominator, double& numerator)");
	}
	if (isinf(numerator) || isinf(denominator)) {
		return;
	}
	if (isnan(numerator)) {
		throw exc::rational(0U, "simplify_fraction(double& denominator, double& numerator)");
	}
	if (isnan(denominator)) {
		throw exc::rational(1U, "simplify_fraction(double& denominator, double& numerator)");
	}

	numerator_copy.db = numerator; denominator_copy.db = denominator;
	exp_of_numerator.db = numerator; exp_of_denominator.db = denominator;
	exp_of_numerator.ull <<= 1; exp_of_denominator.ull <<= 1;
	exp_of_numerator.ull >>= 53; exp_of_denominator.ull >>= 53;
		
	unsigned short exp_diff(0), exp_sum(exp_of_numerator.ush + exp_of_denominator.ush);
	if (exp_sum >= 2U * (LIFTING + ALLOW_DEVIATION) || exp_sum <= 2U * (LIFTING - ALLOW_DEVIATION)) {
		if (exp_of_numerator.ush > exp_of_denominator.ush) {
			exp_diff = exp_of_numerator.ush - exp_of_denominator.ush;
			exp_of_numerator.ush = LIFTING + exp_diff / 2U;
			exp_of_denominator.ush = LIFTING + exp_diff / 2U - exp_diff;
		}
		else if (exp_of_numerator.ush < exp_of_denominator.ush) {
			exp_diff = exp_of_denominator.ush - exp_of_numerator.ush;
			exp_of_numerator.ush = LIFTING + exp_diff / 2U - exp_diff;
			exp_of_denominator.ush = LIFTING + exp_diff / 2U;
		}
		else { // exp_of_numerator.ush == exp_of_denominator.ush
			exp_of_numerator.ush = exp_of_denominator.ush = LIFTING;
		}
	}
	exp_of_numerator.ull <<= 52; exp_of_denominator.ull <<= 52;

	constexpr unsigned long long bit_operator(0x800FFFFFFFFFFFFFU);
	numerator_copy.ull &= bit_operator; denominator_copy.ull &= bit_operator;
	numerator_copy.ull |= exp_of_numerator.ull; denominator_copy.ull |= exp_of_denominator.ull;
	numerator = numerator_copy.db; denominator = denominator_copy.db;
}

NUMBER_API const complex i(0.0, 1.0);