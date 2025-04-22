# include <iostream> 
#include <string.h>
#include "catalog.h"

using namespace std;
using namespace Catalog;
 
//Due to application of Encapsulation
//private data members are always accessed using getter function
//and new values are assigned using setter function

//using namespace Catalog;
int main(){

     Product  theProduct;   //instance is created from Class Product

    theProduct.setId(564);
    theProduct.setTitle("iPhone");
    theProduct.setDescription("Smart Phone");
    theProduct.setStock(56000);

    //Showing all data member values of object the Product
    cout<<"Welcome to ECommerce"<<endl;
    cout<<"ID:"<<theProduct.getId()<<endl;
    cout<<"Title"<<theProduct.getTitle()<<endl;
    cout<<"Description"<<theProduct.getDescription()<<endl;
    cout<<"Stock Availble"<<theProduct.getStock()<<endl;
     
}


//g++ -I include  ./src/main.cpp -o ./build/test.exe