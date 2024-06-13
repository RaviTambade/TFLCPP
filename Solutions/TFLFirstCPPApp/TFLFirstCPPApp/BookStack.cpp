//Implementation of Class
#include "BookStack.h"
#include<stdio.h>           //Header files // System
#include <iostream>         //System.IO

using namespace std;

BookStack::BookStack()
{
    top = BOTTOM;
}

bool BookStack::IsFull()
{
    bool status = false;
    if (top == MAX - 1)
    {
        status = true;
    }
     return status;
}

bool BookStack::IsEmpty()
{
    bool status = false;
    if (top == BOTTOM)
    {
        status = true;
    }
    return status;
}

void BookStack::Push(int bookId)
{
    top = top + 1;
    books[top] = bookId;
}

int BookStack::Pop()
{
    int bookIdTop = 0;
    if (!IsEmpty()) {
         bookIdTop = books[top];
        top = top - 1;
    }
    return bookIdTop;
}

void BookStack::Print()
{
    if (!IsEmpty())
    {
        cout << "\n Printing all Book Ids:  ";
        for (int i = top; i >= 0; i--)
        {
            cout << "\n" << books[i];
        } 
    }
    else
    {
        cout << "\n Book Stack is empty";
    }
}

