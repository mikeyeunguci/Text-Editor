#include "CursorEnd.hpp"


CursorEnd::CursorEnd()
{

}


void CursorEnd::execute(EditorModel& model)
{
    prevcolumn = model.cursorColumn();
    prevrow = model.cursorLine();
    model.setCol(model.getV()[model.cursorLine()-1].size() + 1);
}


void CursorEnd::undo(EditorModel& model)
{
    model.setCol(prevcolumn);
    model.setRow(prevrow);
}