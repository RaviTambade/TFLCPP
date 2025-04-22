#include <iostream>
#include <string>
using namespace std;

namespace HR{

    //namespace:logical collection of classes
    //classes are defined to create more than objects
    //class act Like blue print

    class Person{
        //consist of members

        public :
                int id;
                string firstName;
                string lastName;
                int age;
                //constant variables are declared and initialized at same place.
                const string nationality="Indian";

                Person(){
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
    
                ~Person(){
                    cout<<"Destructor is called"<<endl;
                }
            
                //Constant Functions are read only functions
                //you can not manipulate interal data of an object
                void showDetails()  const {
                    //firstName="Reena";
                    cout<<firstName <<"  "<<lastName<<endl;
                }
            };
        }

using namespace HR;

int main(){

    //constant variables can be only initalized once.
    //constant variables can not be changed throughout application exeuction
    const int result=56;
    //result=result+100;    //Not allowed by compiler
    Person p1;
    p1.showDetails();
}