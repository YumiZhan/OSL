/* OSL/Number/complex_modifier.cpp
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

inline void osl::complex::add(agm_cpl cpl)
{
	_real += cpl._real; _imag += cpl._imag;
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::add(agm real, agm imag)
{
	_real += real; _imag += imag;
}

inline void osl::complex::sub(agm_cpl cpl)
{
	_real -= cpl._real; _imag -= cpl._imag;
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::sub(agm real, agm imag)
{
	_real -= real; _imag -= imag;
}

inline void osl::complex::mul(agm_cpl cpl)
{
	_real = _real * cpl._real - _imag * cpl._imag;
	_imag = _real * cpl._imag + _imag * cpl._real;
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::mul(agm real, agm imag)
{
	_real = _real * real - _imag * imag;
	_imag = _real * imag + _imag * real;
}

inline void osl::complex::div(agm_cpl cpl)
{
	gsl_complex gsl_cpl(gsl_complex_div(gsl_complex_rect(_real, _imag), gsl_complex_rect(cpl._real, cpl._imag)));
	_real = GSL_REAL(gsl_cpl); _imag = GSL_IMAG(gsl_cpl);
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::div(agm real, agm imag)
{
	gsl_complex gsl_cpl(gsl_complex_div(gsl_complex_rect(_real, _imag), gsl_complex_rect(real, imag)));
	_real = GSL_REAL(gsl_cpl); _imag = GSL_IMAG(gsl_cpl);
}

inline void osl::complex::exc()
{
	double temp(_real);
	_real = _imag;
	_imag = temp;
}

inline void osl::complex::absc()
{
	_real = fabs(_real);
	_imag = fabs(_imag);
}