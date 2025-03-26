#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace Banking {
    class Account{
        private:
                int id;
                string name;
                double balance;
        public :
            Account(int i=0, string nm="", double amount=0):id(i), name(nm), balance(amount){   }

            void deposit(float amount){
                balance=balance+ amount;
            }

            void withdraw(float amount){
                balance=balance-amount;
            }

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
    
             // Serialize the object into an output stream (file or memory)
            void serialize(std::ofstream& outFile) {
                outFile << id << std::endl;
                outFile << name << std::endl;
                outFile << balance << std::endl;
            }
           
            void deserialize(std::ifstream& inFile) {
                inFile>>id;
                inFile.ignore();
                getline(inFile, name);  
                inFile >> balance;              
            }

            void display() const {
                std::cout <<"Id: "<<id<< ", Name: " << name << ", balance: " << balance << std::endl;
            }
        };

    class RepositoryManager{

        public:

            static   void  saveAccountDetails(){
                Account acct1(77,"Chaitanya Patil", 70);
                ofstream outFile("accounts.dat");
                if (outFile.is_open()) {
                    acct1.serialize(outFile);
                    outFile.close();
                    cout << "Object serialized to people.dat" << std::endl;
                }
            }

            static  void showAccountDetails(){
                Account acct2;

                ifstream inFile("accounts.dat");
                    if (inFile.is_open()) {
                        acct2.deserialize(inFile);
                        inFile.close();
                    cout << "Object deserialized from people.dat" << std::endl;
                    }
                
                    acct2.display();
            }
    };

    class UIManager{

    public:
        static void showMenu(){
            cout<< endl<< "Welcome to Order Processing System."<<endl;;
            cout<<"------------------------------------------------"<<endl;
            cout<<" 1. Show Account Details"<<endl;
            cout<<" 2. Save Account Details"<<endl;
            cout<<" 3. Deposit"<<endl;
            cout<<" 4. withdraw"<<endl;
            cout<<" 5. Exit"<<endl;
            cout<<"------------------------------------------------"<<endl;
            cout<<"------------------------------------------------"<<endl;
        }
};
}
using namespace Banking;

int main(){
    int choice;
    bool exit=false;

    cout<<"Welcome to HDFC Bank"<<endl;
    while(!exit){

        UIManager::showMenu();  //static function is always called using :: scope resolution operator
        cin>>choice;

        switch(choice){
            case 1:
                RepositoryManager::showAccountDetails();
            break;
            case 2:
                RepositoryManager::saveAccountDetails();
            break;
            case 3:
                cout<<"Deposit Amount"<<endl;     
            break;
            case 4:
                cout<<"Withdraw Amount"<<endl;    
            break;
            case 5:
                    cout<<"Thank you for visiting HDFC Bank"<<endl;
                    exit=true;
            break;
        }
    return 0;
    }
}