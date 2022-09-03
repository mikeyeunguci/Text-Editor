#include "BackSpace.hpp"
#include "EditorException.hpp"


BackSpace::BackSpace()
{
    boolUndoChar = false;
}


void BackSpace::execute(EditorModel& model)
{
    if (model.cursorColumn() == 1 && model.cursorLine() == 1)
    {
        throw EditorException("Already at beginning");
    }
    prevcolumn = model.cursorColumn();
    prevrow = model.cursorLine();
    if (model.cursorColumn() != 1)
    {
        boolUndoChar = true;
        undochar = model.getV()[model.cursorLine() - 1][model.cursorColumn() - 2];
        model.deleteChar();
    }
    else
    {
        prevstring = model.getV()[model.cursorLine() - 2];
        reAdd = model.getV()[model.cursorLine()-1];
        model.getV().erase(model.getV().begin() + model.cursorLine() - 1);
        model.setRow(model.cursorLine() - 1);
        model.setCol(model.getV()[model.cursorLine() - 1].size() + 1);
        model.getV()[model.cursorLine()-1].append(reAdd);
    }
}


void BackSpace::undo(EditorModel& model)
{
    if (boolUndoChar == true)
    {
        model.insertChar(undochar);
    }
    else
    {
        model.getV().insert(model.getV().begin() + model.cursorLine(), reAdd);
        model.getV()[model.cursorLine()-1] = prevstring;
        model.setCol(prevcolumn);
        model.setRow(prevrow);
    }
}