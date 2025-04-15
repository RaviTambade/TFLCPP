#include <iostream>

// Does this program contains multiple tasks
// Individual Multiple functions 

//multiple behavioural Application Source Code

using namespace std;
//Task 1
void accept_input(){
    string message;
    cin>>message;
}

//Task 2
void display_output(){
    cout<< "Thank you for learning at Transflower"<<endl;
}

//Task 3
void print_hello() {
     cout << "Print execution" <<endl;
}

//Your Application can not be executed by entry point function
//Entry point Task


//Serial Exeuction :

int main() {
    cout << "Main execution" <<endl;
    print_hello();
    accept_input();
    display_output();

    return 0;
}