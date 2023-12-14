#pragma once

//Square.h

//This file is a model part(MVC)

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

#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

/*
 ласс квадрата это квадратна€ матрица со стороной size
*/
class Square {
private:
	matrix<unsigned> data;


protected:
	unsigned operator()(unsigned columnn, unsigned row)const;
	unsigned& operator()(unsigned columnn, unsigned row);
	unsigned size{ 0 };

public:
	Square(unsigned _size);
	matrix<unsigned> getMatrix();
	friend std::ostream& operator<<(std::ostream& out, Square square);
};