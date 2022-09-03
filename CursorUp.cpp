#include "CursorUp.hpp"
#include "EditorException.hpp"

CursorUp::CursorUp()
{
}


void CursorUp::execute(EditorModel& model)
{
    prevcolumn = model.cursorColumn();
    prevrow = model.cursorLine();
    if (model.cursorLine() == 1)
    {
        throw EditorException("Already at Top");
    }
    model.setRow(model.cursorLine() - 1);
    if (model.getV()[model.cursorLine()-1].size() + 1 < model.cursorColumn())
    {
        model.setCol(model.getV()[model.cursorLine()-1].size() + 1);
    }
}

void CursorUp::undo(EditorModel& model)
{
    model.setRow(prevrow);
    model.setCol(prevcolumn);
}


