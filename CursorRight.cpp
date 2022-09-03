#include "CursorRight.hpp"
#include <iostream> //debug
#include "EditorException.hpp"

CursorRight::CursorRight()
{
}


void CursorRight::execute(EditorModel& model)
{
    prevCol = model.cursorColumn();
    prevRow = model.cursorLine();
    if (model.CursorAtEnd() == true)
    {
        if (model.getV().size() == model.cursorLine())
        {
            throw EditorException("Already at end");
        }
        else
        {
            model.setRow(model.cursorLine() + 1);
            model.setCol(1);
        }
        
    }
    else
    {
        model.setCol(model.cursorColumn() + 1);
    }
}


void CursorRight::undo(EditorModel& model)
{
    model.setCol(prevCol);
    model.setRow(prevRow);
}