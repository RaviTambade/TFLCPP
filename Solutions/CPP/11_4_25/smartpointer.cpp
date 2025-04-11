#include <iostream>
#include <string>
#include <memory>  // For smart pointers
using namespace std;
class Account {

    private:
            string name;
            double balance;

    public:
        Account(const string& name, double balance)
            : name(name), balance(balance) {
            cout << "Account created for " << name << "\n";
        }

        ~Account() {
            cout<<"DiInitialization "<<endl;
            cout << "Account destroyed for " << name << "\n";
        }

        void display() const {

            //clean up job
          
            cout << "Account: " << name << ", Balance: $" << balance << "\n";
        
        }
};

int main() {

    /*Account * ptrAcct=NULL;
    ptrAcct=new Account("raj",780000);
    ptrAcct->display();

    if(ptrAcct !=NULL){
        delete ptrAcct;
    }*/

    unique_ptr<Account> accPtr = make_unique<Account>("Pragati", 1000.0);
    accPtr->display();

    // No need to manually delete -
    // happens automatically when accPtr goes out of scope
    return 0;
}
