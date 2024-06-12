#pragma once
// 3:Create a abstract class Shape with pure virtual method area;
// Create Rectangle,Circle,Square class..inherit them from Shape class..Override
// area method. Test these all classes by creating object of respective class.

#include <iostream>
using namespace std;

static const double pi = 3.14;

//Major Object Oriented Programming
//1.Abstraction
//2.Inheritance & Polymorphsim
//3.Encapsulation

//Abstraction
//abstract class
//Minimum condition: minimum one method should be astract (pure virutal function)


//Classes are of two types
//Concrete class  : the class fromwhich we can instantiate object
//Abstract class  : the class fromwhich we can not create object

//Abstract classes are used for Polymorphism point of view

class Shape
{
    public:
        virtual float CalculateArea() = 0;   //pure virtual
        // Data member in pure virtual function which is an
        // abstract function should be the same as the data
        // member in the child class as it must be overriden.


    //Rule: each method declared pure virutal function should be overrided in child classes
};

//Extend key word is used in java for extending parent class to derived class 














