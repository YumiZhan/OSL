/* OSL/Matrix/exc::matrix.cpp
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

#include "pch.h"
#include "matrix.h"
using namespace osl::exc;
using osl::c_str;

c_str vector::overview_list[] = {
	"Failed to allocate space",	//0
	"Unexpected NULL pointer",	//1
	"Beyond range",				//2
	"",
	"Incorrect number of size",	//4
	"The start number is larger than the end number",	//5
	""
	"Size unmatched",			//7
};

inline vector::vector(unsigned code, c_str discription) :
	code(code), discription(discription)
{}

inline c_str osl::exc::vector::overview() const
{
	return vector::overview_list[code];
}

c_str matrix::overview_list[] = {
	"Failed to allocate space",		//0
	"Unexpected NULL pointer",		//1
	"Beyond range",					//2
	"Incorrect number of rows",		//3
	"Incorrect number of columns",	//4
	"The start number is large than the end number"	//5
	"Number of rows unmatched"		//6
	"Number of columns unmatched",	//7
};

inline matrix::matrix(unsigned code, c_str discription) :
	code(code), discription(discription)
{}

inline c_str matrix::overview() const
{
	return matrix::overview_list[code];
}