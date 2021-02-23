#include "pch.h"
#include "number.h"
#include <gsl/gsl_complex_math.h>

inline bool osl::complex::equal_to(agm_cpl cpl, double reference) const
{
	if (reference == 0.0) {
		reference = (fabs(cpl._real) + fabs(_real)) * 0.5;
	}
	if (fabs(cpl._real - _real) < ZERO * reference
		&& fabs(cpl._imag - _imag) < ZERO * reference) {
		return true;
	}
	return false;
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

inline osl::complex osl::complex::pow(agm_cpl cpl) const
{
	gsl_complex gsl_cpl(gsl_complex_pow(gsl_complex_rect(_real, _imag), gsl_complex_rect(cpl._real, cpl._imag)));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

inline osl::complex osl::complex::pow(agm real) const
{
	gsl_complex gsl_cpl(gsl_complex_pow_real(gsl_complex_rect(_real, _imag), real));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

namespace osl {
	inline complex sqrt(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_sqrt(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex sqrt(agm real)
	{
		gsl_complex gsl_cpl(gsl_complex_sqrt_real(real));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex exp(agm_cpl index)
	{
		gsl_complex gsl_cpl(gsl_complex_exp(gsl_complex_rect(index._real, index._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex exp(agm index)
	{
		gsl_complex gsl_cpl(gsl_complex_exp(gsl_complex_rect(index, 0.0)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

}

inline osl::complex osl::complex::log(agm_cpl base) const
{
	gsl_complex gsl_cpl(gsl_complex_log_b(gsl_complex_rect(_real, _imag), gsl_complex_rect(base._real, base._imag)));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

inline osl::complex osl::complex::log(agm base) const
{
	gsl_complex gsl_cpl(gsl_complex_log_b(gsl_complex_rect(_real, _imag), gsl_complex_rect(base, 0.0)));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

inline osl::complex osl::complex::log10() const
{
	gsl_complex gsl_cpl(gsl_complex_log10(gsl_complex_rect(_real, _imag)));
	return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
}

namespace osl {
	inline complex cos(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_cos(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex sin(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_sin(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex tan(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_tan(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex csc(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_csc(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex sec(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_sec(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex cot(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_cot(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex acos(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arccos(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex asin(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arcsin(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex atan(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arctan(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex acsc(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arccsc(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex asec(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arcsec(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex acot(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arccot(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex cosh(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_cosh(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex sinh(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_sinh(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex tanh(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_tanh(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex csch(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_csch(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex sech(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_sech(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex coth(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_coth(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex acosh(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arccosh(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex asinh(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arcsinh(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex atanh(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arctanh(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex acsch(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arccsch(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex asech(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arcsech(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}

	inline complex acoth(agm_cpl cpl)
	{
		gsl_complex gsl_cpl(gsl_complex_arccoth(gsl_complex_rect(cpl._real, cpl._imag)));
		return complex(GSL_REAL(gsl_cpl), GSL_IMAG(gsl_cpl));
	}
}