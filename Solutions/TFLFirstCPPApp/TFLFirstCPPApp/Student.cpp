#include "Student.h"


Student::Student() : Person()
{
    studentID = "0000";
    gpa = 0.0;
}

Student::Student(string name, int age, string studentID, double gpa)
    : Person(name, age)
{
    this->studentID = studentID;
    this->gpa = gpa;
}
void Student::display()
{
    Person::display();
    cout << "Student ID: " << studentID << endl;
    cout << "GPA: " << gpa << endl;
}