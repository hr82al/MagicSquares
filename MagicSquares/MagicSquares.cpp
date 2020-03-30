#include "MagicSquares.h"

wxIMPLEMENT_APP(MagicSquares);

bool MagicSquares::OnInit()
{
	SquaresFrame* squareFrame = new SquaresFrame();
	squareFrame->Show(true);
	return true;
}
