﻿#ifdef NUMBER_EXPORTS
#define NUMBER_API __declspec(dllexport)
#else
#define NUMBER_API __declspec(dllimport)
#pragma	comment(lib, "number")
#endif // _NUMBER_EXPORTS

#include <iostream>
using namespace std;

#define PI 3.141592653589793
//#define ZERO 1E-10
extern NUMBER_API double ZERO;

class NUMBER_API real {
public:
	bool known;

	//real.cpp
	inline real();
	inline real(const real& origin);
	inline real(double num);
	inline real(double numerator, double denominator);

	friend NUMBER_API inline real abs(const real& origin);
	inline real abs()const;
	inline double fabs()const;
	inline double to_double()const;
	inline bool zero(double reference = 1)const;
	inline bool zero(const real& real)const;
	inline bool infinite(double reference = 1)const;
	inline bool infinite(const real& real)const;
	inline double denominator()const;
	inline double numerator()const;
	inline void print()const;
	friend NUMBER_API inline void print(const real& num);

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
	friend NUMBER_API inline ostream& operator<<(ostream& os, const real& output_real);
	friend NUMBER_API inline istream& operator>>(istream& is, real& input_real);

	friend NUMBER_API inline real operator~(const real& origin);
	friend NUMBER_API inline real operator&(const real& real_1, const real& real_2);
	friend NUMBER_API inline real operator|(const real& real_1, const real& real_2);

	inline real& operator+=(double num);
	inline real& operator+=(const real& origin);

	inline real& operator-=(double num);
	inline real& operator-=(const real& origin);

	inline real& operator*=(double num);
	inline real& operator*=(const real& origin);

	inline real& operator/=(double num);
	inline real& operator/=(const real& origin);

	friend NUMBER_API inline real operator+(const real& origin, double num);
	friend NUMBER_API inline real operator+(double num, const real& origin);
	friend NUMBER_API inline real operator+(const real& origin_1, const real& origin_2);

	friend NUMBER_API inline real operator-(const real& origin, double num);
	friend NUMBER_API inline real operator-(double num, const real& origin);
	friend NUMBER_API inline real operator-(const real& real_1, const real& real_2);

	friend NUMBER_API inline real operator-(const real& origin);

	friend NUMBER_API inline real operator*(const real& origin, double num);
	friend NUMBER_API inline real operator*(double num, const real& origin);
	friend NUMBER_API inline real operator*(const real& real_1, const real& real_2);

	friend NUMBER_API inline real operator/(const real& origin, double num);
	friend NUMBER_API inline real operator/(double num, const real& origin);
	friend NUMBER_API inline real operator/(const real& real_1, const real& real_2);

	friend NUMBER_API inline bool operator==(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator==(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator==(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator!=(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator!=(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator!=(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator<(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator<(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator<(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator<=(const real& num_1, double num_2) { return num_1 < num_2; }
	friend NUMBER_API inline bool operator<=(double num_1, const real& num_2) { return num_1 < num_2; }
	friend NUMBER_API inline bool operator<=(const real& num_1, const real& num_2) { return num_1 < num_2; }

	friend NUMBER_API inline bool operator>(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator>(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator>(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator>=(const real& origin, double num) { return origin > num; }
	friend NUMBER_API inline bool operator>=(double num, const real& origin) { return num > origin; }
	friend NUMBER_API inline bool operator>=(const real& real_1, const real& real_2) { return real_1 > real_2; }

	//rcmath.cpp
	friend NUMBER_API inline double acos(const real& num);
	friend NUMBER_API inline double asin(const real& num);
	friend NUMBER_API inline double atan(const real& num);

	friend NUMBER_API inline double atan2(const real& num_1, double num_2);
	friend NUMBER_API inline double atan2(double num_1, const real& num_2);
	friend NUMBER_API inline double atan2(const real& num_1, const real& num_2);

	friend NUMBER_API inline double cos(const real& num);
	friend NUMBER_API inline double cosh(const real& num);
	friend NUMBER_API inline double sin(const real& num);
	friend NUMBER_API inline double sinh(const real& num);
	friend NUMBER_API inline double tan(const real& num);
	friend NUMBER_API inline double tanh(const real& num);
	friend NUMBER_API inline double exp(const real& num);

	friend NUMBER_API inline double frexp(const real& num, double* exponent);
	friend NUMBER_API inline double frexp(double num, real& exponent);
	friend NUMBER_API inline double frexp(const real& num, real& exponent);

	friend NUMBER_API inline double ldexp(const real& num, int exponent);

	friend NUMBER_API inline double log(const real& num, double base);
	friend NUMBER_API inline double log(double num, const real& base);
	friend NUMBER_API inline double log(const real& num, const real& base);
	friend NUMBER_API inline double ln(const real& num);
	friend NUMBER_API inline double log2(const real& num);
	friend NUMBER_API inline double log10(const real& num);

	friend NUMBER_API inline double modf(const real& num, int* integer);

	friend NUMBER_API inline double pow(const real& num, double exponent);
	friend NUMBER_API inline double pow(double num, const real& exponent);
	friend NUMBER_API inline double pow(const real& num, const real& exponent);
	friend NUMBER_API inline double pow2(const real& num);
	friend NUMBER_API inline double sqrt(const real& num);

	friend NUMBER_API inline double ceil(const real& num);
	friend NUMBER_API inline double floor(const real& num);
	friend NUMBER_API inline double fabs(const real& num);

	friend NUMBER_API inline double fmod(const real& num_1, double num_2);
	friend NUMBER_API inline double fmod(double num_1, const real& num_2);
	friend NUMBER_API inline double fmod(const real& num_1, const real& num_2);

private:
	double _denominator, _numerator;
};

class NUMBER_API complex {
public:
	bool known;
	inline complex();
private:
	real _real, _imag;
};