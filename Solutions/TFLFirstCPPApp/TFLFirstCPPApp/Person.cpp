//Base class methods implementation
#include "Person.h"

//default constructor
Person::Person()
{
    name = "Smita Shinde";
    age = 18;
}

//parameterized constructor
Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

//Implementation of Virtual function in cpp file
void Person::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}