#pragma once
//SquaresFrame.h

/* Shows GUI window.
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

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include "MagicSquaresCalc/MagicSquare.h"


// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

const unsigned msDEFAULT_SIZE = 3;
// control ids

enum {
	msID_SPINCTL = wxID_HIGHEST,
	WORKER_EVENT
};



//This class is a view part(MVC)
class SquaresFrame :
	public wxFrame
{
public:
	SquaresFrame();
	unsigned squareSize = msDEFAULT_SIZE;
	matrix<unsigned> magicSquare;

	wxMutex mutex;

protected:
	// event hadlers
	void OnSpinCtrl(wxSpinEvent& event);
	void OnTextChange(wxCommandEvent& event);
	void OnWorkerEvent(wxThreadEvent& event);
private:
	wxGrid* grid;
	wxSpinCtrl* spinCtrl;
	wxBoxSizer* vsizer;
	void resize_table(unsigned n);
	void updateSquare(unsigned N);
	wxDECLARE_EVENT_TABLE();
};



//This class is a contlol part(MVC)
class MagicSquaresWorkerThread :
	public wxThread
{
public:
	MagicSquaresWorkerThread(SquaresFrame* aframe);
	virtual void* Entry() wxOVERRIDE;
private:
	SquaresFrame* frame;
};
