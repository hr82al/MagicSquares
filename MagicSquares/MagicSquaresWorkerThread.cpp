//MagicSquaresWorkerThread.cpp

//This part is a contlol part(MVC)

/* Runs a thread for calculation a magic square.
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
#include "SquaresFrame.h"

MagicSquaresWorkerThread::MagicSquaresWorkerThread(SquaresFrame* aframe) 
	: frame(aframe)
{
}
wxThread::ExitCode MagicSquaresWorkerThread::Entry() {
	MagicSquare magicSquare(frame->squareSize);
	frame->magicSquare = magicSquare.getMatrix();
	wxThreadEvent event(wxEVT_THREAD, WORKER_EVENT);
	wxQueueEvent(frame, event.Clone());
	frame->mutex.Unlock();
	return NULL;
}