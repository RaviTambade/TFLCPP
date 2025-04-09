//Programming Language:
//  C, C++ ,C#
//  java, python, dart, javascript

//Execution: Runtime ( computational resources)
//Hardware: CPU, RAM, Hard disk, Monitor, keyboard, mouse
//Software: Operating System (Linux, Windows, Mac OS,  Unix, etc)
//Application Software: commerce application  exe file


//At the time exection :
// Process:
//          a program under exeuction
//          consist of  heap, stack and thread

//Thread: small unit of exeuction
//        a path of execution

//Primary Thread:primary thread invokes main function

// Language  C/C++  ------Source Code---.c or .cpp ( C++ 14)
// Build tool: gcc/ g++, turbo c, borland C, (MingW- 64)
//             compiler, linker
// Node js , JRE, .NET, Python, Go  native --------Runtime

//Exeuction:
//Concurrency:

//sequential exeuction------parallel execution
//                          (concurrent execution)
//blocking call -- nonblocking call
//sync call ----------async call

//
// Topic: Asynchronous PRogramming
//Multithreading:
//Multitasking


//online shopping Aplication:(Application Software)
// shopping cart
// wishlist
// product catalog 
// order processing
// product search
// orgranizing products according price, category, likes
// orderhisotry
// online payment
// view reviews against product 

#include <iostream>
using namespace std;

enum ecommerceOption { browse, addItem, removeItem, placeOrder, cancelOrder, payAmount, trackOrder};
 
//Product Search Task
void search(){

    cout<< "Specific Product has been searched from Avaialble Product Catalog"<<endl;

}

//product sort Task
void sort(){
    cout<< "All products have been sorted in ascending order based on sale"<<endl;
}

//Shopping Cart insertion Task
void addToCart(){
    cout<< "New Item is added to existing Shopping Cart"<<endl;
}

//Shopping Cart remove item Task
void removeFromCart(){
    cout<< "Item is removed from shopping Cart"<<endl;
}

void processOrder(){
    // complex logic for  order placement
    cout<< "Thank you for successful payment. Your order has been confirmed."<<endl;
}

void trackDelivery(){
    cout<< "Your Parcel has been dispatched and it is on the way"<<endl;
}


//Flow: (Standard Protcol)
//College Addmission Process  (sequential , blocking, synchrnous )
//1.Fill Application Form
//2.Upload all essential documents 
//3.Submit Form
//4.Verify Application form content
//5.Perform Payment 
//6.Reciive challan
//7.confirm admissiion
//8.Id card issued
//10.Welcome to College as student



//Single Threaded Application
//Sequential Exeuction Application
//Application consist of  Blocking Calls
//Synchronous Call (Exeuction)

//Multiple tasks are exeucted one after the another by Primary Thread
//entry point (main task)



int main(){
    ecommerceOption shoppoingStatus;
    cout<< "Welcome to Transflower"<<endl;
    sort();
    ecommerceOption  shoppoingStatus=addItem;
    //due to some processing



    //conditional sequencing execution

    switch(shoppoingStatus)
    {

        case  browse:
                sort();
                search();
        break;

        case addItem:
                addToCart();
        break; 

        case removeItem:
                removeFromCart();
        break; 
        
        case  placeOrder:
                processOrder();
        break;
    
        case trackOrder:
                trackDelivery();
        break;
  
    cout<<"Thank you for  purchase product online from our TFL Store"<<endl;
}