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

    // Object is initialized at the time of creation 

     Product p,p2, p3, p4;
     Product  theProduct(23,"Gerbera", "beautiful flower",5600);
        //instance is created from Class Product
 
    //Showing all data member values of object the Product

    cout<<"Product Details of P object"<<endl;
    cout<<"ID: "<<p.getId()<<endl;
    cout<<"Title: "<<p.getTitle()<<endl;
    cout<<"Description: "<<p.getDescription()<<endl;
    cout<<"Stock Availble: "<<p.getStock()<<endl;

    cout<<" Product Details of theProduct object "<<endl;
    cout<<"ID: "<<theProduct.getId()<<endl;
    cout<<"Title: "<<theProduct.getTitle()<<endl;
    cout<<"Description: "<<theProduct.getDescription()<<endl;
    cout<<"Stock Availble: "<<theProduct.getStock()<<endl;
     
}


//g++ -I include  ./src/main.cpp -o ./build/test.exe