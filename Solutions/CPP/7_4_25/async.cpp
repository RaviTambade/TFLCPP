#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <chrono>

using namespace std;
 
string  getProductfromCatalog(){

    this_thread::sleep_for(chrono::seconds(6));
    cout<< "Specific Product has been searched from Avaialble Product Catalog"<<endl;
    return "Gerbera";
}

 
void sort(){
    cout<< "All products have been sorted in ascending order based on sale"<<endl;
}
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

//Object Oriented Programming
//Encapsulation:Hiding Complexity
//Simplicity: is nothing but Hiding Complexity


int main(){
    cout<<"Primary Thread executing  main code"<<endl; 

    //a Promise is retured from async method
    //assurance of geting value when the method is going to be exeucted
    
    std::future<string> result=std::async(launch::async, getProductfromCatalog);
    string actualProduct=result.get();
    cout<<"The Product is :"<<actualProduct;
    cout<<"Primary Thread is about to terminate"<<endl;
    return 0;
}

