
#include "uimanager.h"
#include <iostream>

using namespace std;

namespace WellnessForever{
    
    void UIManager::showMenu(){
        cout<<"Welcome to Wellness Forever"<<endl<<endl;
        cout<<" 1. Show  existing Medicine Details"<<endl;
        cout<<" 2. Insert new Medicine"<<endl;
        cout<<" 3. Update Stock Amount"<<endl;
        cout<<" 4. Sale Medicine"<<endl;
        cout<<" 5. Exit"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Enter your option from Menu shown above:";
    }
}
  