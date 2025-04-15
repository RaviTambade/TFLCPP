#pragma once
#include "Shape.h"

//Clean Code Strategy
//Inheritance
class Circle : public Shape
{
    private:
        int radius = 0;
       
    public:
        //Encapsulation: Hiding data
        int getRadius() { return radius; }
        void setRadius(int radius) { this->radius = radius; }
        
        Circle();   //default constructor
        Circle(int radius) { this->radius = radius; } //parameterized constructor
        
        //Camel casing namming convention
        float calculateArea() { return pi * radius * radius; }
        void display();

        friend void getradius(Circle& r);  //Friend class
        ~Circle(){}; 
};



