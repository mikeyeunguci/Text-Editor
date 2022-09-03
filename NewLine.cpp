#include "NewLine.hpp"


NewLine::NewLine()
{
}


void NewLine::execute(EditorModel& model)
{
    model.newLine();
}


void NewLine::undo(EditorModel& model)
{
    model.undoNewLine();
}