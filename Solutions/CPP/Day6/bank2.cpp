#include <iostream>
using namespace std;



class Account{
    private :
        int id;
        string holder;
        double balance;
        
    public:
       Account(){

        }
        Account(int i,string name, double amount){
            id=i;
            holder=name;
            balance=amount;
        }

        void setId(int i){
            id=i;
        }

        int getId(){
            return id;
        }

        void setHolder(string name){
            holder=name;
        }

        string getHolder(){
            return holder;
        }

        void setBalance(double amount){
            balance=amount;
        }

        double getBalance(){
            return balance;
        }

        void deposit(float amount){
                balance=balance+ amount;
        }

        void withdraw(float amount){
            balance=balance-amount;
        }


        static void fundsTransfer( Account *ptrFromAccount ,Account * ptrToAccount, 
                                   float amount){
           cout<<"performing funds Transfer"<<endl;
            ptrFromAccount->withdraw(amount);
            ptrToAccount->deposit(amount);

        }

        void show(){
            cout<<"Account ID: "<<id<<endl;
            cout<<"Account Holder"<<holder<<endl;
            cout<<"Account Balance"<<balance<<endl;
             
        }

        ~Account(){
            cout<<"Account Destructor is called"<<endl;
        }
};

int main(){

    cout<<"Welcome to HDFC Bank"<<endl;
    /* 
    Date today(18,3,2025);
    Date yesterday(17,3,2025);
    Date tomorrow(19,3,2025);
    today.show();
    tomorrow.show();
    yesterday.show();

    Date dd;
    dd.show();
    */
 
    Account acct123(78,"Raj",50000);
    Account acct654(98, "Manisha",89000);

    cout<<"before Funds Transfer"<<endl;
    acct123.show();
    acct654.show();     
    Account::fundsTransfer(&acct123,&acct654,5000);
    cout<<"after Funds Transfer"<<endl;
    acct123.show();
    acct654.show();
   
    return 0;
}