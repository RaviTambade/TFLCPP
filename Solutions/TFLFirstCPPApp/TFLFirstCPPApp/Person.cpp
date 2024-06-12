//Base class methods implementation
#include "Person.h"
Person::Person()
{
    name = "John Doe";
    age = 0;
}

Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

void Person::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}