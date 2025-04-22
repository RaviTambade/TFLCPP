#include <iostream>
#include <string>

using namespace std;
int main(){
    int result=90;

    //deep copy
    int marks=result;
    marks++;


    cout<<" result="<<result<<endl;
    cout<<" marks="<<marks<<endl;

    //shallow copy
    int & refResult=result;
    refResult++;
    cout<<" Original result="<<result<<endl;
    cout<<"Reference of result= "<<refResult<<endl;
}