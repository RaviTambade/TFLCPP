#include <iostream>
using namespace std;

class Account{

    private:
        float balance;
    
    public: 
        //default constructor
        Account(){
            balance=5000;
        }

        //Parameterized constructor
        Account(float amount){
            balance=amount;
        }

        Account( Account & other){
            balance=other.getBalance();
        }
        void deposit(float amount){
            balance+=amount;
        }

        void withdraw(float amount){
            balance-=amount;
        }
        
        float getBalance(){
            return balance;
        }
};

int main(){
    
    Account acct24;
    Account acct65;
    Account acct234(76000);
    Account acct675(23000);
    
    Account acct89(acct24); //create replica of existing object with the help of Copy Constructor 
                            // new object will be created from existing object (Clonning)

    Account * ptrTheAcct=new Account(5464);

    float currentBalance_24=acct24.getBalance();
    float currentBalance_1=acct234.getBalance();
    float currentBalance_2=acct675.getBalance();
    float currentBalance_3=acct89.getBalance();

    
    cout<<" Current Balance of acct24="<<currentBalance_24<<endl;
    cout<<" Current Balance of acct89="<<currentBalance_3<<endl;
    cout<<" Current Balance of acct675="<<currentBalance_2<<endl;
    cout<<" Current Balance of acct234="<<currentBalance_1<<endl;

    if(ptrTheAcct != NULL){
        delete ptrTheAcct;
    }
}