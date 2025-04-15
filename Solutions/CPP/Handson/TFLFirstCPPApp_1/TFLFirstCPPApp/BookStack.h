#pragma once
#define MAX 5               //Macro   : constant definition 
#define PI 3.14
#define BOTTOM -1

//Content
//          Header
//          Body

// Declaration of Class
class BookStack
{
        //Member variables
    private:
        int books[MAX];
        int top;  //index 

        //Member functions
    public:
        //Camelcasing notation
        BookStack();        //constructor:the function is called once object is created and to be initialized
        bool IsFull();
        bool IsEmpty();
        void Push(int bookId);
        int  Pop();
        void Print();
        ~BookStack() {  }   //destructor: the function is called before object is getting removed  
};

//Separation of Concern
