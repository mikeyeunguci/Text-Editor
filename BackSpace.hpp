#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP
#include "Command.hpp"
#include <vector>
#include <string>


class BackSpace : public Command
{
public:
    BackSpace();
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
private:
    unsigned int prevcolumn;
    unsigned int prevrow;
    char undochar;
    std::string reAdd;
    std::string prevstring;
    bool boolUndoChar;
};

#endif