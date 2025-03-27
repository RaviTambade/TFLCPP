#include "account.h"
#include <fstream>
#include <string>

using namespace std;

namespace Banking {

    Account::Account(int i, string nm, double amount):id(i), name(nm), balance(amount){   }
    //setter and getter

    void Account::setId(int i){
    id=i;
}

    int Account::getId(){
    return id;
}

    void Account::setName(string nm){
   name=nm;
}

    string Account::getName(){
    return name;
}


    void Account::setBalance(double bal){
    balance=bal;
}

    double  Account::getBalance(){
    return balance;
}

    //Banking Operations

    void Account::deposit(double amount){
        balance=balance+ amount;
    }

    void Account::withdraw(double amount){
    balance=balance-amount;
}

    void Account::display() const {
        cout<<"Current Account Details "<<endl;
        std::cout <<"Id: "<<id<< ", Name: " << name << ", balance: " << balance << std::endl;
    }

     

    //Persistence: Serialize the object into an output stream (file or memory)
    void Account::serialize(std::ofstream& outFile) {
        outFile << id << std::endl;
        outFile << name << std::endl;
        outFile << balance << std::endl;
    }

    //Persistence: DeSerialize the object into an output stream (file or memory)

    void Account::deserialize(std::ifstream& inFile) {
        inFile>>id;
        inFile.ignore();
        getline(inFile, name);  
        inFile >> balance;              
    }

    istream&  operator>>(istream& is,   Account& prn)
    {
        is>>prn.id;
        is.ignore();
        getline(is, prn.name);
        is.ignore();
        is>>prn.balance;
        return is;
    }  

    ostream&  operator<<(ostream& os, const Account& prn)
    {
        os<<prn.id<<endl;
        os<<prn.name<<endl;
        os<<prn.balance<<endl;
        return os;
    }
}