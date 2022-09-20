#include "texteditor.h"
#include <iostream>
using namespace std;


// Default constructor 
TextEditor::TextEditor()
{
    BufferType(); //By calling BufferType, call default constructor of doublylinked list
    pos = buffer.Begin();   //Set BufferType::Iterator pos as buffer.Begin()
    currLine = 0;   //initialize int currLine as 0
}

TextEditor::~TextEditor()
{
    
    for(BufferType::Iterator it = buffer.Begin(); it!= buffer.End(); it++)  //traverse from begin to end of the buffer.pos and simultaneously delete.
    {
        Delete();
    }
    currLine = 0;   //initialize currLine as 0
}

// Insert a new line after the current position
void TextEditor::Insert(const char* s)
{
    buffer.InsertNext(pos, s); //By using DL's InsertNext function, insert s next to the position.
    pos++;  //After storage, increase iterator by 1. So that newly inserted line becomes currLine.
    currLine += 1;  //Same as the currLine.
}

// Delete the current line
void TextEditor::Delete()
{
    if(buffer.Size() < 1) { //if the buffer's node is under 1, it should warn that buffer is empty.
        std::cout << "Buffer is empty" << std::endl;
    }
    else
    {
        buffer.DeleteNode(pos); //delete current node.
        if(++pos == buffer.End())   //if next to current is end then it should decrease iterator's position and also currLine too.
        {
            --pos;
            currLine -= 1;
        }
    }
}

// Move one line up
void TextEditor::MoveUp()
{
    // ToDo
    if(pos-- == buffer.Begin()) // if pos-- is begin then it should warn that it is the beginning of the buffer.
    {
        cout << "Beginning of the buffer" << endl;
        ++pos;  //as the iterator's before value doesn't exist, it should increase the pos of iterator by 1.
    }
    else
        currLine -= 1;  //as it moved up, currLine should be decreased by 1.
}

// Move one line down
void TextEditor::MoveDown()
{
    // ToDo
    if(++pos == buffer.End())   //if ++pos is the end then it should warn it is the end of the buffer.
    {
        cout << "End of the buffer" << endl;
        --pos;  //as the iterator's next value doesn't exist, it should decrease the pos of iterator by 1.
    }
    else
        currLine += 1;  //as it moved down, currLine should be increased by 1.
}

//
// Interactive mode
//
void TextEditor::Run()
{
    string inp;
    
    while(1)
    {
        cout << "> ";
        getline(cin, inp);
        
        // ToDo	- implement other functions
        
        if(inp == "u") MoveUp();
        else if(inp == "x") exit(0);
        else if(inp == "d") MoveDown();
        else if(inp == "p") Print();
        else if(inp == "pa") PrintAll();
        else if(inp == "r") Delete();
        else if(inp == "i")
        {
            char input[100];    //declare the insertion values' array's largest size.
            cout << "(Insert) > ";
            cin.getline(input, 100);    //size becomes same with input's size.
            char* j = input;    //In cin.getline, input should be pointer of char.
            Insert(j);  //insert next to the current position.
        }
        else
        {
            cout << "No such command. Available commands are u(up), d(down), p(print), pa(print all), r (delete), i(insert), and x(exit)" << endl;
        }
    }
}


// ----------------------

// Print the current line with the line number
void TextEditor::Print()
{
    if(buffer.Size() < 1) {
        std::cout << "Buffer is empty" << std::endl;
    }
    else {
        std::cout << "Current(L" << currLine << ") : " << *pos << std::endl;
    }
}

// Print all with the line number
void TextEditor::PrintAll()
{
    int i=1;
    for(BufferType::Iterator it=buffer.Begin(); it != buffer.End(); it++)
    {
        cout << "L" << i++ << " :";
        if(i == (currLine+1)) cout << "*";
        else cout << " ";
        cout << *it << endl;
    }
}
