#include <iostream>
#include <string>

using namespace std;

namespace HR 
{
    class Person{
        //consist of members
        
        private :
                int id;
                string firstName;
                string lastName;
                int age;

        public:
                void setAge(int a){
                    age=a;
                }

                int getAge(){
                    return age;
                }

                //constructor is automatically called  after object constructed in memory
               
               //constructor overloading
                Person(){
                    id=11;
                    firstName="Ravi";
                    lastName="Tambade";
                    age=49;
                }

                //constructor overloading
                Person(int i, string fName, string lName,int ag){
                    cout<<" Parameterized Constructor is called"<<endl;
                    id=i;
                    firstName=fName;
                    lastName=lName;
                    age=ag;
                   
                }
    
                ~Person(){
                    cout<<"Destructor is called"<<endl;
                    //It is automatically called to deinitialize resources 
                    //before object getting destroyed from memory

                }
            
                
                //Function overloading (Method overloading)
                //static polymorphism

                void showDetails()  const {
                    cout<< "Default screen Output"<<endl;
                    cout<<firstName <<"  "<<lastName<<endl;
                }

                void showDetails(string device) const{
                    cout<< "Printer Output"<<endl;
                    cout<<firstName <<"  "<<lastName<<endl;
                }
            };

    class Employee{

        private:
                int employeeNumber;
                double basicSalary;
                double dailyAllowance;
                double providentFund;
                double hra;          
    };

    class Manager{

        private:
                string department;
                float incentive;

    };

}

using namespace HR;

int main(){

    cout<< "HR System";
    Person p1;
    Person p2(34, "Rajiv", "Patil", 35);

    Employee emp1;
    Employee emp2;

}