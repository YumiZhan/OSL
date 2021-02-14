#include "pch.h"
#include "number.h"
#include <gsl/gsl_complex_math.h>

inline osl::complex::complex() :
	_real(0), _imag(0), known(false)
{}

inline osl::complex::complex(const complex& cpl) :
	_real(cpl._real), _imag(cpl._imag), known(cpl.known)
{}

inline osl::complex::complex(double real) :
	_real(real), _imag(0), known(true)
{}

inline osl::complex::complex(double a, double b, int mod) :
	known(true)
{
	switch (mod) {
	case cpl_RECT:
		_real = a; _imag = b;
		break;
	case cpl_POLA:
		gsl_complex gsl_cpl(gsl_complex_polar(a, b));
		_real = GSL_REAL(gsl_cpl); _imag = GSL_IMAG(gsl_cpl);
		break;
	default:
		_real = a; _imag = b;
	}
}

inline double osl::complex::real()
{
	return _real;
}

inline double osl::complex::imag()
{
	return _imag;
}