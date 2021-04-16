/* OSL/Number/number.h
 *
 * Copyright (C) 2021 YuminZhan
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this
 * program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#ifdef NUMBER_EXPORTS
#	define NUMBER_API __declspec(dllexport)
#else
#	define NUMBER_API __declspec(dllimport)
#	pragma	comment(lib, "number")
#endif // _NUMBER_EXPORTS

#include <iostream>

#define BEGIN_OSL namespace osl {
#define END_OSL }

#define CPL_RECT 0
#define CPL_POLA 1

// throw value
#define IMPOSSIBLE 0

BEGIN_OSL // namespace osl {
typedef const double& argument, agm;
typedef const char* c_str;
typedef int error;

extern NUMBER_API double PI; // 3.1415926535897932
extern NUMBER_API double ZERO; // 1E-10

NUMBER_API inline void simplify_fraction(double& denominator, double& numerator);

class NUMBER_API rational {
	typedef const rational& agm_rational;
	double _denominator, _numerator;
	// object_operation.cpp
	inline void simplify();

public:
	bool known;

	// rational.cpp
	inline rational();
	inline rational(agm_rational origin);
	inline rational(agm num);
	inline rational(agm numerator, agm denominator);
	inline rational(c_str c_str);
	inline rational(const wchar_t* w_str);

	inline bool zero(agm reference = 1)const;
	inline bool zero(agm_rational reference)const;
	inline bool infinite(agm reference = 1)const;
	inline bool infinite(agm_rational reference)const;

	inline double denominator()const;
	inline double numerator()const;
	inline void console_print(c_str end = "\n")const;
	inline void console_show(c_str end = "\n")const;
	inline rational to_radian()const;
	inline rational to_degree()const;

	// rational_modifier.cpp.cpp
	inline void rec();
	inline void absr();
	inline void add(agm num);
	inline void add(agm_rational rational);
	inline void sub(agm num);
	inline void sub(agm_rational rational);
	inline void mul(agm num);
	inline void mul(agm_rational rational);
	inline void div(agm num);
	inline void div(agm_rational rational);

	// rational_comparation.cpp
	inline bool larger_than(agm num)const;
	inline bool larger_than(agm_rational num)const;
	inline bool not_less_than(agm num)const;
	inline bool not_less_than(agm_rational num)const;
	inline bool less_than(agm num)const;
	inline bool less_than(agm_rational num)const;
	inline bool not_larger_than(agm num)const;
	inline bool not_larger_than(agm_rational num)const;
	inline bool equal_to(agm num, double reference = 0.0)const;
	inline bool equal_to(agm_rational num, rational reference = 0.0)const;

	// rational_overload_operators.cpp
	inline operator double()const;

	friend NUMBER_API inline std::ostream& operator <<(std::ostream& os, agm_rational output_rational);
	friend NUMBER_API inline std::istream& operator >>(std::istream& is, rational& input_rational);

	friend NUMBER_API inline rational operator ~(agm_rational origin);

	inline rational& operator +=(agm num);
	inline rational& operator +=(agm_rational num);

	inline rational& operator -=(agm num);
	inline rational& operator -=(agm_rational num);

	inline rational& operator *=(agm num);
	inline rational& operator *=(agm_rational num);

	inline rational& operator /=(agm num);
	inline rational& operator /=(agm_rational num);

	inline rational& operator ^=(agm num);
	inline rational& operator ^=(agm_rational num);

	inline rational& operator ++();
	inline rational operator ++(int);
	inline rational& operator --();
	inline rational operator --(int);

	friend NUMBER_API inline rational operator +(agm_rational num);
	friend NUMBER_API inline rational operator -(agm_rational num);

	friend NUMBER_API inline rational operator +(agm_rational num_1, agm num_2);
	friend NUMBER_API inline rational operator +(agm num_1, agm_rational num_2);
	friend NUMBER_API inline rational operator +(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline rational operator -(agm_rational num_1, agm num_2);
	friend NUMBER_API inline rational operator -(agm num_1, agm_rational num_2);
	friend NUMBER_API inline rational operator -(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline rational operator *(agm_rational num_1, agm num_2);
	friend NUMBER_API inline rational operator *(agm num_1, agm_rational num_2);
	friend NUMBER_API inline rational operator *(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline rational operator /(agm_rational num_1, agm num_2);
	friend NUMBER_API inline rational operator /(agm num_1, agm_rational num_2);
	friend NUMBER_API inline rational operator /(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline rational operator ^(agm_rational num_1, agm_rational num_2);
	friend NUMBER_API inline rational operator ^(agm num_1, agm_rational num_2);
	friend NUMBER_API inline rational operator ^(agm_rational num_1, agm num_2);

	friend NUMBER_API inline bool operator ==(agm_rational num_1, agm num_2);
	friend NUMBER_API inline bool operator ==(agm num_1, agm_rational num_2);
	friend NUMBER_API inline bool operator ==(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline bool operator !=(agm_rational num_1, agm num_2);
	friend NUMBER_API inline bool operator !=(agm num_1, agm_rational num_2);
	friend NUMBER_API inline bool operator !=(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline bool operator <(agm_rational num_1, agm num_2);
	friend NUMBER_API inline bool operator <(agm num_1, agm_rational num_2);
	friend NUMBER_API inline bool operator <(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline bool operator <=(agm_rational num_1, agm num_2);
	friend NUMBER_API inline bool operator <=(agm num_1, agm_rational num_2);
	friend NUMBER_API inline bool operator <=(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline bool operator >(agm_rational num_1, agm num_2);
	friend NUMBER_API inline bool operator >(agm num_1, agm_rational num_2);
	friend NUMBER_API inline bool operator >(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline bool operator >=(agm_rational num_1, agm num_2);
	friend NUMBER_API inline bool operator >=(agm num_1, agm_rational num_2);
	friend NUMBER_API inline bool operator >=(agm_rational num_1, agm_rational num_2);

	friend NUMBER_API inline bool operator !(agm_rational num);

	// rational_overload_cmath.cpp
	friend NUMBER_API inline double cos(agm_rational num);
	friend NUMBER_API inline double cosh(agm_rational num);
	friend NUMBER_API inline double sin(agm_rational num);
	friend NUMBER_API inline double sinh(agm_rational num);
	friend NUMBER_API inline double tan(agm_rational num);
	friend NUMBER_API inline double tanh(agm_rational num);

	friend NUMBER_API inline double acos(agm_rational num);
	friend NUMBER_API inline double acosh(agm_rational num);
	friend NUMBER_API inline double asin(agm_rational num);
	friend NUMBER_API inline double asinh(agm_rational num);
	friend NUMBER_API inline double atan(agm_rational num);
	friend NUMBER_API inline double atan2(agm_rational num_1, agm num_2);
	friend NUMBER_API inline double atan2(agm num_1, agm_rational num_2);
	friend NUMBER_API inline double atan2(agm_rational num_1, agm_rational num_2);
	friend NUMBER_API inline double atanh(agm_rational num);

	friend NUMBER_API inline double exp(agm_rational num);
	friend NUMBER_API inline double exp2(agm_rational num);
	friend NUMBER_API inline double expm1(agm_rational num);

	friend NUMBER_API inline double frexp(agm_rational num, int* exponent);
	friend NUMBER_API inline double ldexp(agm_rational num, int exponent);

	friend NUMBER_API inline double log(agm_rational num, agm base);
	friend NUMBER_API inline double log(agm num, agm_rational base);
	friend NUMBER_API inline double log(agm_rational num, agm_rational base);
	friend NUMBER_API inline double log(agm_rational num);
	friend NUMBER_API inline double ln(agm_rational num) { return log(num); }
	friend NUMBER_API inline double log2(agm_rational num);
	friend NUMBER_API inline double log10(agm_rational num);
	friend NUMBER_API inline double lg(agm_rational num) { return log10(num); }
	friend NUMBER_API inline double log1p(agm_rational num);

	friend NUMBER_API inline double copysign(agm_rational num_1, agm_rational num_2);
	friend NUMBER_API inline double modf(agm_rational num, double* integer);
	friend NUMBER_API inline double modf(agm num, rational& integer);
	friend NUMBER_API inline double modf(agm_rational num, rational& integer);

	friend NUMBER_API inline double pow(agm_rational num, agm exponent);
	friend NUMBER_API inline double pow(agm num, agm_rational exponent);
	friend NUMBER_API inline double pow(agm_rational num, agm_rational exponent);
	friend NUMBER_API inline double pow2(agm_rational num);
	friend NUMBER_API inline double pow10(agm_rational num);
	friend NUMBER_API inline double sqrt(agm_rational num);
	friend NUMBER_API inline double hypot(agm_rational x, agm_rational y);

	friend NUMBER_API inline double ceil(agm_rational num);
	friend NUMBER_API inline double round(agm_rational num);
	friend NUMBER_API inline double floor(agm_rational num);
	friend NUMBER_API inline double trunc(agm_rational num);
	friend NUMBER_API inline double fabs(agm_rational num);

	friend NUMBER_API inline double fmod(agm_rational num_1, agm num_2);
	friend NUMBER_API inline double fmod(agm num_1, agm_rational num_2);
	friend NUMBER_API inline double fmod(agm_rational num_1, agm_rational num_2);
};
typedef const rational& agm_rational;

class NUMBER_API complex {
	typedef const complex& agm_cpl;
	double _real, _imag;

public:
	bool known;

	// complex.cpp
	/* Constructor */
	inline complex();
	inline complex(agm_cpl cpl);
	inline complex(agm real);
	inline complex(agm a, agm b, int mod = CPL_RECT);
	complex(c_str str);
	/* Console Print */
	inline void console_print_rect(c_str end = "\n")const;
	inline void console_print_polar(c_str end = "\n")const;
	/* Properties of Complex Numbers */
	inline double real()const;
	inline double imag()const;
	inline double abs()const;
	inline double abs2()const;
	inline double agl()const;
	inline double logabs()const;

	// complex_modifier.cpp
	inline void add(agm_cpl cpl);
	inline void add(agm real, agm imag = 0.0);
	inline void sub(agm_cpl cpl);
	inline void sub(agm real, agm imag = 0.0);
	inline void mul(agm_cpl cpl);
	inline void mul(agm real, agm imag = 0.0);
	inline void div(agm_cpl cpl);
	inline void div(agm real, agm imag = 0.0);
	inline void exc();
	inline void absc();

	// complex_utility_functions.cpp
	/* Complex Comparation */
	inline bool equal_to(agm_cpl cpl, double reference = 0.0)const;
	/* Elementary Complex Functions */
	inline complex conjugated()const;
	inline complex inversed()const;
	inline complex negative()const;
	inline complex pow(agm_cpl cpl)const;
	inline complex pow(agm real)const;
	friend NUMBER_API inline complex sqrt(agm_cpl cpl);
	friend NUMBER_API inline complex sqrt(agm real);
	friend NUMBER_API inline complex exp(agm_cpl index);
	friend NUMBER_API inline complex exp(agm index);
	inline complex log(agm_cpl base)const;
	inline complex log(agm base = ::exp(1.0))const;
	inline complex ln()const { return this->log(); }
	inline complex log10()const;
	inline complex lg()const { return this->log10(); }
	/* Complex Trigonometric Functions and Inverse Complex Trigonometric Functions */
	friend NUMBER_API inline complex cos(agm_cpl cpl);
	friend NUMBER_API inline complex sin(agm_cpl cpl);
	friend NUMBER_API inline complex tan(agm_cpl cpl);
	friend NUMBER_API inline complex csc(agm_cpl cpl);
	friend NUMBER_API inline complex sec(agm_cpl cpl);
	friend NUMBER_API inline complex cot(agm_cpl cpl);
	friend NUMBER_API inline complex acos(agm_cpl cpl);
	friend NUMBER_API inline complex asin(agm_cpl cpl);
	friend NUMBER_API inline complex atan(agm_cpl cpl);
	friend NUMBER_API inline complex acsc(agm_cpl cpl);
	friend NUMBER_API inline complex asec(agm_cpl cpl);
	friend NUMBER_API inline complex acot(agm_cpl cpl);
	/* Complex Hyperbolic Functions and Inverse Complex Hyperbolic Functions */
	friend NUMBER_API inline complex cosh(agm_cpl cpl);
	friend NUMBER_API inline complex sinh(agm_cpl cpl);
	friend NUMBER_API inline complex tanh(agm_cpl cpl);
	friend NUMBER_API inline complex csch(agm_cpl cpl);
	friend NUMBER_API inline complex sech(agm_cpl cpl);
	friend NUMBER_API inline complex coth(agm_cpl cpl);
	friend NUMBER_API inline complex acosh(agm_cpl cpl);
	friend NUMBER_API inline complex asinh(agm_cpl cpl);
	friend NUMBER_API inline complex atanh(agm_cpl cpl);
	friend NUMBER_API inline complex acsch(agm_cpl cpl);
	friend NUMBER_API inline complex asech(agm_cpl cpl);
	friend NUMBER_API inline complex acoth(agm_cpl cpl);

	// complex_overload_operators.cpp
	/* Stream Operations */
	friend NUMBER_API inline std::ostream& operator <<(std::ostream& os, agm_cpl cpl);
	friend NUMBER_API std::istream& operator >>(std::istream& is, complex& cpl);
	/* Change Properties */
	friend NUMBER_API inline complex operator ~(agm_cpl cpl);
	friend NUMBER_API inline complex operator +(agm_cpl cpl);
	friend NUMBER_API inline complex operator -(agm_cpl cpl);
	/* Fundamental Operations */
	friend NUMBER_API inline complex operator +(agm_cpl cpl1, agm_cpl cpl2);
	friend NUMBER_API inline complex operator +(agm_cpl cpl, agm real);
	friend NUMBER_API inline complex operator +(agm real, agm_cpl cpl);
	friend NUMBER_API inline complex operator -(agm_cpl cpl1, agm_cpl cpl2);
	friend NUMBER_API inline complex operator -(agm_cpl cpl, agm real);
	friend NUMBER_API inline complex operator -(agm real, agm_cpl cpl);
	friend NUMBER_API inline complex operator *(agm_cpl cpl1, agm_cpl cpl2);
	friend NUMBER_API inline complex operator *(agm_cpl cpl, agm real);
	friend NUMBER_API inline complex operator *(agm real, agm_cpl cpl);
	friend NUMBER_API inline complex operator /(agm_cpl cpl1, agm_cpl cpl2);
	friend NUMBER_API inline complex operator /(agm_cpl cpl, agm real);
	friend NUMBER_API inline complex operator /(agm real, agm_cpl cpl);
	friend NUMBER_API inline complex operator ^(agm_cpl cpl1, agm_cpl cpl2);
	friend NUMBER_API inline complex operator ^(agm_cpl cpl, agm real);
	friend NUMBER_API inline complex operator ^(agm real, agm_cpl cpl);
	/* Compound Assignments */
	inline complex& operator +=(agm_cpl cpl);
	inline complex& operator +=(agm real);
	inline complex& operator -=(agm_cpl cpl);
	inline complex& operator -=(agm real);
	inline complex& operator *=(agm_cpl cpl);
	inline complex& operator *=(agm real);
	inline complex& operator /=(agm_cpl cpl);
	inline complex& operator /=(agm real);
	inline complex& operator ^=(agm_cpl cpl);
	inline complex& operator ^=(agm real);
	/* Complex Comparations */
	friend NUMBER_API inline bool operator ==(agm_cpl cpl1, agm_cpl cpl2);
	friend NUMBER_API inline bool operator !=(agm_cpl cpl1, agm_cpl cpl2);
	
};
typedef const complex& agm_cpl;
extern NUMBER_API const complex i; // i = complex(0.0, 1.0)

END_OSL // }