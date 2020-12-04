#include "number.h"
#include "pch.h"
#include "framework.h"
#include "number.h"
#include <iostream>
using namespace std;

inline ostream& operator<<(ostream& os, const real& origin)
{
	if (origin.known) {
		os << origin.to_double();
	}
	else {
		os << "unknow";
	}
	return os;
}

inline istream& operator>>(istream& is, real& origin)
{
	origin.known = true;
	is >> origin._numerator;
	origin._denominator = 1;
	return is;
}

inline real operator~(const real& origin)
{
	real temp(origin);
	temp.reciprocal();
	return temp;
}

inline real operator&(const real& real_1, const real& real_2)
{
	return real(real_1._numerator + real_2._numerator, real_1._denominator + real_2._denominator);
}

inline real operator|(const real& real_1, const real& real_2)
{
	return real(real_1._numerator - real_2._numerator, real_1._denominator - real_2._denominator);
}

inline real& real::operator+=(double num)
{
	this->add(num);
	return *this;
}

inline real& real::operator+=(const real& origin)
{
	this->add(origin);
	return *this;
}

inline real& real::operator-=(double num)
{
	this->subtract(num);
	return *this;
}

inline real& real::operator-=(const real& origin)
{
	this->subtract(origin);
	return *this;
}

inline real& real::operator*=(double num)
{
	this->multiply(num);
	return *this;
}

inline real& real::operator*=(const real& origin)
{
	this->multiply(origin);
	return *this;
}

inline real& real::operator/=(double num)
{
	this->subtract(num);
	return *this;
}

inline real& real::operator/=(const real& origin)
{
	this->subtract(origin);
	return *this;
}

inline real real::operator++()
{
	real temp(*this);
	this->add(1);
	return temp;
}

inline real real::operator++(int)
{
	this->add(1);
	return *this;
}

inline real operator+(const real& origin, double num)
{
	real temp(origin);
	temp.add(num);
	return temp;
}

inline real operator+(double num, const real& origin)
{
	real temp(origin);
	temp.add(num);
	return temp;
}

inline real operator+(const real& real_1, const real& real_2)
{
	real temp(real_1);
	temp.add(real_2);
	return temp;
}

inline real operator-(const real& origin, double num)
{
	real temp(origin);
	temp.subtract(num);
	return temp;
}

inline real operator-(double num, const real& origin)
{
	real temp(origin);
	temp.subtract(num);
	return temp;
}

inline real operator-(const real& real_1, const real& real_2)
{
	real temp(real_1);
	temp.subtract(real_2);
	return temp;
}

inline real operator-(const real& origin)
{
	real temp(origin);
	temp._numerator = -temp._numerator;
	return temp;
}

inline real operator*(const real& origin, double num)
{
	real temp(origin);
	temp.multiply(num);
	return temp;
}

inline real operator*(double num, const real& origin)
{
	real temp(origin);
	temp.multiply(num);
	return temp;
}

inline real operator*(const real& real_1, const real& real_2)
{
	real temp(real_1);
	temp.multiply(real_2);
	return temp;
}

inline real operator/(const real& origin, double num)
{
	real temp(origin);
	temp.divide(num);
	return temp;
}

inline real operator/(double num, const real& origin)
{
	real temp(origin);
	temp.divide(num);
	return temp;
}

inline real operator/(const real& real_1, const real& real_2)
{
	real temp(real_1);
	temp.divide(real_2);
	return temp;
}

inline bool operator==(const real& origin, double num)
{
	return (::fabs(origin._numerator - num * origin._denominator)
		< ZERO * origin._denominator);
}

inline bool operator==(double num, const real& origin)
{
	return (::fabs(num * origin._denominator - origin._numerator)
		< ZERO * origin._denominator);
}

inline bool operator==(const real& real_1, const real& real_2)
{
	return (::fabs(real_1._numerator * real_2._denominator - real_1._denominator * real_2._numerator)
		< ZERO * real_1._denominator * real_2._denominator);
}

inline bool operator!=(const real& origin, double num)
{
	return (::fabs(origin._numerator - num * origin._denominator)
		> ZERO * origin._denominator);
}

inline bool operator!=(double num, const real& origin)
{
	return (::fabs(num * origin._denominator - origin._numerator)
		> ZERO * origin._denominator);
}

inline bool operator!=(const real& real_1, const real& real_2)
{
	return (::fabs(real_1._numerator * real_2._denominator - real_1._denominator * real_2._numerator)
		> ZERO * real_1._denominator * real_2._denominator);
}

inline bool operator<(const real& num_1, double num_2)
{
	return num_1.less_than(num_2);
}

inline bool operator<(double num_1, const real& num_2)
{
	return num_2.larger_than(num_1);
}

inline bool operator<(const real& num_1, const real& num_2)
{
	return num_1.less_than(num_2);
}

inline bool operator<=(const real& num_1, double num_2)
{
	return num_1.not_larger_than(num_2);
}

inline bool operator<=(double num_1, const real& num_2)
{
	return num_2.not_less_than(num_1);
}

inline bool operator<=(const real& num_1, const real& num_2)
{
	return num_1.not_larger_than(num_2);
}

inline bool operator>(const real& num_1, double num_2)
{
	return num_1.larger_than(num_2);
}

inline bool operator>(double num_1, const real& num_2)
{
	return num_2.less_than(num_1);
}

inline bool operator>(const real& num_1, const real& num_2)
{
	return num_1.larger_than(num_2);
}

inline bool operator>=(const real& num_1, double num_2)
{
	return num_1.not_less_than(num_2);
}

inline bool operator>=(double num_1, const real& num_2)
{
	return num_2.not_larger_than(num_1);
}

inline bool operator>=(const real& num_1, const real& num_2)
{
	return num_1.not_less_than(num_2);
}