#pragma once
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;
class Student : public Person
{
private:
    string studentID;
    double gpa;

public:
    Student();
    Student(string name, int age, string studentID, double gpa);
    void display();
};