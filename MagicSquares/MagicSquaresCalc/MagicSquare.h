#pragma once

//MagicSquare.h

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

#include "Square.h"

class MagicSquare : public Square {
public:
	MagicSquare(unsigned _size);
	unsigned get(unsigned column, unsigned row);

private:
	void evalOddMagicSquare();
	void evalDoubleEvenMagicSquare();
};