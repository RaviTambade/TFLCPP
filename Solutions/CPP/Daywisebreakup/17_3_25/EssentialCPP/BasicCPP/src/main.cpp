#include <iostream>
#include "data.h"


//declaration of function or variable ---- header file
//implementation of function ------------- c or cpp file
using namespace std;
int main(){
    initialize();
    cout<<" Welcome to C++"<<endl;
    return 0;
}


//g++ -I include  ./src/data.cpp ./src/main.cpp -o ./build/test.exe