//Square.cpp

//This file is a view part(MVC)

/* A generic square.
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


#include "Square.h"
#include <climits>

const char DELIMITER{';'}; //разделтитель между элементасми квадрата в строках

std::ostream& operator<<(std::ostream& out, Square square)
{
	for (size_t j = 0; j < square.size; j++) {
		for (size_t i = 0; i < square.size - 1; i++) {
			out << square(j, i) << DELIMITER;
		}
		out << square(j, square.size - 1) << std::endl;
	}
	return out;
}

//доступ дл€ чтени€ к элементу квадрата через оператор ()
unsigned Square::operator()(unsigned columnn, unsigned row) const
{
	return data(columnn, row);
}

//доступ дл€ изменине€ елемента квадрата через оператор ()
unsigned& Square::operator()(unsigned column, unsigned row)
{
	return data(column, row);
}

//–азмер стороны квадраты задаЄтс€ в конструкторе
Square::Square(unsigned _size)
{
	if (_size > sqrt(UINT_MAX)) {
		throw new std::exception("«начение стороны квадрата слишком большое");
	}
	const unsigned INIT_VALUE = 0;
	size = _size;
	//data = new unsigned[size * size]{ 0 };
	data = matrix<unsigned>(size, size);
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			data(i, j) = INIT_VALUE;
		}
	}

}

matrix<unsigned> Square::getMatrix()
{
	return data;
}
