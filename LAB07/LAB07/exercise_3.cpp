#include "TextEditor.cpp"
#include <iostream>
using namespace std;

int main()
{
    TextEditor texts;
    LineType* current;
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    texts.InsertLine("Hello");
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    texts.InsertLine("World!");
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    texts.GoToTopC();
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    texts.GoToBottomC();
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    texts.GoToTopD();
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    texts.GoToBottomD();
    current = texts.GetCurrentLine();
    cout << current->line << endl;
    return 0;
}
