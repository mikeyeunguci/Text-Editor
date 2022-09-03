// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "NewChar.hpp"
#include "NewLine.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "CursorEnd.hpp"
#include "CursorHome.hpp"
#include "BackSpace.hpp"
#include "DeleteLine.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
            {
                return Interaction::quit();
            }
            case 'Z':
            {
                return Interaction::undo();
            }
            case 'A':
            {
                return Interaction::redo();
            }
            case 'O':
            {
                CursorRight* CursorRightobj = new CursorRight;
                return Interaction::command(CursorRightobj);
            }
            case 'U':
            {
                CursorLeft* CursorLeftobj = new CursorLeft;
                return Interaction::command(CursorLeftobj);
            }
            case 'J':
            {
                NewLine* NewLineobj = new NewLine;
                return Interaction::command(NewLineobj);
            }
            case 'M':
            {
                NewLine* NewLineobj = new NewLine;
                return Interaction::command(NewLineobj);
            }
            case 'I':
            {
                CursorUp* CursorUpobj = new CursorUp;
                return Interaction::command(CursorUpobj);
            }
            case 'K':
            {
                CursorDown* CursorDownobj = new CursorDown;
                return Interaction::command(CursorDownobj);   
            }
            case 'Y':
            {
                CursorHome* CursorHomeobj = new CursorHome;
                return Interaction::command(CursorHomeobj);
            }
            case 'P':
            {
                CursorEnd* CursorEndobj = new CursorEnd;
                return Interaction::command(CursorEndobj);
            }
            case 'H':
            {
                BackSpace* BackSpaceobj = new BackSpace;
                return Interaction::command(BackSpaceobj);
            }
            case 'D':
            {
                DeleteLine * DeleteLineobj = new DeleteLine;
                return Interaction::command(DeleteLineobj);
            }

            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            NewChar* NewCharobj = new NewChar(keypress.code());
            return Interaction::command(NewCharobj);
        }
    }
}

