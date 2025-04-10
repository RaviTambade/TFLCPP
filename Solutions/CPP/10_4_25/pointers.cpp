#include<iostream>
using namespace std;
int main() {

    int count =890;
   int *   const  ptr =&count;
    cout<<"Data= "<<*ptr<<endl;
    int result=98;
    
    //read only pointer
    //ptr=&result;   //You can not reassign another address to same pointer
    cout<<"Data= "<<*ptr<<endl;

    //Pointers
    int amount=678;
    int *pLocation1=&amount;
    int *pLocation2=&amount;

    cout<<*pLocation1<<endl;
    cout<<*pLocation2<<endl;
    
    //shallow copy
    //Same location is shared with each pointer
    *pLocation1=9000;

    cout<<*pLocation1<<endl;
    cout<<*pLocation2<<endl;


    //Refernce

    //Deep Copy
    //replica is created for each reference
    string  user="ravi tambade";
    string user1=user;
    string user2=user;

    cout<<user1<<endl;
    cout<<user2<<endl;

    user2="Sarthak Kadam";

    cout<<user1<<endl;
    cout<<user2<<endl;

}