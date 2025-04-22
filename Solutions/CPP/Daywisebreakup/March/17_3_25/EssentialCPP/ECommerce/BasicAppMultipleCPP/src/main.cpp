#include "ecommerce.h"
#include <iostream>

//Modularity
//Logic is divided into multiple libraries
//invoke all functions from other libraries into main function

int main(){
    showAvaialbleProduct();
    addProductTocart();
    deliverProduct();
}

//g++ -I include  ./src/catalog.cpp  ./src/shoppingcart.cpp ./src/delivery.cpp  ./src/main.cpp -o ./build/store.exe