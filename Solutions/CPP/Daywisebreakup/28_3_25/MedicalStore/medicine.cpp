#include "medicine.h"
#include <fstream>
#include <string>

using namespace std;

namespace WellnessForever {

    Medicine::Medicine((int i=0, string nm="", string  cat="",
                        float amount=0,int qty=0):
                        id(i), name(nm),category(cat), price(amount),quantity(qty)){   }

    void Medicine::setId(int i){
        id=i;
    }

    int Medicine::getId(){
        return id;
    }

    void Medicine::setName(string nm){
        name=nm;
    }

    string Medicine::getName(){
        return name;
    }
    
    
    void Medicine::setCategory(string cat){
        category=cat;
    }

    string Medicine::getCategory(){
        return category;
    }   


    void Medicine::setPrice(float amount){
        price=amount;
    }

    double  Medicine::getPrice(){
        return balance;
    }

    void Medicine::setQuantity(float amount){
        price=amount;
    }

    double  Medicine::getQuantity(){
        return balance;
    }

 
    void Medicine::display() const {
        cout<<"Medicine Details "<<endl;
        std::cout <<"Id: "<<id<< ", Name: " << name <<  ", Category " << category <<  ", price: " << price <<  ", quantity: " << quantity <<std::endl;
    }

     
    void Medicine::serialize(std::ofstream& outFile) {
        outFile << id << std::endl;
        outFile << name << std::endl;
        outFile << category << std::endl;
        outFile << price << std::endl;
        outFile << quantity << std::endl;
    }


    void Medicine::deserialize(std::ifstream& inFile) {
        inFile>>id;
        inFile.ignore();
        getline(inFile, name); 
        inFile.ignore();
        getline(inFile, category);
        inFile.ignore();
        inFile>>price;
        inFile.ignore();             
        inFile >>quantity;              
    }

    istream&  operator>>(istream& is,   Medicine& prn)
    {
        is>>prn.id;
        is.ignore();
        getline(is, prn.name);
        is.ignore();
        is>>prn.balance;
        return is;
    }  

    ostream&  operator<<(ostream& os, const Medicine& prn)
    {
        os<<prn.id<<endl;
        os<<prn.name<<endl;
        os<<prn.balance<<endl;
        return os;
    }
}