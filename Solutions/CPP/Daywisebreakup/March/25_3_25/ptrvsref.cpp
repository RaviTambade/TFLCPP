#include <iostream>
#include <string>
using namespace std;
int main(){

  
    int count=56;
    int * intPtr=NULL;  //pointer variable
    intPtr=&count;      //Pointer is holding address of the variable count
    int & refInt=count;  //reference variable referring  to the variable  count
    cout <<"Initial Level of Programm"<<endl;
    cout<< "Data ="<<count<<endl;
    cout<< "Data pointing by pointer="<<*intPtr<<endl;
    cout<< "Data referenced by  reference ="<<refInt<<endl;
    //intPtr=NULL;  //pointer is not pointing to anything

    cout<<"Assigning another variable "<<endl<<endl;
    int result=90;
    intPtr=&result;   //Bad Practice
                      //It is not good practice to reassign another object to reference
                        //old address is overwritten by new address in pointer
    
    refInt=result;
    cout<< " data pointing by reference :"<<refInt<<endl; 


    //You need to take extra precautions against pointer
    // Dangling pointer issue;
    if(intPtr !=NULL){
        cout<< " data pointing by pointer :"<<*intPtr<<endl; 
    }
    else{
        cout<<"Dangling pointer issue :"<<endl;
    }
}

/*
A reference in C++ is an alias for another variable.
Once a reference is initialized, 
it cannot be reassigned to refer to a different object.
*/