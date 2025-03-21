#include <iostream>
using namespace std;

class Manager {
    private:
        //member variables
         string name;
         float  salary;
         
    public :
          //shared variable
          static int count;
          Manager(){
                name="Taresh Patil";
                salary=56000;
               count++;
          }

          Manager(string nm, float sal){
                name=nm;
                salary=sal;
               count++;
          }
          void display(){
            cout<<"Manager instance "<<name << " salary ="<<salary;

           }
          static int getCount(){
                return count;
          }
};

 int Manager::count=0;

int main()
{
   
    Manager mgr1,mgr56;
    Manager mgr2;
    Manager mgr3;
    Manager mgr4("Rajiv Nene",30000);
    int objectCount=Manager::getCount();
    cout<<"Number of instance of class manager="<<objectCount;

    return  0;
}