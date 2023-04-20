#include "TextEditor.hpp"
#include <cstddef>
#include <new>
#include <iostream>
using namespace std;

struct LineType
{
    char line[80];
    LineType* next;
    LineType* back;
};

TextEditor::TextEditor()  // Class constructor
{
    strcpy(header->line, "---Top of file---");
    strcpy(trailer->line, "---Bottom of file---");
    header->next = trailer;
    header->back = NULL;
    trailer->next = NULL;
    trailer->back = header;
    currentLine = header;
}

// Big-O notation : O(N)
void TextEditor::GoToTopC()
{
    while(currentLine->back != NULL)
    {
        currentLine = currentLine->back;
    }
    currentLine = currentLine->next;
}

void TextEditor::GoToBottomC()
{
    while(currentLine->next != NULL)
    {
        currentLine = currentLine->next;
    }
    currentLine = currentLine->back;
}

// Big-O notation : O(1)
void TextEditor::GoToTopD()
{
    currentLine = header->next;
}

void TextEditor::GoToBottomD()
{
    currentLine = trailer->back;
}

void TextEditor::InsertLine(const char* newLine)
{
    LineType *newNode = new LineType;
    strcpy(newNode->line, newLine);
    if(currentLine->next != NULL)
    {
        newNode->back = currentLine;
        newNode->next = currentLine->next;
        (currentLine->next)->back = newNode;
        currentLine->next= newNode;
    }
    else
    {
        newNode->next = currentLine;
        newNode->back = currentLine->back;
        (currentLine->back)->next = newNode;
        currentLine->back = newNode;
    }
    currentLine = newNode;
}

LineType* TextEditor::GetCurrentLine() const
{
    return currentLine;
}

