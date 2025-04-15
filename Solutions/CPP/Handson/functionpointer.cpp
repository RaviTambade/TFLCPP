#include <iostream>
using namespace std;
//listener
//receiver
//handler
//callback
int add(int a, int b) {
    return a + b;
}

//callback 
int mult(int a, int b) {
    return a * b;
}

//declare function pointer 
int (*ptrfn) (int, int);

int main (){
   
    //int result = add(5, 3);  // direct call, early binding of function
    ptrfn=mult;
    int result=ptrfn(87,56);  //call pointer to function
                              //indirect call
    cout<<"Result ="<<result<<endl;
}