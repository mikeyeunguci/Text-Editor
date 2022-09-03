#include "CursorHome.hpp"

CursorHome::CursorHome()
{
}


void CursorHome::execute(EditorModel& model)
{
    prevcolumn = model.cursorColumn();
    prevrow = model.cursorLine();
    model.setCol(1);
}


void CursorHome::undo(EditorModel& model)
{
    model.setCol(prevcolumn);
    model.setRow(prevrow);
}