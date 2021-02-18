#include "pch.h"
#include "number.h"
#include <cmath>
#include <string>
using std::string;

#define POSITIVE 1.0
#define NEGATIVE -1.0

namespace osl {
	inline std::ostream& operator <<(std::ostream& os, agm_cpl cpl)
	{
		if (cpl._real != 0.0) {
			os << cpl._real;
			if (cpl._imag > 0.0)
				os << '+';
		}
		else if (cpl._imag == 0.0) {
			os << 0.0;
			return os;
		}
		if (cpl._imag > 0.0) {
			if (cpl._imag != 1.0)
				os << cpl._imag;
			os << 'i';
		}
		else if (cpl._imag < 0.0) {
			os << '-';
			if (cpl._imag != -1.0)
				os << -cpl._imag;
			os << 'i';
		}
		return os;
	}

	std::istream& operator >>(std::istream& is, complex& cpl)
	{
		string cpl_str, partial;
		is >> cpl_str;
		size_t length(cpl_str.length()), i(0U);
		double sign(POSITIVE);
		if (cpl_str.at(i) == '+' || cpl_str.at(i) == '-') {
			if (cpl_str.at(i) == '-')
				sign = NEGATIVE;
			i++;
		}
		for (; true; i++) {
			if (i > length) {
				throw IMPOSSIBLE;
			}
			if (i == length) {
				if (!partial.empty())
					cpl._real = sign * atof(partial.c_str());
				else
					cpl._real = 0.0;
				return is;
			}
			if (cpl_str.at(i) == 'i') {
				if (!partial.empty())
					cpl._imag = sign * atof(partial.c_str());
				else
					cpl._imag = sign * 1.0;
				i++;
				break;
			}
			if ('0' <= cpl_str.at(i) && cpl_str.at(i) <= '9' || cpl_str.at(i) == '.') {
				partial.append(1, cpl_str.at(i));
			}
			else {
				if (!partial.empty())
					cpl._real = sign * atof(partial.c_str());
				else
					cpl._real = 0.0;
				break;
			}
		}
		partial.clear();
		if (i >= length) {
			return is;
		}
		if (cpl_str.at(i) == '+') {
			sign = POSITIVE;
			i++;
		}
		else if (cpl_str.at(i) == '-') {
			sign = NEGATIVE;
			i++;
		}
		for (; true; i++) {
			if (i > length) {
				throw IMPOSSIBLE;
			}
			if (i == length) {
				if (!partial.empty())
					cpl._real += sign * atof(partial.c_str());
				else
					cpl._real += 0.0;
				break;
			}
			if (cpl_str.at(i) == 'i') {
				if (!partial.empty())
					cpl._imag += sign * atof(partial.c_str());
				else
					cpl._imag += sign * 1.0;
				break;
			}
			if ('0' <= cpl_str.at(i) && cpl_str.at(i) <= '9' || cpl_str.at(i) == '.') {
				partial.append(1, cpl_str.at(i));
			}
			else {
				if (!partial.empty())
					cpl._real += sign * atof(partial.c_str());
				else
					cpl._real += 0.0;
				break;
			}
		}
		return is;
	}

	complex operator ~(agm_cpl cpl)
	{
		return complex(cpl._real, -cpl._imag);
	}

	complex operator +(agm_cpl cpl)
	{
		return cpl;
	}

	complex operator -(agm_cpl cpl)
	{
		return complex(-cpl._real, -cpl._imag);
	}

	complex operator +(agm_cpl cpl1, agm_cpl cpl2)
	{
		return complex(cpl1._real + cpl2._real, cpl1._imag + cpl2._imag);
	}

	complex operator +(agm_cpl cpl, agm real)
	{
		return complex(cpl._real + real, cpl._imag);
	}

	complex operator +(agm real, agm_cpl cpl)
	{
		return complex(real + cpl._real, cpl._imag);
	}

}