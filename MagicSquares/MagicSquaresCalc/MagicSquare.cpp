//MagicSquare.cpp

//This file is a model part(MVC)

/* Data calculation.
   Copyright (C) 2020 Aleksandr Khromov.
This file is part of Magic Squares.
Magic Squares is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
Magic Squares is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Magic Squares.  If not, see <https://www.gnu.org/licenses/>.  */

#include "MagicSquare.h"

MagicSquare::MagicSquare(unsigned _size) : Square{_size}
{
	if ((size % 2) != 0) {//если квадрат нечётный
		evalOddMagicSquare();
	}
	else if ((size % 4) == 0) {
		evalDoubleEvenMagicSquare();
	}
}

unsigned MagicSquare::get(unsigned column, unsigned row)
{
	return (*this)(column, row);
}

//построение нечётного магического квадрата
//Building an odd magic square
void MagicSquare::evalOddMagicSquare()
{
	const unsigned N = size - 1;
	unsigned i = 0;
	unsigned j = (size + 1) / 2 - 1;
	for (unsigned count = 1 ; count <= size * size; count++) {
		(*this)(i, j) = count;
		//при каждом size-ом пмеремещении сдвигаемся на позицию вниз
		if (count % size == 0) {
			i++;
		}
		else {
			if (i == 0) {
				i = N;
			}
			else
			{
				i--;
			}
			if (j == N) {
				j = 0;
			}
			else {
				j++;
			}
		}
	}
}

void MagicSquare::evalDoubleEvenMagicSquare()
{
	const unsigned SUB_SIZE = 4;
	const unsigned MAX = size * size;
	unsigned subRow;
	unsigned subClolumn;
	for (unsigned row = 0; row < size; row++) {
		for (unsigned column = 0; column < size; column++) {
			subRow = row % SUB_SIZE;
			subClolumn = column % SUB_SIZE;
			// если строка и стольбец принадлежит главной или побочной диагонали или  блока 4x4 
			if (subRow == subClolumn || subRow + subClolumn == 3) { 
				(*this)(row, column) = row * size + column + 1;  
			}
			else {
				(*this)(row, column) = MAX - row * size - column ;
			}
		}
	}
}
