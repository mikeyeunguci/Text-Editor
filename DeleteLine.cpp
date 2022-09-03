#include "DeleteLine.hpp"


DeleteLine::DeleteLine()
{

}


void DeleteLine::execute(EditorModel& model)
{
    prevcolumn = model.cursorColumn();
    prevrow = model.cursorLine();
    prevstr = model.getV()[model.cursorLine() - 1];
    if (model.getV().size() == 1)
    {
        model.getV()[0] = "";
        model.setCol(1);
        model.setRow(1);
    }
    else
    {
        model.DeleteLine();
    }
}


void DeleteLine::undo(EditorModel& model)
{
    model.setRow(prevrow);
    model.setCol(prevcolumn);
    model.getV().insert(model.getV().begin() + model.cursorLine() -1, prevstr);
}