#pragma once
#ifdef NUMBER_EXPORTS
#define NUMBER_API __declspec(dllexport)
#else
#define NUMBER_API __declspec(dllimport)
#pragma	comment(lib, "number")
#endif // _NUMBER_EXPORTS

#include <iostream>

extern NUMBER_API double PI;
extern NUMBER_API double ZERO;

class NUMBER_API real {
public:
	bool known;

	// real.cpp
	inline real();
	inline real(const real& origin);
	inline real(double num);
	inline real(double numerator, double denominator);
	inline real(const char* c_str);
	inline real(const wchar_t* w_str);

	inline bool zero(double reference = 1)const;
	inline bool zero(const real& real)const;
	inline bool infinite(double reference = 1)const;
	inline bool infinite(const real& real)const;

	inline double denominator()const;
	inline double numerator()const;
	inline void print()const;
	friend NUMBER_API inline void print(const real& num);
	inline real to_radian()const;
	inline real to_degree()const;

	// object_operation.cpp
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

	// comparation.cpp
	inline bool larger_than(double num)const;
	inline bool larger_than(const real& num)const;
	inline bool not_less_than(double num)const;
	inline bool not_less_than(const real& num)const;
	inline bool less_than(double num)const;
	inline bool less_than(const real& num)const;
	inline bool not_larger_than(double num)const;
	inline bool not_larger_than(const real& num)const;
	inline bool equal_to(double num, double precision = ZERO)const;
	inline bool equal_to(const real& num, const real& precision = ZERO)const;

	// operator.cpp
	inline operator double()const;

	friend NUMBER_API inline std::ostream& operator<<(std::ostream& os, const real& output_real);
	friend NUMBER_API inline std::istream& operator>>(std::istream& is, real& input_real);

	friend NUMBER_API inline real operator~(const real& origin);
	friend NUMBER_API inline real operator&(const real& real_1, const real& real_2);
	friend NUMBER_API inline real operator|(const real& real_1, const real& real_2);

	inline real& operator+=(double num);
	inline real& operator+=(const real& num);

	inline real& operator-=(double num);
	inline real& operator-=(const real& num);

	inline real& operator*=(double num);
	inline real& operator*=(const real& num);

	inline real& operator/=(double num);
	inline real& operator/=(const real& num);

	inline real& operator++();
	inline real operator++(int);
	inline real& operator--();
	inline real operator--(int);

	friend NUMBER_API inline real operator+(const real& num_1, double num_2);
	friend NUMBER_API inline real operator+(double num_1, const real& num_2);
	friend NUMBER_API inline real operator+(const real& num_1, const real& num_2);

	friend NUMBER_API inline real operator-(const real& num_1, double num_2);
	friend NUMBER_API inline real operator-(double num_1, const real& num_2);
	friend NUMBER_API inline real operator-(const real& num_1, const real& num_2);

	friend NUMBER_API inline real operator-(const real& num);

	friend NUMBER_API inline real operator*(const real& num_1, double num_2);
	friend NUMBER_API inline real operator*(double num_1, const real& num_2);
	friend NUMBER_API inline real operator*(const real& num_1, const real& num_2);

	friend NUMBER_API inline real operator/(const real& num_1, double num_2);
	friend NUMBER_API inline real operator/(double num_1, const real& num_2);
	friend NUMBER_API inline real operator/(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator==(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator==(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator==(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator!=(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator!=(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator!=(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator<(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator<(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator<(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator<=(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator<=(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator<=(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator>(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator>(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator>(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator>=(const real& num_1, double num_2);
	friend NUMBER_API inline bool operator>=(double num_1, const real& num_2);
	friend NUMBER_API inline bool operator>=(const real& num_1, const real& num_2);

	friend NUMBER_API inline bool operator!(const real& num);

	// rcmath.cpp
	friend NUMBER_API inline double cos(const real& num);
	friend NUMBER_API inline double cosh(const real& num);
	friend NUMBER_API inline double sin(const real& num);
	friend NUMBER_API inline double sinh(const real& num);
	friend NUMBER_API inline double tan(const real& num);
	friend NUMBER_API inline double tanh(const real& num);

	friend NUMBER_API inline double acos(const real& num);
	friend NUMBER_API inline double acosh(const real& num);
	friend NUMBER_API inline double asin(const real& num);
	friend NUMBER_API inline double asinh(const real& num);
	friend NUMBER_API inline double atan(const real& num);
	friend NUMBER_API inline double atan2(const real& num_1, double num_2);
	friend NUMBER_API inline double atan2(double num_1, const real& num_2);
	friend NUMBER_API inline double atan2(const real& num_1, const real& num_2);
	friend NUMBER_API inline double atanh(const real& num);
	
	friend NUMBER_API inline double exp(const real& num);
	friend NUMBER_API inline double exp2(const real& num);
	friend NUMBER_API inline double expm1(const real& num);

	friend NUMBER_API inline double frexp(const real& num, double* exponent);
	friend NUMBER_API inline double frexp(double num, real& exponent);
	friend NUMBER_API inline double frexp(const real& num, real& exponent);

	friend NUMBER_API inline double ldexp(const real& num, int exponent);

	friend NUMBER_API inline double log(const real& num, double base);
	friend NUMBER_API inline double log(double num, const real& base);
	friend NUMBER_API inline double log(const real& num, const real& base);
	friend NUMBER_API inline double log(const real& num);
	friend NUMBER_API inline double ln(const real& num);
	friend NUMBER_API inline double log2(const real& num);
	friend NUMBER_API inline double log10(const real& num);
	friend NUMBER_API inline double lg(const real& num);
	friend NUMBER_API inline double log1p(const real& num);

	friend NUMBER_API inline double copysign(const real& num_1, const real& num_2);
	friend NUMBER_API inline double modf(const real& num, int* integer);

	friend NUMBER_API inline double pow(const real& num, double exponent);
	friend NUMBER_API inline double pow(double num, const real& exponent);
	friend NUMBER_API inline double pow(const real& num, const real& exponent);
	friend NUMBER_API inline double pow2(const real& num);
	friend NUMBER_API inline double pow10(const real& num);
	friend NUMBER_API inline double sqrt(const real& num);
	friend NUMBER_API inline double hypot(const real& x, const real& y);
	friend NUMBER_API inline double poly(const real& x, int n, double* c);

	friend NUMBER_API inline double ceil(const real& num);
	friend NUMBER_API inline double round(const real& num);
	friend NUMBER_API inline double floor(const real& num);
	friend NUMBER_API inline double trunc(const real& num);
	friend NUMBER_API inline double fabs(const real& num);

	friend NUMBER_API inline double fmod(const real& num_1, double num_2);
	friend NUMBER_API inline double fmod(double num_1, const real& num_2);
	friend NUMBER_API inline double fmod(const real& num_1, const real& num_2);

private:
	double _denominator, _numerator;
};

template <class num = real>
class NUMBER_API complex {
public:
	bool known;
	inline complex();
	inline complex(const num& real);
	inline complex(const num& real, const num& imag);

	inline num real();
	inline num imag();
private:
	num _real, _imag;
};