#include <iostream>
#include <string>
using namespace std;
 //Pure :Object Oriented Programming language
// 1. Abstraction
// 2. Encapsulation
// 3. Inheritance 

    //Encapsulation: Hiding data by defining using private keyword
class Person{
    private :
        int id;
        string firstName;
        string lastName;
        int age;
    public:

        //Private Variables can be accessed only throgh  public member functions

                Person(){
                    cout<<"Constructor is called"<<endl;
                    id=11;
                    firstName="Ravi";
                    lastName="Tambade";
                    age=49;
                }

                Person(int i, string fName, string lName,int ag){
                    cout<<" Parameterized Constructor is called"<<endl;
                    id=i;
                    firstName=fName;
                    lastName=lName;
                    age=ag;
                 
                } 

                //friend keyword violte the rule of encpsualtion
                //C++ is  not Pure Object Oriented Programming language
                friend  void display(Person  thePerson);
};
 

//Implementation of function declared in class is outside of class

void display(Person  thePerson){
    cout<<thePerson.firstName<< "" <<thePerson.lastName <<endl;
}

int main(){

    Person p1;
    Person p2(45,"Sarthak", "Kadam",22);
    Person p3(65, "Sanika", "Kulkarni",21);
    display(p1);

 
    return 0;
}

/*



*/