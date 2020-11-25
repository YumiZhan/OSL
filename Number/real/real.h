#pragma once
#include "..\pch.h"
#include <iostream>
using namespace std;

#ifndef ZERO
#define ZERO 1E-10
#endif // !ZERO

#define PI 3.141592653589793

class real
{
public:
	bool known;

	//real.cpp
	inline real();
	inline real(const real& origin);
	inline real(double num);
	inline real(double numerator, double denominator);

	friend inline real abs(const real& origin);
	inline real abs()const;
	inline double fabs()const;
	inline double to_double()const;
	inline bool zero(double reference = 1)const;
	inline bool zero(const real& real)const;
	inline bool infinite(double reference = 1)const;
	inline bool infinite(const real& real)const;
	inline double denominator()const;
	inline double numerator()const;
	inline void print(double reference = 1)const;

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

	friend inline real operator+(const real& origin, double num);
	friend inline real operator+(double num, const real& origin);
	friend inline real operator+(const real& origin_1, const real& origin_2);

	friend inline real operator-(const real& origin, double num);
	friend inline real operator-(double num, const real& origin);
	friend inline real operator-(const real& real_1, const real& real_2);

	friend inline real operator-(const real& origin);

	friend inline real operator*(const real& origin, double num);
	friend inline real operator*(double num, const real& origin);
	friend inline real operator*(const real& real_1, const real& real_2);

	friend inline real operator/(const real& origin, double num);
	friend inline real operator/(double num, const real& origin);
	friend inline real operator/(const real& real_1, const real& real_2);

	friend inline bool operator==(const real& num_1, double num_2);
	friend inline bool operator==(double num_1, const real& num_2);
	friend inline bool operator==(const real& num_1, const real& num_2);

	friend inline bool operator!=(const real& num_1, double num_2);
	friend inline bool operator!=(double num_1, const real& num_2);
	friend inline bool operator!=(const real& num_1, const real& num_2);

	friend inline bool operator<(const real& num_1, double num_2);
	friend inline bool operator<(double num_1, const real& num_2);
	friend inline bool operator<(const real& num_1, const real& num_2);

	friend inline bool operator<=(const real& num_1, double num_2) { return num_1 < num_2; }
	friend inline bool operator<=(double num_1, const real& num_2) { return num_1 < num_2; }
	friend inline bool operator<=(const real& num_1, const real& num_2) { return num_1 < num_2; }

	friend inline bool operator>(const real& num_1, double num_2);
	friend inline bool operator>(double num_1, const real& num_2);
	friend inline bool operator>(const real& num_1, const real& num_2);

	friend inline bool operator>=(const real& origin, double num) { return origin > num; }
	friend inline bool operator>=(double num, const real& origin) { return num > origin; }
	friend inline bool operator>=(const real& real_1, const real& real_2) { return real_1 > real_2; }

	//rcmath.cpp
	friend inline double acos(const real& num);
	friend inline double asin(const real& num);
	friend inline double atan(const real& num);

	friend inline double atan2(const real& num_1, double num_2);
	friend inline double atan2(double num_1, const real& num_2);
	friend inline double atan2(const real& num_1, const real& num_2);

	friend inline double cos(const real& num);
	friend inline double cosh(const real& num);
	friend inline double sin(const real& num);
	friend inline double sinh(const real& num);
	friend inline double tan(const real& num);
	friend inline double tanh(const real& num);
	friend inline double exp(const real& num);

	friend inline double frexp(const real& num, double* exponent);
	friend inline double frexp(double num, real& exponent);
	friend inline double frexp(const real& num, real& exponent);

	friend inline double ldexp(const real& num, int exponent);

	friend inline double log(const real& num, double base);
	friend inline double log(double num, const real& base);
	friend inline double log(const real& num, const real& base);
	friend inline double ln(const real& num);
	friend inline double log2(const real& num);
	friend inline double log10(const real& num);

	friend inline double modf(const real& num, int* integer);

	friend inline double pow(const real& num, double exponent);
	friend inline double pow(double num, const real& exponent);
	friend inline double pow(const real& num, const real& exponent);
	friend inline double pow2(const real& num);
	friend inline double sqrt(const real& num);

	friend inline double ceil(const real& num);
	friend inline double floor(const real& num);
	friend inline double fabs(const real& num);

	friend inline double fmod(const real& num_1, double num_2);
	friend inline double fmod(double num_1, const real& num_2);
	friend inline double fmod(const real& num_1, const real& num_2);

private:
	double _denominator, _numerator;
};