
//standard library for I/O operations
//it consist of standard input-output stream
//components:
//1. istream ( for input operations)
//2. ostream ( for output operations)

//stream
// flow of information (data)
// input----->>application---->>output----
// user----->>input >> application---does processing
#include <iostream> 
using namespace std;
int main(){
    int number=678;

    //Opertors: +, -, *, / arithmatic operators
    // insertion operator  >>
    // extraction operator <<
    
    cout<<"Enter  one number :"<<endl;
    cin>>number;
    //Logic
    number=number +1;
     
    //output
    cout<<"Result="<<number<<endl;
    return 0;
}