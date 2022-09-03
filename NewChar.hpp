#ifndef NEWCHAR_HPP
#define NEWCHAR_HPP
#include "Command.hpp"
#include <string>

class NewChar : public Command
{
public:
    NewChar(char c);
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    char character;
};

#endif
