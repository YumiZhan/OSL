#pragma once
#include "..\pch.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef ZERO
#define ZERO 1E-10
#endif // !ZERO

class real
{
public:
	bool known;
	string name;

	//real.cpp
	inline real();
	inline real(const real& origin, string name = "");
	inline real(double num, string name = "");
	inline real(double numerator, double denominator, string name = "");

	friend inline real abs(const real& origin);
	inline double fabs()const;
	inline double to_double()const;
	inline bool zero(double num = 1)const;
	inline bool zero(const real& real)const;
	inline bool infinite(double num = 1)const;
	inline bool infinite(const real& real)const;
	inline double denominator()const;
	inline double numerator()const;
	inline void print()const;

	//object_operation.cpp
	inline void reciprocal();
	inline void rabs();
	inline void add(double num);
	inline void add(const real& real);
	inline void subtract(double num);
	inline void subtract(const real& real);
	inline void multiply(double num);
	inline void multiply(const real& real);
	inline void divide(double num);
	inline void divide(const real& real);

	//operator.cpp
	friend inline ostream& operator<<(ostream& os, const real& output_real);
	friend inline istream& operator>>(istream& is, real& input_real);

	friend inline real operator~(const real& origin);
	friend inline real operator&(const real& real_1, const real& real_2);
	friend inline real operator|(const real& real_1, const real& real_2);

	inline real& operator+=(double num);
	inline real& operator+=(const real& origin);

	inline real& operator-=(double num);
	inline real& operator-=(const real& origin);

	inline real& operator*=(double num);
	inline real& operator*=(const real& origin);

	inline real& operator/=(double num);
	inline real& operator/=(const real& origin);

	friend inline real operator+(const real& real, double num);
	friend inline real operator+(double num, const real& real);
	friend inline real operator+(const real& real_1, const real& real_2);

	friend real operator-(const real& real, double num);
	friend real operator-(const real& real_1, const real& real_2);
	friend real operator-(double num, const real& real);

	friend real operator-(const real& origin);

	friend real operator*(const real& real_1, double num);
	friend real operator*(const real& real_1, const real& real_2);
	friend real operator*(double num, const real& real);

	friend real operator/(const real& real, double num);
	friend real operator/(const real& real_1, const real& real_2);
	friend real operator/(double num, const real& real);

	friend bool operator==(const real& real, double num);
	friend bool operator==(double num, const real& real);
	friend bool operator==(const real& real_1, const real& real_2);

	friend bool operator!=(const real& real, double num);
	friend bool operator!=(double num, const real& real);
	friend bool operator!=(const real& real_1, const real& real_2);

	friend bool operator<(const real& real, double num);
	friend bool operator<(double num, const real& real);
	friend bool operator<(const real& real_1, const real& real_2);

	friend bool operator<=(const real& real, double num);
	friend bool operator<=(double num, const real& real);
	friend bool operator<=(const real& real_1, const real& real_2);

	friend bool operator>(const real& real, double num);
	friend bool operator>(double num, const real& real);
	friend bool operator>(const real& real_1, const real& real_2);

	friend bool operator>=(const real& real, double num);
	friend bool operator>=(double num, const real& real);
	friend bool operator>=(const real& real_1, const real& real_2);

private:
	bool finite;
	double _denominator, _numerator;
};

inline double fabs(const real& num)
{
	return num.fabs();
}