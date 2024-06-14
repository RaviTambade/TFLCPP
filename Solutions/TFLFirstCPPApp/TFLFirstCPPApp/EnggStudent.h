#pragma once
 
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;


//Bottom Class
//Multi level Inheriance
//Leve1: Person, Level2: Student, Level3:EnggStudent

//class Hierchy:
// Person---Student--EnggStudent----->
// 
//Grand Child Class
class EnggStudent : public Student
{
private:
    string branch;
    int year;

public:

    EnggStudent();
    EnggStudent(string name, int age, string studentID, double gpa, string b, int y);
    virtual void display();
};