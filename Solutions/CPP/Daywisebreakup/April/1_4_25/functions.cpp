#include <iostream>
using namespace std;

//global scope
string printerTitle;


void print(){
    //short term memory variables
    string name;
    printerTitle="Laserjet Printer";
    cout<<"Printing on screen"<<endl;
    name="Tranflower";
}


int  main(){
    printerTitle="Inkjet Printer";
    print();
    cout<<name<<endl;
    cout<<printerTitle <<endl;
}