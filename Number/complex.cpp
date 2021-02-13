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

inline osl::complex::complex(double real, double imag) :
	_real(real), _imag(imag), known(true)
{}

inline osl::complex osl::complex_pola(double r, double theta)
{
	gsl_complex gsl_cpl(gsl_complex_polar(r, theta));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

inline double osl::complex::real()
{
	return _real;
}

inline double osl::complex::imag()
{
	return _imag;
}