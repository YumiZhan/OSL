#pragma once
#ifdef NUMBER_EXPORTS
#	define NUMBER_API __declspec(dllexport)
#else
#	define NUMBER_API __declspec(dllimport)
#	pragma	comment(lib, "number")
#endif // _NUMBER_EXPORTS

#include <iostream>
#define cpl_RECT 0
#define cpl_POLA 1

namespace osl {
	extern NUMBER_API double PI; // 3.1415926535897932
	extern NUMBER_API double ZERO; // 1E-10

	NUMBER_API inline void simplify_fraction(double& denominator, double& numerator);

	class NUMBER_API real {
		double _denominator, _numerator;
		// object_operation.cpp
		inline void simplify();

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
		inline void console_print()const;
		inline void console_show()const;
		inline real to_radian()const;
		inline real to_degree()const;

		// real_self_operation.cpp
		inline void rec();
		inline void absr();
		inline void add(double num);
		inline void add(const real& real);
		inline void sub(double num);
		inline void sub(const real& real);
		inline void mul(double num);
		inline void mul(const real& real);
		inline void div(double num);
		inline void div(const real& real);

		// real_comparation.cpp
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

		// real_overload_operator.cpp
		inline operator double()const;

		friend NUMBER_API inline std::ostream& operator <<(std::ostream& os, const real& output_real);
		friend NUMBER_API inline std::istream& operator >>(std::istream& is, real& input_real);

		friend NUMBER_API inline real operator ~(const real& origin);

		inline real& operator +=(double num);
		inline real& operator +=(const real& num);

		inline real& operator -=(double num);
		inline real& operator -=(const real& num);

		inline real& operator *=(double num);
		inline real& operator *=(const real& num);

		inline real& operator /=(double num);
		inline real& operator /=(const real& num);

		inline real& operator ++();
		inline real operator ++(int);
		inline real& operator --();
		inline real operator --(int);

		friend NUMBER_API inline real operator +(const real& num_1, double num_2);
		friend NUMBER_API inline real operator +(double num_1, const real& num_2);
		friend NUMBER_API inline real operator +(const real& num_1, const real& num_2);

		friend NUMBER_API inline real operator -(const real& num_1, double num_2);
		friend NUMBER_API inline real operator -(double num_1, const real& num_2);
		friend NUMBER_API inline real operator -(const real& num_1, const real& num_2);

		friend NUMBER_API inline real operator -(const real& num);

		friend NUMBER_API inline real operator *(const real& num_1, double num_2);
		friend NUMBER_API inline real operator *(double num_1, const real& num_2);
		friend NUMBER_API inline real operator *(const real& num_1, const real& num_2);

		friend NUMBER_API inline real operator /(const real& num_1, double num_2);
		friend NUMBER_API inline real operator /(double num_1, const real& num_2);
		friend NUMBER_API inline real operator /(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator ==(const real& num_1, double num_2);
		friend NUMBER_API inline bool operator ==(double num_1, const real& num_2);
		friend NUMBER_API inline bool operator ==(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator !=(const real& num_1, double num_2);
		friend NUMBER_API inline bool operator !=(double num_1, const real& num_2);
		friend NUMBER_API inline bool operator !=(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator <(const real& num_1, double num_2);
		friend NUMBER_API inline bool operator <(double num_1, const real& num_2);
		friend NUMBER_API inline bool operator <(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator <=(const real& num_1, double num_2);
		friend NUMBER_API inline bool operator <=(double num_1, const real& num_2);
		friend NUMBER_API inline bool operator <=(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator >(const real& num_1, double num_2);
		friend NUMBER_API inline bool operator >(double num_1, const real& num_2);
		friend NUMBER_API inline bool operator >(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator >=(const real& num_1, double num_2);
		friend NUMBER_API inline bool operator >=(double num_1, const real& num_2);
		friend NUMBER_API inline bool operator >=(const real& num_1, const real& num_2);

		friend NUMBER_API inline bool operator !(const real& num);

		// real_overload_cmath.cpp
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

		friend NUMBER_API inline double frexp(const real& num, int* exponent);
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
		friend NUMBER_API inline double modf(const real& num, double* integer);
		friend NUMBER_API inline double modf(double num, real& integer);
		friend NUMBER_API inline double modf(const real& num, real& integer);

		friend NUMBER_API inline double pow(const real& num, double exponent);
		friend NUMBER_API inline double pow(double num, const real& exponent);
		friend NUMBER_API inline double pow(const real& num, const real& exponent);
		friend NUMBER_API inline double pow2(const real& num);
		friend NUMBER_API inline double pow10(const real& num);
		friend NUMBER_API inline double sqrt(const real& num);
		friend NUMBER_API inline double hypot(const real& x, const real& y);

		friend NUMBER_API inline double ceil(const real& num);
		friend NUMBER_API inline double round(const real& num);
		friend NUMBER_API inline double floor(const real& num);
		friend NUMBER_API inline double trunc(const real& num);
		friend NUMBER_API inline double fabs(const real& num);

		friend NUMBER_API inline double fmod(const real& num_1, double num_2);
		friend NUMBER_API inline double fmod(double num_1, const real& num_2);
		friend NUMBER_API inline double fmod(const real& num_1, const real& num_2);
	};

	class NUMBER_API complex {
		double _real, _imag;

	public:
		bool known;

		// complex.cpp
		inline complex();
		inline complex(const complex& cpl);
		inline complex(double real);
		inline complex(double a, double b, int mod = cpl_RECT);
		inline double real();
		inline double imag();

		// complex_self_operation.cpp
		inline void add(const complex& cpl);
		inline void sub(const complex& cpl);
		inline void mul(const complex& cpl);
		inline void div(const complex& cpl);
		inline void exc();
		inline void absc();
	};
}