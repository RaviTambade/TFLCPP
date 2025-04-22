#include <iostream>
#include <fstream>
#include <string>

#include <string.h>
using namespace std;

namespace Banking {


    //Business Logic 
    class Account{
        private:
                int id;
                string name;
                double balance;
        public :
            Account(int i=0, string nm="", double amount=0):id(i), name(nm), balance(amount){   }

            //setter and getter
            void setId(int i){
                id=i;
            }
            int getId(){
                return id;
            }

            void setName(string nm){
               name=nm;
            }
            string getName(){
                return name;
            }


            void setBalance(double bal){
                balance=bal;
            }
            double  getBalance(){
                return balance;
            }

            //Banking Operations

            void deposit(double amount){
                balance=balance+ amount;
            }

            void withdraw(double amount){
                balance=balance-amount;
            }

            //Operator overloading  >> and <<

            friend  istream&  operator>>(istream& is,   Account& prn)
            {
                is>>prn.id;
                is.ignore();
                getline(is, prn.name);
                is.ignore();
                is>>prn.balance;
                return is;
            }  
            
            friend  ostream&  operator<<(ostream& os, const Account& prn)
            {
                os<<prn.id<<endl;
                os<<prn.name<<endl;
                os<<prn.balance<<endl;
                return os;
            }
    

            //Persistence: Serialize the object into an output stream (file or memory)
            void serialize(std::ofstream& outFile) {
                outFile << id << std::endl;
                outFile << name << std::endl;
                outFile << balance << std::endl;
            }
           
           //Persistence: DeSerialize the object into an output stream (file or memory)
            
            void deserialize(std::ifstream& inFile) {
                inFile>>id;
                inFile.ignore();
                getline(inFile, name);  
                inFile >> balance;              
            }

            void display() const {
                cout<<"Current Account Details "<<endl;
                std::cout <<"Id: "<<id<< ", Name: " << name << ", balance: " << balance << std::endl;
            }
        };


    //Data Access Logic
    class RepositoryManager{
        public:
            static Account currentAccount;
            static void  saveAccountDetails(){
                ofstream outFile("accounts.dat");
                if (outFile.is_open()) {
                    currentAccount.serialize(outFile);
                    outFile.close();
                    cout << "Object serialized to people.dat" << std::endl;
                }
            }

            static void   getAccountDetails(){
                ifstream inFile("accounts.dat");
                if (inFile.is_open()) 
                {
                    currentAccount.deserialize(inFile);
                    inFile.close();
                    cout << "Object deserialized from people.dat" << std::endl;
                }  
            }
    };

    //User Interface Logic
    class UIManager{
        public:         
            static void showMenu(){
                cout<<"Welcome to HDFC Bank"<<endl<<endl;
                cout<<" 1. Show  existing Account Details"<<endl;
                cout<<" 2. Create new Account"<<endl;
                cout<<" 3. Deposit Amount"<<endl;
                cout<<" 4. Withdraw Amount"<<endl;
                cout<<" 5. Exit"<<endl;
                cout<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;
                cout<<"Enter your option from Menu shown above:";
            }
    };
}
using namespace Banking;

//static variable has to be initialized before main function

Account RepositoryManager::currentAccount(34, "Chitra More",56000);

void acceptAccountDetails(){
    cout<<"New Bank Account"<<endl<<endl;
     cout<<"Please enter your Account Details"<<endl<<endl;
       
     cout<<"Enter new Account ID"<<endl;
     int id;
     cin>>id;
     RepositoryManager::currentAccount.setId(id);
    
     cout<<"Enter your Name"<<endl;
     string name;
     cin>>name;
     RepositoryManager::currentAccount.setName(name);

     cout<<"Enter  Initial Amount"<<endl;
     double amount;
     cin>>amount;
     RepositoryManager::currentAccount.setBalance(amount);
     cout<<"Thank  you for providing details"<<endl;*/

 }

int main()
{
    int choice;
        do{
            UIManager::showMenu();
            cin>>choice;
            cout<<endl<<"You have selected Option: "<<choice<<endl;
            switch(choice){
                case 1:         
                    cout<<" Your Account Details :"<<endl;
                break;
                case 2:   
                {
                    cout<<" Account Opening :"<<endl;
                    //UIManager::acceptAccountDetails();
                    RepositoryManager::saveAccountDetails();
                    cout<<" Account has been successfully Opened in Bank"<<endl;
                }
                break;
                case 3:
                { 
                    RepositoryManager::getAccountDetails();
                    RepositoryManager::currentAccount.display();
                    cout<<endl<<" Depositing Amount: "<<endl;
                    double amount;
                    cout<< "Enter  Amount  to deposit  :";
                    cin>>amount;
                    
                    RepositoryManager::currentAccount.deposit(amount);
                    RepositoryManager::currentAccount.display();
                }
                break;
                case 4:
                {
                    RepositoryManager::getAccountDetails();
                    RepositoryManager::currentAccount.display();

                    cout<<endl<<"Withdrawing Amount: "<<endl;
                    double amount;
                    cout<< "Enter  Amount  to withdraw  : ";
                    cin>>amount;
                    cout<<" The amount = "<<amount;
                    RepositoryManager::currentAccount.withdraw(amount);
                    RepositoryManager::currentAccount.display();
                }
                break;
                case 5:
                    cout<<" You have decided to extit"<<endl;
                break;
            }
        }
    while(choice !=5);
    cout<<"Thank you for visiting HDFC Bank"<<endl;
    return 0;
    }