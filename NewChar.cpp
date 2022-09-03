#include "NewChar.hpp"


NewChar::NewChar(char c)
    :character{c}
{
}


void NewChar::execute(EditorModel& model)
{
    model.insertChar(character);
}


void NewChar::undo(EditorModel& model)
{
    model.deleteChar();
}