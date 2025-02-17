#include "EnggStudent.h"


//MemberInitialized List :
// 
//Current class constructor calls internally Parent class constructor
//It provided chaining effect

EnggStudent::EnggStudent():Student(){

    year = 1;
    branch = "IT";
}
EnggStudent::EnggStudent(string name, int age, string studentID, 
						 double gpa, string b, int y)
            :Student(name,age, studentID,gpa){

    year =y;
    branch = b;
}

  
void EnggStudent::display()
{
    Student::display();
    cout << "Year: " << year << endl;
    cout << "Branch: " << branch << endl;
}
