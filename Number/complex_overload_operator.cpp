#include "pch.h"
#include "number.h"
#include <cmath>
#include <string>
using std::string;

namespace osl {
	inline std::ostream& operator <<(std::ostream& os, agm_cpl cpl)
	{
		if (cpl._real != 0.0) {
			os << cpl._real;
			if (cpl._imag > 0.0)
				os << '+';
		}
		else if (cpl._imag == 0.0) { // _real == 0 && _imag == 0
			os << 0.0;
			return os;
		}
		if (cpl._imag > 0.0) { // _real == 0 && _imag > 0
			if (cpl._imag != 1.0)
				os << cpl._imag;
			os << 'i';
		}
		else if (cpl._imag < 0.0) { // _real == 0 && _imag < 0
			if (cpl._imag != -1.0)
				os << cpl._imag;
			os << "-i";
		}
		return os;
	}

	std::istream& operator >>(std::istream& is, complex& cpl)
	{
		string str;
		is >> str;
		cpl = complex(str.c_str());
		return is;
	}

	complex operator ~(agm_cpl cpl)
	{
		return complex(cpl._real, -cpl._imag);
	}

	complex operator +(agm_cpl cpl)
	{
		return cpl;
	}

	complex operator -(agm_cpl cpl)
	{
		return complex(-cpl._real, -cpl._imag);
	}

	complex operator +(agm_cpl cpl1, agm_cpl cpl2)
	{
		return complex(cpl1._real + cpl2._real, cpl1._imag + cpl2._imag);
	}

	complex operator +(agm_cpl cpl, agm real)
	{
		return complex(cpl._real + real, cpl._imag);
	}

	complex operator +(agm real, agm_cpl cpl)
	{
		return complex(real + cpl._real, cpl._imag);
	}

	complex operator -(agm_cpl cpl1, agm_cpl cpl2)
	{
		return complex(cpl1._real - cpl2._real, cpl1._imag - cpl2._imag);
	}

	complex operator -(agm_cpl cpl, agm real)
	{
		return complex(cpl._real - real, cpl._imag);
	}

	complex operator -(agm real, agm_cpl cpl)
	{
		return complex(real - cpl._real, -cpl._imag);
	}

	complex operator *(agm_cpl cpl1, agm_cpl cpl2)
	{
		return complex(cpl1._real * cpl2._real - cpl1._imag * cpl2._imag, cpl1._real * cpl2._imag + cpl1._imag * cpl2._real);
	}

	complex operator *(agm_cpl cpl, agm real)
	{
		return complex(cpl._real * real, cpl._imag * real);
	}

	complex operator *(agm real, agm_cpl cpl)
	{
		return complex(real * cpl._real, real * cpl._imag);
	}

	complex operator /(agm_cpl cpl1, agm_cpl cpl2)
	{
		complex temp(cpl1);
		temp.div(cpl2);
		return temp;
	}

	complex operator /(agm_cpl cpl, agm real)
	{
		complex temp(cpl);
		temp.div(real);
		return temp;
	}

	complex operator /(agm real, agm_cpl cpl)
	{
		complex temp(real);
		temp.div(cpl);
		return temp;
	}

}