#include <iostream>
#include <thread>
#include <chrono>

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


//a Task
void print_hello() {
    while(true){
        cout << "Hello from a secondary thread 1!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }       
}


void print_Bye() {
        while(true){
            cout << "Bye from a secondary thread 2!" << endl;
           this_thread::sleep_for(chrono::seconds(5));
        }
}
    
int main() {
    cout<<"Primary Thread Exeuction is started."<<endl;
    ecommerceOption shoppoingStatus;
    cout<< "Welcome to Transflower"<<endl;

    ecommerceOption  shoppoingStatus=addItem;
    switch(shoppoingStatus)
    {
        case  browse:{
            //secondary Thread
            thread  searchworker(search);  // Start a new thread
            searchworker.join();
        }        
        break;

        case addItem:{
            //secondary Thread
            thread addWorker(addItem);
            addWorker.join();
        } 
        break; 

        case removeItem:{
            thread removeWorker(removeItem);
            removeWorker.join();
        }
                
        break; 
        
        case  placeOrder:
                 
        break;
    
        case trackOrder:
                 
        break;
  
    cout<<"Thank you for  purchase product online from our TFL Store"<<endl;
}

    
    thread tBye(print_Bye);
    tHello.join();  // Wait for the thread to finish
    tBye.join();
    cout<<"Primary Thread Execution is about to terminate"<<endl;
    return 0;
}
