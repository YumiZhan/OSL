#include "pch.h"
#include "number.h"

namespace osl {
	template <class num>
	inline complex<num>::complex() :
		known(false), _real(0), _imag(0)
	{}

	template<class num>
	inline complex<num>::complex(const num& real) :
		known(true), _real(real), imag(0)
	{}

	template<class num>
	inline complex<num>::complex(const num& real, const num& imag) :
		known(true), _real(real), _imag(imag)
	{}
	
	template<class num>
	inline num complex<num>::real()
	{
		return _real;
	}
	
	template<class num>
	inline num complex<num>::imag()
	{
		return _imag;
	}
}