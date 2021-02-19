#include "pch.h"
#include "framework.h"
#include "number.h"

#define LIFTING 0x3FFU // 1023U
#define ALLOW_DEVIATION 0x40U // 64U

namespace osl {
	NUMBER_API double PI = 3.1415926535897932;
	NUMBER_API double ZERO = 1E-10;

	NUMBER_API inline void simplify_fraction(double& denominator, double& numerator)
	{
		union {
			double db;
			unsigned long long ull;
			unsigned short ush;
		}exp_of_numerator, exp_of_denominator, numerator_copy, denominator_copy;

		if (denominator == 0 || numerator == 0) {
			return;
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
}