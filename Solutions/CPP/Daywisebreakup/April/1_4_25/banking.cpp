#include <iostream>
using namespace std;

//Pure Abstract Base Class
class Account {
    public :
            virtual void  deposit(double amount)=0;
            virtual void  withdraw(double amount)=0;
};

class CurrentAccount:Account{

    private : double balance;
              double processingFee;
    public  :
            CurrentAccount(double initialAmount): balance(initialAmount) {
                processingFee=5;
            }
            
            void  deposit(double amount) override{
                balance=balance +amount-processingFee;
            }
            
            void  withdraw(double amount) override {
                balance=balance-amount-processingFee;
            }
};

class SavingAccount:Account{

    private : double balance;
    public  :
            SavingAccount(double initialAmount): balance(initialAmount) {}
            
            void  deposit(double amount) override{
                balance=balance +amount-1;
            }
            
            void  withdraw(double amount) override {
                balance=balance-amount-1;
            }
};

class SalaryAccount:Account{
    private :
            double balance;

    public:
        SalaryAccount(double initialAmount): balance(initialAmount) {}
        
        void  deposit(double amount) override{
            balance=balance +amount;
        }
        
        void  withdraw(double amount) override {
            balance=balance-amount;
        }
};


int main (){

}