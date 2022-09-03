#include "CursorDown.hpp"
#include "EditorException.hpp"

CursorDown::CursorDown()
{
}


void CursorDown::execute(EditorModel& model)
{
    prevrow = model.cursorLine();
    prevcolumn = model.cursorColumn();
    if (model.cursorLine() == model.getV().size())
    {
        throw EditorException("Already at bottom");
    }
    else
    {
        model.setRow(model.cursorLine() + 1);
        if (model.getV()[model.cursorLine()-1].size() + 1 < model.cursorColumn())
        {
            model.setCol(model.getV()[model.cursorLine()-1].size() + 1);
        }
    }

}

void CursorDown::undo(EditorModel& model)
{
    model.setRow(prevrow);
    model.setCol(prevcolumn);
}