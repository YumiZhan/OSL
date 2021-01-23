#include "number.h"
#include "pch.h"
#include "framework.h"
#include "number.h"
#include <iostream>
using namespace std;

inline ostream& operator<<(ostream& os, const real& num)
{
	if (num.known) {
		os << num.todouble();
	}
	else {
		os << "unknow";
	}
	return os;
}

inline istream& operator>>(istream& is, real& num)
{
	num.known = true;
	is >> num._numerator;
	num._denominator = 1;
	return is;
}

inline real operator~(const real& num)
{
	real temp(num);
	temp.reciprocal();
	return temp;
}

inline real operator&(const real& num_1, const real& num_2)
{
	return real(num_1._numerator + num_2._numerator, num_1._denominator + num_2._denominator);
}

inline real operator|(const real& num_1, const real& num_2)
{
	return real(num_1._numerator - num_2._numerator, num_1._denominator - num_2._denominator);
}

inline real& real::operator+=(double num)
{
	this->add(num);
	return *this;
}

inline real& real::operator+=(const real& num)
{
	this->add(num);
	return *this;
}

inline real& real::operator-=(double num)
{
	this->subtract(num);
	return *this;
}

inline real& real::operator-=(const real& num)
{
	this->subtract(num);
	return *this;
}

inline real& real::operator*=(double num)
{
	this->multiply(num);
	return *this;
}

inline real& real::operator*=(const real& num)
{
	this->multiply(num);
	return *this;
}

inline real& real::operator/=(double num)
{
	this->subtract(num);
	return *this;
}

inline real& real::operator/=(const real& num)
{
	this->subtract(num);
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

inline real operator+(const real& num_1, double num_2)
{
	real temp(num_1);
	temp.add(num_2);
	return temp;
}

inline real operator+(double num_1, const real& num_2)
{
	real temp(num_1);
	temp.add(num_2);
	return temp;
}

inline real operator+(const real& num_1, const real& num_2)
{
	real temp(num_1);
	temp.add(num_2);
	return temp;
}

inline real operator-(const real& num_1, double num_2)
{
	real temp(num_1);
	temp.subtract(num_2);
	return temp;
}

inline real operator-(double num_1, const real& num_2)
{
	real temp(num_1);
	temp.subtract(num_2);
	return temp;
}

inline real operator-(const real& num_1, const real& num_2)
{
	real temp(num_1);
	temp.subtract(num_2);
	return temp;
}

inline real operator-(const real& num)
{
	real temp(num);
	temp._numerator = -temp._numerator;
	return temp;
}

inline real operator*(const real& num_1, double num_2)
{
	real temp(num_1);
	temp.multiply(num_2);
	return temp;
}

inline real operator*(double num_1, const real& num_2)
{
	real temp(num_1);
	temp.multiply(num_2);
	return temp;
}

inline real operator*(const real& num_1, const real& num_2)
{
	real temp(num_1);
	temp.multiply(num_2);
	return temp;
}

inline real operator/(const real& num_1, double num_2)
{
	real temp(num_1);
	temp.divide(num_2);
	return temp;
}

inline real operator/(double num_1, const real& num_2)
{
	real temp(num_1);
	temp.divide(num_2);
	return temp;
}

inline real operator/(const real& num_1, const real& num_2)
{
	real temp(num_1);
	temp.divide(num_2);
	return temp;
}

inline bool operator==(const real& num_1, double num_2)
{
	return num_1.equal_to(num_2);
}

inline bool operator==(double num_1, const real& num_2)
{
	return num_2.equal_to(num_1);
}

inline bool operator==(const real& num_1, const real& num_2)
{
	return num_1.equal_to(num_2);
}

inline bool operator!=(const real& num_1, double num_2)
{
	return !num_1.equal_to(num_2);
}

inline bool operator!=(double num_1, const real& num_2)
{
	return !num_2.equal_to(num_1);
}

inline bool operator!=(const real& num_1, const real& num_2)
{
	return !num_1.equal_to(num_2);
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

inline bool operator!(const real& num)
{
	return !num.known;
}