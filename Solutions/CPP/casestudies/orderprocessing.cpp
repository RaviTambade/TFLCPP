#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product{
        private:
                string name;
                double price;
                int stockQuantity;

        public:
                Product(){}
                Product(string name, double price, int quantity){

                }

                ~Product(){

                }
};


class Customer{
        private:
                string name;
                string email;
                bool isActive;
        public:

};



class Order{
    private:
            Customer * ptrCustomer;
            vector<Product *> products;
            double totalAmount;
            string orderStatus;
            string paymentStatus;
    public:
            void AddProduct( Product * ptrProduct, int quatity){}
            /******** */

};



void showMenu(){

        cout<< endl<< "Welcome to Order Processing System."<<endl;;
        cout<<"------------------------------------------------"<<endl;
        cout<<" 1. View Products"<<endl;
        cout<<" 2. Place Order"<<endl;
        cout<<" 3. Apply Discount"<<endl;
        cout<<" 4. Process Order"<<endl;
        cout<<" 5. Exit"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"------------------------------------------------"<<endl;
}


int main(){

    int choice;
    bool exit=false;
    cout<<"Order Processing Management"<<endl;
    while(!exit){
        showMenu();
        cin>>choice;
        switch(choice){
            case 1:
                    {


                    }
            break;

            case 2:
                    {

                    }
            break;

            case 3:
                    {

                    }
            break;

            case 4:
                    {
                        
                    }
            break;

            case 5:
                    cout<<"Thank you for visiting Shop"<<endl;
                    exit=true;
            break;
        }
    return 0;
   }
}