#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class Person{
    private:
            int id;
            char * ptrName;
            int age;
    public :

            //1.default constructor
            Person(){
                id=34;
                int size= sizeof(char) * 12;
                ptrName=new char[size];
                strcpy( this->ptrName, "Chiranjivi");
                age=53;
            }

            //2.Parameterized Constructor
            Person(int i, char * ptrNm, int a){
                id=i;
                int length=strlen(ptrNm);
                int size= sizeof(char) * length;
                ptrName=new char[strlen(ptrNm)+1];
                strcpy( this->ptrName, ptrNm);
                age=a;
            }

            //3.Copy Constructor
            Person(const Person& other){
                this->id=other.id;
                this->age=other.age;
                ptrName=new char[strlen(other.ptrName)+1];
                strcpy( this->ptrName, other.ptrName);
            }

            void setName(char * pName){
                ptrName=pName;
            }   

            char * getName(){
                return ptrName;
            }

            friend  istream&  operator>>(istream& is,   Person& prn)
            {
                cout << "Person Detail Accept from EndUser :"<<endl;
                cout<<"Enter your name:  ";
                is >> prn.ptrName ;
                cout<<endl <<"Enter your are:  ";
                is >> prn.age;
                return is;
            }  
            
            friend  ostream&  operator<<(ostream& os, const Person& prn)
            {
                os<<"Person object: "<<prn.ptrName << " Age: "<<prn.age << endl;
                return os;
            }

            

            //In C malloc and free are functions for 
            //dynamic memory allocation
            //In C++ new and delete are operators for 
            //dynamic memory allocation
            ~Person(){
                if(ptrName != NULL){
                    delete [] ptrName;
                }
            }

        };


int main (){

    Person p1;
    char name[12];
    strcpy( name, "Shiv Kumar");

    Person p2(34, name,23);

    //Creating object using Copy Constructor

    Person p3(p2);

    cout<<p1<<endl;
    cout<<"P2 "<<p2<<endl;
    cout<<"P3 "<<p3<<endl;

    cout<<"After setting ......"<<endl;
    char anotherName[12];
    strcpy( anotherName, "Raj Kapoor");

    p3.setName(anotherName);
    cout<<"P2 "<<p2<<endl;
    cout<<"P3 "<<p3<<endl;
}