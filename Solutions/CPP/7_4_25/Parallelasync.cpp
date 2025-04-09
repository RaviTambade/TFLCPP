#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <chrono>

using namespace std;

enum ecommerceOption { browse, addItem, removeItem, placeOrder, cancelOrder, payAmount, trackOrder};
 
//Parallel Execution:
// hook functions-----react 
// Action Listeners ----java
// Callback function ---node js
// Helper functions  ---- Event handling
// Request Handlers


string  getProductfromCatalog(){

    this_thread::sleep_for(chrono::seconds(6));
    cout<< "Specific Product has been searched from Avaialble Product Catalog"<<endl;
    return "Gerbera";
}

void sort(){
    cout<< "All products have been sorted in ascending order based on sale"<<endl;
}

string addToCart(){
    this_thread::sleep_for(chrono::seconds(3));
    cout<< "New Item is added to existing Shopping Cart"<<endl;
    return "iPhone";
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

//Object Oriented Programming
//Encapsulation:Hiding Complexity
//Simplicity: is nothing but Hiding Complexity

int main(){
    cout<<"Primary Thread executing  main code"<<endl; 
    
    //Route mapping
    std::future<string> resultCatalog=std::async(launch::async, getProductfromCatalog);
    std::future<string> resultCart=std::async(launch::async, addToCart);
    
    //Receive Response
    string actualProduct=resultCatalog.get();
    string cartItem=resultCart.get();
    
    //Presentation
    cout<<"The Product is :"<<actualProduct;
    cout<<"The Item added to Cart  :"<<cartItem;


    cout<<"Primary Thread is about to terminate"<<endl;
    return 0;
}