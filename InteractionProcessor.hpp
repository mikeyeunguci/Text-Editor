// InteractionProcessor.hpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// The job of an InteractionProcessor is to wait for interactions (e.g., the
// user pressing keys on the keyboard) and then to make the appropriate changes
// on the EditorModel and EditorView as a result.
//
// Do not change or remove the signatures of the public member functions
// that have been declared here, since they are called in other parts
// of BooEdit that you won't be working on.  You do have the freedom
// to add anything else to this class (additional member variables or
// member functions) that you'd like -- though my own solution didn't
// have anything else.

#ifndef INTERACTIONPROCESSOR_HPP
#define INTERACTIONPROCESSOR_HPP

#include "EditorModel.hpp"
#include "EditorView.hpp"
#include "InteractionReader.hpp"
#include <vector>



class InteractionProcessor
{
public:
    InteractionProcessor(
        EditorModel& model, EditorView& view,
        InteractionReader& interactionReader)
        : model{model}, view{view}, interactionReader{interactionReader}
    {
        std::vector<Command*> Undo;
        UndoStack = Undo;
        std::vector<Command*> Redo;
        RedoStack = Redo;
    }

    void run();

private:
    EditorModel& model;
    EditorView& view;
    InteractionReader& interactionReader;
    std::vector<Command*> UndoStack;
    std::vector<Command*> RedoStack;
};



#endif

