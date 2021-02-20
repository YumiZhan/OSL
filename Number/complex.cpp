/* OSL/Number/complex.cpp
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
#include <gsl/gsl_complex_math.h>
#include <cstdlib>
#include <string>
using std::cout;
using std::string;

#define POSITIVE 1.0
#define NEGATIVE -1.0

inline osl::complex::complex() :
	_real(0.0), _imag(0.0), known(false)
{}

inline osl::complex::complex(agm_cpl cpl) :
	_real(cpl._real), _imag(cpl._imag), known(cpl.known)
{}

inline osl::complex::complex(agm real) :
	_real(real), _imag(0.0), known(true)
{}

inline osl::complex::complex(agm a, agm b, int mod) :
	known(true)
{
	switch (mod) {
	case CPL_RECT:
		_real = a; _imag = b;
		break;
	case CPL_POLA:
		gsl_complex gsl_cpl(gsl_complex_polar(a, b));
		_real = GSL_REAL(gsl_cpl); _imag = GSL_IMAG(gsl_cpl);
		break;
	default:
		_real = a; _imag = b;
	}
}

osl::complex::complex(c_str str) :
	_real(0.0), _imag(0.0), known(true)
{
	string cpl_str(str), partial;
	size_t length(cpl_str.length()), i(0U);
	double sign(POSITIVE);
	if (cpl_str.at(i) == '+' || cpl_str.at(i) == '-') {
		if (cpl_str.at(i) == '-')
			sign = NEGATIVE;
		i++;
	}
	for (; true; i++) {
		if (i == length) {
			if (!partial.empty())
				_real += sign * atof(partial.c_str());
			return;
		}
		if (cpl_str.at(i) == 'i') {
			if (!partial.empty())
				_imag += sign * atof(partial.c_str());
			else
				_imag += sign * 1.0;
			i++;
			break;
		}
		if ('0' <= cpl_str.at(i) && cpl_str.at(i) <= '9' || cpl_str.at(i) == '.') {
			partial.append(1, cpl_str.at(i));
		}
		else {
			if (!partial.empty())
				_real += sign * atof(partial.c_str());
			break;
		}
	}
	partial.clear();
	if (i >= length) {
		return;
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
		if (i == length) {
			if (!partial.empty())
				_real += sign * atof(partial.c_str());
			break;
		}
		if (cpl_str.at(i) == 'i') {
			if (!partial.empty())
				_imag += sign * atof(partial.c_str());
			else
				_imag += sign * 1.0;
			break;
		}
		if ('0' <= cpl_str.at(i) && cpl_str.at(i) <= '9' || cpl_str.at(i) == '.') {
			partial.append(1, cpl_str.at(i));
		}
		else {
			if (!partial.empty())
				_real += sign * atof(partial.c_str());
			break;
		}
	}
	return;
}

inline void osl::complex::console_print_rect(c_str end) const
{
	cout << *this << end;
}

inline void osl::complex::console_print_polar(c_str end) const
{
	gsl_complex gsl_cpl(gsl_complex_rect(_real, _imag));
	double r(gsl_complex_abs(gsl_cpl)), theta(gsl_complex_arg(gsl_cpl));
	if (theta >= 0) {
		cout << r << "e^(i" << theta << ')' << end;
	}
	else {
		cout << r << "e^(-i" << -theta << ')' << end;
	}
}

inline double osl::complex::real() const
{
	return _real;
}

inline double osl::complex::imag() const
{
	return _imag;
}

inline double osl::complex::abs() const
{
	return gsl_complex_abs(gsl_complex_rect(_real, _imag));
}

inline double osl::complex::abs2() const
{
	return gsl_complex_abs2(gsl_complex_rect(_real, _imag));
}

inline double osl::complex::agl() const
{
	return gsl_complex_arg(gsl_complex_rect(_real, _imag));
}

inline double osl::complex::logabs() const
{
	return gsl_complex_logabs(gsl_complex_rect(_real, _imag));
}

inline osl::complex osl::complex::conjugated() const
{
	return complex(_real, -_imag);
}

inline osl::complex osl::complex::inversed() const
{
	gsl_complex gsl_cpl(gsl_complex_inverse(gsl_complex_rect(_real, _imag)));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

inline osl::complex osl::complex::negative() const
{
	gsl_complex gsl_cpl(gsl_complex_negative(gsl_complex_rect(_real, _imag)));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

namespace osl {
	inline complex sqrt(agm real)
	{
		gsl_complex gsl_cpl(gsl_complex_sqrt_real(real));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex sqrt(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_sqrt(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}
}