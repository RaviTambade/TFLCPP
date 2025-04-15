# include <iostream> 
#include <string.h>

//How to implement Modularity
//How to define a class
//How to create object (instance)
//how to set data to data members belong to object
//how to show data of object 

namespace Catalog{

    class Product{
        public :     //access Specifiers (public/ private/ protected)
                //data members
                int id;
                char title[10];
                char description[200];
                int stock;
    };
}

namespace CRM{
    class Customer{
        public:
            int id;
            char fullName[100];
            char contactNumber[10];
            char email[200];
            int age;

    };
}

using namespace std;
//using namespace Catalog;
int main(){

    Catalog::Product  theProduct;   //instance is created from Class Product

    //data members are initialized of object theProduct

    theProduct.id=456;
    strcpy (theProduct.title,"iPhone");
    strcpy(theProduct.description,"Smart Phone");
    theProduct.stock=56000;

    //Showing all data member values of object the Product

    cout<<"Welcome to ECommerce"<<endl;
    cout<<"ID:"<<theProduct.id<<endl;
    cout<<"Title"<<theProduct.title<<endl;
    cout<<"Description"<<theProduct.description<<endl;
    cout<<"Stock Availble"<<theProduct.stock<<endl;

    //Write logic for creating object of Customer
    //set values to date member belong to customer object

    // display all data members belong to customer object.

}
