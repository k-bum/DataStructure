#ifndef TextEditor_hpp
#define TextEditor_hpp

struct LineType;

class TextEditor
{
public:
    TextEditor();
    void GoToTopC();
    void GoToBottomC();
    void GoToTopD();
    void GoToBottomD();
    void InsertLine(const char* newline);
    LineType* GetCurrentLine() const;
    
private:
    LineType* header;
    LineType* trailer;
    LineType* currentLine;
};

#endif
