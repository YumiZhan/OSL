#include "number.h"
#include <gsl/gsl_complex_math.h>

inline void osl::complex::add(const complex& cpl)
{
	_real += cpl._real; _imag += cpl._imag;
}

inline void osl::complex::subtract(const complex& cpl)
{
	_real -= cpl._real; _imag -= cpl._imag;
}

inline void osl::complex::multiply(const complex& cpl)
{
	_real = _real * cpl._real - _imag * cpl._imag;
	_imag = _real * cpl._imag + _imag * cpl._real;
}

inline void osl::complex::divide(const complex& cpl)
{
	gsl_complex gsl_cpl(gsl_complex_rect(_real, _imag));
	gsl_cpl = gsl_complex_div(gsl_cpl, gsl_complex_rect(cpl._real, cpl._imag));
	_real = GSL_REAL(gsl_cpl); _imag = GSL_IMAG(gsl_cpl);
}
