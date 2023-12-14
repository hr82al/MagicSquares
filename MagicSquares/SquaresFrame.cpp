//SquaresFrame.cpp

//This file is a view part(MVC)

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
#include "SquaresFrame.h"


// ----------------------------------------------------------------------------
// event tables
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE(SquaresFrame, wxFrame)
EVT_SPINCTRL(msID_SPINCTL, SquaresFrame::OnSpinCtrl)
EVT_TEXT(msID_SPINCTL, SquaresFrame::OnTextChange)
EVT_THREAD(WORKER_EVENT, OnWorkerEvent)
wxEND_EVENT_TABLE()


SquaresFrame::SquaresFrame() : wxFrame(nullptr, wxID_ANY, "Магические квадраты")
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* hsizer = new wxBoxSizer(wxHORIZONTAL);
	vsizer = new wxBoxSizer(wxVERTICAL);
	spinCtrl = new wxSpinCtrl(panel, msID_SPINCTL);
	/* 
	Due to experiments was figured out that max size of square grid of my computer
	is about 7000 x 7000. Therefore there is the limit of generated magic 
	squares from 3 to 7000
	*/
	spinCtrl->SetRange(msDEFAULT_SIZE, 7000);
	spinCtrl->SetValue(msDEFAULT_SIZE);
	hsizer->Add(new wxStaticText(panel, wxID_ANY, wxT("Сторона магического квадрата N:")));
	hsizer->Add(spinCtrl);
	grid = new wxGrid(panel, wxID_ANY);
	grid->CreateGrid(msDEFAULT_SIZE, msDEFAULT_SIZE);

	//Remove rows and columns titles
	grid->SetRowLabelSize(0);
	grid->SetColLabelSize(0);
	
	grid->EnableEditing(false);

	vsizer->Add(hsizer);
	vsizer->Add(grid);
	
	CreateStatusBar();

	panel->SetSizer(vsizer);
	vsizer->SetSizeHints(this);
	updateSquare(msDEFAULT_SIZE);
}


void SquaresFrame::OnSpinCtrl(wxSpinEvent& event)
{
	int value = event.GetInt();
	updateSquare(value);
}

void SquaresFrame::OnTextChange(wxCommandEvent& event)
{
	int value = event.GetInt();
	updateSquare(value);
}

void SquaresFrame::OnWorkerEvent(wxThreadEvent& event)
{
	SetStatusText("Формируется изображение квадрата со стороной " +
		std::to_string(squareSize));
	resize_table(squareSize);
	for (unsigned row = 0; row < squareSize; row++) {
		for (unsigned column = 0; column < squareSize; column++) {
			grid->SetCellValue(row, column,
				std::to_string(magicSquare(row, column)));
		}
	}
	SetStatusText("Изображён квадрат со стороной " +
		std::to_string(squareSize));
	// At this point calculations is ended and a permission to change
	//a square side is granted
	spinCtrl->Enable();
}


void SquaresFrame::resize_table(unsigned n)
{
	int N = static_cast<int>(n);
	if (N > grid->GetNumberCols()) {
		grid->AppendCols(N - grid->GetNumberCols());
		grid->AppendRows(N - grid->GetNumberRows());
	}
	else {
		grid->DeleteCols(0, grid->GetNumberCols() - N);
		grid->DeleteRows(0, grid->GetNumberRows() - N);
	}
	vsizer->SetSizeHints(this);
}

void SquaresFrame::updateSquare(unsigned N)
{
	if (((N % 2) == 0) && ((N % 4) != 0)) {
		SetStatusText("Квадрат со стороной " + std::to_string(N) + 
			" не является " + "ни нечётным, ни дважды чётным");
		return;
	}
	squareSize = N;

	if (mutex.TryLock() == wxMUTEX_NO_ERROR) {
		//It prevents changing a curent calcalation tast 
		//while calculations is not ended
		spinCtrl->Disable();
		MagicSquaresWorkerThread* thread = new MagicSquaresWorkerThread(this);
		if (thread->Create() != wxTHREAD_NO_ERROR)
		{
			return;
		}
		thread->Run();
	}
	else {
		return;
	}
}
