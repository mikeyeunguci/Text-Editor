// EditorModel.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <iostream> //debug


EditorModel::EditorModel()
    :row{1}, column{1}
{
    v.push_back("");
}


int EditorModel::cursorLine() const
{
    return row;
}


int EditorModel::cursorColumn() const
{
    return column;
}


int EditorModel::lineCount() const
{
    return v.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return v[lineNumber-1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    this->errorMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    this->errorMessage = "";
}


std::vector<std::string>& EditorModel::getV()
{
    return v;
}


void EditorModel::setCol(unsigned int col_)
{
    column = col_;
}


void EditorModel::setRow(unsigned int row_)
{
    row = row_;
}


void EditorModel::insertChar(char c)
{
    v[row-1].insert(column-1, 1, c);
    column +=1;
}

void EditorModel::deleteChar()
{
    column -=1;
    v[row-1].erase(column-1, 1);
}

bool EditorModel::CursorAtEnd()
{
    if (column > v[row-1].size())
    {
        return true;
    }
    return false;
}


void EditorModel::newLine()
{
    if (CursorAtEnd() == true)
    {
        v.insert(v.begin() + row, "");
        column = 1;
        row += 1;
        return;
    }
    std::string toMove = v[row-1].substr(column-1);
    v[row-1].erase(column-1);
    v.insert(v.begin() + row, toMove);
    column = 1;
    row += 1;
}


void EditorModel::undoNewLine()
{
    std::string reAdd = v[row-1];
    v.erase(v.begin() + row-1);
    row -= 1;
    column = v[row-1].size() + 1;
    v[row-1].append(reAdd);
}


void EditorModel::DeleteLine()
{
    v.erase(v.begin() + row-1);
    if (row > v.size())
    {
        row -= 1;
    }
    if (column > v[row-1].size() + 1)
    {
        column = v[row-1].size() + 1;
    }
}