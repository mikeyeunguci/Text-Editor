#include "CursorLeft.hpp"
#include "EditorException.hpp"

CursorLeft::CursorLeft()
{
}


void CursorLeft::execute(EditorModel& model)
{
    prevCol = model.cursorColumn();
    prevRow = model.cursorLine();   
    if (model.cursorColumn() == 1)
    {
        if (model.cursorLine() == 1)
        {
            throw EditorException("Already at beginning");
        }
        else
        {
            model.setRow(model.cursorLine() - 1);
            model.setCol(model.getV()[model.cursorLine() - 1].size() + 1);
        }
    }
    else
    {
        model.setCol(model.cursorColumn() - 1);
    }
}


void CursorLeft::undo(EditorModel& model)
{
    model.setCol(prevCol);
    model.setRow(prevRow);
}