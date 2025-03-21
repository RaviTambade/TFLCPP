# include <iostream> 
#include <string.h>
#include "crm.h"
#include "catalog.h"

/*using namespace std;
using namespace Catalog;
using namespace CRM;
*/


//using namespace Catalog;
int main(){

    Catalog::Product  theProduct;   //instance is created from Class Product

    theProduct.id=456;
    strcpy (theProduct.title,"iPhone");
    strcpy(theProduct.description,"Smart Phone");
    theProduct.stock=56000;

    //Showing all data member values of object the Product
    std::cout<<"Welcome to ECommerce"<<std::endl;
    std::cout<<"ID:"<<theProduct.id<<std::endl;
    std::cout<<"Title"<<theProduct.title<<std::endl;
    std::cout<<"Description"<<theProduct.description<<std::endl;
    std::cout<<"Stock Availble"<<theProduct.stock<<std::endl;

    //Write logic for creating object of Customer
    //set values to date member belong to customer object
    // display all data members belong to customer object.
    CRM::Customer cst;
    cst.id=654;
    cst.age=49;
    strcpy(cst.fullName, "Ravi Tambade");
    strcpy(cst.email,"ravi.tambade@transflower.in");
    strcpy(cst.contactNumber,"9881735801");

    std::cout<<"ID: "<<cst.id<<std::endl;
    std::cout<<"Full Name: "<<cst.fullName<<std::endl;
    std::cout<<"Email: "<<cst.email<<std::endl;
    std::cout<<"Contact Number: "<<cst.contactNumber<<std::endl;
}


//g++ -I include  ./src/main.cpp -o ./build/test.exe