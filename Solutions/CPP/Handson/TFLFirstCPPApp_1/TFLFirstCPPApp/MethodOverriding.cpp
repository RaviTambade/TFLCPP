// Problem Statement: Model a system for handling individuals and students within 
// an educational institution. Create a base class Person with attributes like name 
// and age. Derive a Student class with additional attributes like student ID and GPA,
// inheriting the common attributes from the Person class.

/*#include <iostream>
#include <string>
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


//Derived class: student
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



//Base class methods implementation
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



//derived class methods implementation
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
*/


/*
int main()
{
    //base class object
    Person person("sanika",19 );
    cout << "Person Details:" << endl;
    person.display();
    cout << endl;

    //Derived class object 
    Student student("sumit", 18, "031", 9.8);
    cout << "Student Details:" << endl;
    Student student2("sanika", 18, "031", 9.8);
    student.display();
    student2.display();

    return 0;
}
*/
