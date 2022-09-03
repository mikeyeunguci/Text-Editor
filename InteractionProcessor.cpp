// InteractionProcessor.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <iostream> // debug


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for (unsigned int i = 0; i < UndoStack.size(); i++)
            {
                Command* command = UndoStack[i];
                delete command;
            }
            
            for (unsigned int i = 0; i < RedoStack.size(); i++)
            {
                Command* command = RedoStack[i];
                delete command;
            }
            
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (UndoStack.size() == 0)
            {
                continue;
            }
            Command* command = UndoStack.back();
            UndoStack.pop_back();
            command->undo(model);
            RedoStack.push_back(command);
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (RedoStack.size() == 0)
            {
                continue;
            }
            Command* command = RedoStack.back();
            RedoStack.pop_back();   
            command->execute(model);
            UndoStack.push_back(command);
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                UndoStack.push_back(command);
                model.clearErrorMessage();
                for (unsigned int i = 0; i < RedoStack.size(); i++)
                {
                    Command* command = RedoStack[i];
                    delete command;
                }
                RedoStack.clear();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            
        }
    }
}

