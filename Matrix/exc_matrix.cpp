/* OSL/Matrix/exc_matrix.cpp
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

osl::c_str osl::exc_matrix::overview_list[] = {
	"Failed to allocate space",	//0
	"Unexpected NULL pointer",	//1
	"Beyond range",				//2
	"Unexpected number of columns",	//3
	"Unexpected number of rows",	//4
	"The start number is large than the end number"	//5
};

inline osl::exc_matrix::exc_matrix(unsigned num, c_str discription) :
	num(num), discription(discription)
{}

inline osl::c_str osl::exc_matrix::overview() const
{
	return exc_matrix::overview_list[num];
}