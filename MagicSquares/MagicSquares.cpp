//MagicSquare.cpp

//This file is a view part(MVC)

/* A started point of application.
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

#include "MagicSquares.h"

//������, ���������������� ��������� � ���������� ������ �����
wxIMPLEMENT_APP(MagicSquares);

bool MagicSquares::OnInit()
{
	SquaresFrame* squareFrame = new SquaresFrame();
	squareFrame->Show(true);
	return true;
}
