#include <iostream>
using namespace std;
//Menu UI

int choice;
void showMenu(){
    
  
    cout<<"Welcome to HDFC Bank"<<endl<<endl;
    cout<<" 1. Show Account Details"<<endl;
    cout<<" 2. Save Account Details"<<endl;
    cout<<" 3. Deposit"<<endl;
    cout<<" 4. withdraw"<<endl;
    cout<<" 5. Exit"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

    cout<<"Enter your option from Menu show above  :";
    cin>>choice;
    
}
int main(){
    do{
        showMenu();
        cout<<endl<<"You have selected Option: "<<choice<<endl;
        switch(choice){
            case 1:         
                cout<<" Your Account Details :"<<endl;
            break;
            case 2:
                cout<<" Saving your  Account Details :"<<endl;
            break;
            case 3:
                cout<<" Depositing Amount into existing Bank Account:"<<endl;
            break;
            case 4:
                cout<<"Withdrawing Amount from existing Bank Account:"<<endl;
            break;
            case 5:
                cout<<" You have decided to extit"<<endl;
            break;
        }
    }
   while(choice !=5);
   cout<<"Thank you for visiting HDFC Bank"<<endl;

}