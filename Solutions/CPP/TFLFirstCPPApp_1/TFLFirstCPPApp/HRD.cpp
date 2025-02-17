/*
Title - Transflower :Human Resource Department Employee Management System
	Company maintains employee information  as employee ID, name, designation, and salary.
	I.Allow user to add, delete information of employee. 
	II.Display information of particular employee. 
	III.If employee does not exist an appropriate message is displayed.
	IV. If it is, then the system displays the employee details. 
	Hint:Use index sequential file to maintain the data.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class Employee {
private:
	int code;
	char name[20];
	float salary;
public:
	void read();
	void display();
	int getEmployeeCode() { return code; }
	float getSalary() { return salary; }
	void updateSalary(float s) { salary = s; }
	void appendToFile();
	void searchForRecord();
	void increaseSalary();
	void insertRecord();
};
void Employee::read() {


}
void Employee::display() {


}
void Employee::appendToFile() {

}
void Employee::searchForRecord() {

}
void Employee::increaseSalary() {

}
void Employee::insertRecord() {

}

//Entry Point Main function
/*(int main() {
	cout << "Welcome to Transflower Human Resource Department";
	return 1;
}*/
