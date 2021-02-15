#include "pch.h"
#include "number.h"
using std::cout;

namespace osl {
	inline real::real() :
		_denominator(1), _numerator(0), known(false)
	{}

	inline real::real(const real& origin) :
		_denominator(origin._denominator), _numerator(origin._numerator), known(origin.known)
	{}

	inline real::real(argument num) :
		_denominator(1), _numerator(num), known(true)
	{
		simplify_fraction(_denominator, _numerator);
	}

	inline real::real(argument numerator, argument denominator) :
		_denominator(denominator), _numerator(numerator), known(true)
	{
		simplify_fraction(_denominator, _numerator);
	}

	inline real::real(const char* c_str) :
		_denominator(1), _numerator(atof(c_str)), known(true)
	{
		simplify_fraction(_denominator, _numerator);
	}

	inline real::real(const wchar_t* w_str) :
		_denominator(1), _numerator(_wtof(w_str)), known(true)
	{
		simplify_fraction(_denominator, _numerator);
	}

	inline bool real::zero(argument reference) const
	{
		if (::fabs(_numerator) < ::fabs(_denominator * reference * ZERO)) {
			return true;
		}
		return false;
	}

	inline bool real::zero(const real& reference) const
	{
		if (::fabs(_numerator * reference._denominator)
			< ::fabs(_denominator * reference._numerator * ZERO)) {
			return true;
		}
		return false;
	}

	inline bool real::infinite(argument reference) const
	{
		if (::fabs(_numerator * ZERO) > ::fabs(_denominator * reference)) {
			return true;
		}
		return false;
	}

	inline bool real::infinite(const real& reference) const
	{
		if (::fabs(_numerator * reference._denominator * ZERO)
		> ::fabs(_denominator * reference._numerator)) {
			return true;
		}
		return false;
	}

	inline double real::denominator() const
	{
		return _denominator;
	}

	inline double real::numerator() const
	{
		return _numerator;
	}

	inline void real::console_print(c_str end) const
	{
		cout << this->operator double() << end;
	}

	inline void real::console_show(c_str end) const
	{
		cout << _numerator << '/' << _denominator << end;
	}

	inline real real::to_radian() const
	{
		return real(this->_numerator * PI, this->_denominator * 180);
	}

	inline real real::to_degree() const
	{
		return real(this->_numerator * 180, this->_denominator * PI);
	}
}