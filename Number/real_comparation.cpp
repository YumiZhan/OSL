#include "pch.h"
#include "number.h"

namespace osl {
	inline bool real::larger_than(agm num) const
	{
		return _numerator > _denominator * num;
	}

	inline bool real::larger_than(agm_real num) const
	{
		return _numerator * num._denominator > _denominator * num._denominator;
	}

	inline bool real::not_less_than(agm num) const
	{
		return _numerator >= _denominator * num;
	}

	inline bool real::not_less_than(agm_real num) const
	{
		return _numerator * num._denominator > _denominator * num._denominator;
	}

	inline bool real::less_than(agm num) const
	{
		return _numerator < _denominator* num;
	}

	inline bool real::less_than(agm_real num) const
	{
		return _numerator * num._denominator < _denominator* num._numerator;
	}

	inline bool real::not_larger_than(agm num) const
	{
		return _numerator <= _denominator * num;
	}

	inline bool real::not_larger_than(agm_real num) const
	{
		return _numerator * num._denominator < _denominator* num._numerator;
	}

	inline bool real::equal_to(agm num, agm precision) const
	{
		if (::fabs(this->_numerator - num * this->_denominator) < ::fabs(this->_denominator * precision)) {
			return true;
		}
		return false;
	}

	inline bool real::equal_to(agm_real num, agm_real precision) const
	{
		if (::fabs(this->_numerator * num._denominator - this->_denominator - num._numerator)
			< ::fabs(ZERO * this->_denominator * num._denominator)) {
			return true;
		}
		return false;
	}
}