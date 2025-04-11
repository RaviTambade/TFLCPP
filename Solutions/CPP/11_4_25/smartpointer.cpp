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
            cout << "Account destroyed for " << name << "\n";
        }

        void display() const {
            cout << "Account: " << name << ", Balance: $" << balance << "\n";
        }
};

int main() {
    unique_ptr<Account> accPtr = make_unique<Account>("Pragati", 1000.0);
    accPtr->display();

    // No need to manually delete - happens automatically when accPtr goes out of scope
    return 0;
}
