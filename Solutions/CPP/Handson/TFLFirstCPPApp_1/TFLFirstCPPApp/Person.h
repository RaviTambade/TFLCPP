#pragma once
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;


// Classes can be concrete or abstract
// 


//Base class: person
// Concrete Class:
//                  The class from which we can create object

//Top most Class
class Person
{
    protected:
        string name;
        int age;

    public:
        //Person class does not contain all methods as pure virutal functions

        Person();
        Person(string name, int age);
        virtual void display();     //virtual function always has implementation
};



//What is the difference between virtual and pure virtual function
//virtual function has implementation
//pure virtual funcdtion does not have implementation
//the class which have pure virtual function, it's child class has to implement that function in it
//implementation