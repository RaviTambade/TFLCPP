#pragma once
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

//Base class: person
class Person
{
protected:
    string name;
    int age;

public:
    Person();
    Person(string name, int age);
    virtual void display();
};
