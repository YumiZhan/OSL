#include "pch.h"
#include "number.h"
#include <gsl/gsl_complex_math.h>
#include <string>
using std::cout;

inline osl::complex::complex() :
	_real(0), _imag(0), known(false)
{}

inline osl::complex::complex(agm_cpl cpl) :
	_real(cpl._real), _imag(cpl._imag), known(cpl.known)
{}

inline osl::complex::complex(agm real) :
	_real(real), _imag(0), known(true)
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