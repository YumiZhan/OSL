#include "pch.h"
#include "framework.h"
#include "number.h"

inline bool real::larger_than(double num) const
{
	return _numerator > _denominator * num;
}

inline bool real::larger_than(const real& num) const
{
	return _numerator * num._denominator > _denominator * num._denominator;
}

inline bool real::not_less_than(double num) const
{
	return _numerator >= _denominator * num;
}

inline bool real::not_less_than(const real& num) const
{
	return _numerator * num._denominator > _denominator * num._denominator;
}

inline bool real::less_than(double num) const
{
	return _numerator < _denominator * num;
}

inline bool real::less_than(const real& num) const
{
	return _numerator * num._denominator < _denominator * num._numerator;
}

inline bool real::not_larger_than(double num) const
{
	return _numerator <= _denominator* num;
}

inline bool real::not_larger_than(const real& num) const
{
	return _numerator * num._denominator < _denominator* num._numerator;
}