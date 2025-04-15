#include <iostream>
using namespace  std;
//object oriented programming
//Method overridding : 
//is possible only through inheritance
//Inheritance is implmented through child parent class hiearchy

//we need to establish relation between two classes:
// 1. Association----------------has a  relationship
// 2. Inheritance----------------is a relationship

/*

Inheritance: 
Manager inherits from Employee, reusing its functionality and adding its own.

Method Overriding: The Manager class overrides the ComputePay() method to calculate the manager's pay differently (with a bonus).

Polymorphism: We use a virtual method (ComputePay) in the base class, which is overridden in the derived class.
 When we call ComputePay() on an object, 
 the appropriate version of the function is invoked depending on the object's type 
 (i.e., Employee or Manager).


*/


/*
In C++, inheritance allows you to create a base class that contains common functionality and then 
create derived classes that extend or modify this functionality. 

In this example, we'll create an Employee class and a Manager class, 
where the Manager class inherits from Employee and overrides or extends the behavior of the ComputePay method.

*/

//Base Class
class Employee {
	protected:
		string name;
		double basicSalary;
		int workingDays;
		double dailyAllowance;
	public:
		  Employee(string empName, double empSalary, int days, double da){
		  	this->name=empName;
		  	this->basicSalary=empSalary;
		  	this->dailyAllowance=da;
		  	this->workingDays=days;
		  }
		  
		  virtual double ComputePay(){
		  	cout<<"\n Employee ComputePay is called...";
		  	double package=basicSalary + (workingDays * dailyAllowance);
		  	return package;
		  }
};

//Derived Class
class Manager:public Employee {
	
	private: 
			double bonus;
			
	public:
		    //Member Initialized List
			Manager(string mgrName, double mgrBasicSalary, int days, double da, double incentive):Employee(mgrName,mgrBasicSalary,days, da){	
				this->bonus=incentive;	
			}
						
			//Method overrriding :Changing the behavious of parent class method in derived class
			  double  ComputePay()  override {
			  	cout<<"\n Manager ComputePay is called...";
			 	double package=basicSalary + (workingDays * dailyAllowance) + bonus;
			 	return package;
			}
};
 
 
int main(){

	Employee emp1("Sachin Pande",15000,25,500);
	double result=emp1.ComputePay();
	cout<< "\n Employee Salary="<<result;
	
	Manager mgr1= Manager("Seeta Kumari",23000, 25, 1000,3000);
	double mgrResult=mgr1.ComputePay();
	cout<< "\n Manager Salary="<<mgrResult;
	
	Employee *pEmployee = new Manager("Chadra Babu",33000, 20, 1500,8000);
	//Polymorphism: invoking the behaviour of  overriable method which belong to class , whose object is created.
	double mgr2Salary=pEmployee->ComputePay();   // it invokes the method belong to the class whose objects is created.
	cout<< "\n Manager2 Salary="<<mgr2Salary;
}
