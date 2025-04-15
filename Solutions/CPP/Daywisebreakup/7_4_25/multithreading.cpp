#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//indepedent Task

//Product Search Task
void choose(){

    this_thread::sleep_for(chrono::seconds(6));
    cout<< "Specific Product has been searched from Avaialble Product Catalog"<<endl;
}

//product sort Task
void sort(){
    cout<< "All products have been sorted in ascending order based on sale"<<endl;
}

//Shopping Cart insertion Task
void addToCart(){


    this_thread::sleep_for(chrono::seconds(3));
    cout<< "New Item is added to existing Shopping Cart"<<endl;
}

//Shopping Cart remove item Task
void removeFromCart(){
    cout<< "Item is removed from shopping Cart"<<endl;
}

void placeOrder(){
    // complex logic for  order placement
    cout<< "Thank you for successful payment. Your order has been confirmed."<<endl;
}

void trackOrder(){
    cout<< "Your order has been dispatched and it is on the way"<<endl;
}

//Multithreaded Application

//Primary Thread
// 2 secondary Thrreads
int main(){

    cout<<"Primary Thread executing  main code"<<endl;
    //Create secondary Threads

    //register choose function with tSearch Thread
    //data types:
    //primitive data types:
        //built in data types:int, float, double, char, bool, enum, decimal, etc.
    //user defined data types:
        //custom data types:
        //struct
        //class

    int count=23;
    //object
    string name="Raj";
    bool status=false;

    //parameterized constructor of thread class
    //exe file consist of data segment and code segment
    //we always pass address(code segment address) of a function
    //thread always take input as address of a function
    //Each thread while creating expects function pointer
    //Thread can not exist without call

    //choose();
    //Indirect call
    thread tSearch(choose);
    //register addToCart function with tcart Thread

    thread tcart(addToCart);

    //allow all secondary Threads to join with main primary Thread
    tSearch.join();
    tcart.join();
    cout<<"Primary Thread is about to terminate"<<endl;
    return 0;

}

