#ifndef DELETELINE_HPP
#define DELETELINE_HPP
#include "Command.hpp"
#include <vector>
#include <string>

class DeleteLine : public Command
{
public:
    DeleteLine();
    void execute(EditorModel& model);
    void undo(EditorModel& model);
private:
    unsigned int prevcolumn;
    unsigned int prevrow;
    std::string prevstr;
};

#endif