#include "number.h"
#include "pch.h"
#include <gsl/gsl_complex_math.h>

inline void osl::complex::add(const complex& cpl)
{
	_real += cpl._real; _imag += cpl._imag;
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::add(number real, number imag)
{
	_real += real; _imag += imag;
}

inline void osl::complex::sub(const complex& cpl)
{
	_real -= cpl._real; _imag -= cpl._imag;
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::sub(number real, number imag)
{
	_real -= real; _imag -= imag;
}

inline void osl::complex::mul(const complex& cpl)
{
	_real = _real * cpl._real - _imag * cpl._imag;
	_imag = _real * cpl._imag + _imag * cpl._real;
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::mul(number real, number imag)
{
	_real = _real * real - _imag * imag;
	_imag = _real * imag + _imag * real;
}

inline void osl::complex::div(const complex& cpl)
{
	gsl_complex gsl_cpl(gsl_complex_div(gsl_complex_rect(_real, _imag), gsl_complex_rect(cpl._real, cpl._imag)));
	_real = GSL_REAL(gsl_cpl); _imag = GSL_IMAG(gsl_cpl);
	if (!cpl.known) {
		known = false;
	}
}

inline void osl::complex::div(number real, number imag)
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