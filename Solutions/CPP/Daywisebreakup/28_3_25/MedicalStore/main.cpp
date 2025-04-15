#include <iostream>
#include <string>
#include "medicine.h"
#include "repomanager.h"
#include "uimanager.h"
using namespace std;
using namespace WellnessForever;

int main()
{
    int choice;
        do{
            UIManager::showMenu();
            cin>>choice;
            cout<<endl<<"You have selected Option: "<<choice<<endl;

            switch(choice){
    
                case 1:         
                    cout<<" Medicine Details :"<<endl;
                break;
                
                case 2:   
                {
                    cout<<" Saving Medicine :"<<endl;
                    RepositoryManager::saveAccountDetails();
                    cout<<" Medicine has been successfully saved in inventory"<<endl;
                }
                break;
                
                case 3:
                { 
                    //updating stock
                    RepositoryManager::getMedicine();
                    RepositoryManager::theMedicine.display();

                    cout<<endl<<endl<<" Updating Stock : "<<endl;
                    double quanity;
                    cout<< "Enter  quantity of medicine to update:";
                    cin>>quanity;
                    
                    RepositoryManager::theMedicine.setQuantity(quanity);
                    RepositoryManager::saveMedicine();
                    RepositoryManager::theMedicine.display();
                }
                break;
                
                case 4:
                {
                    //selling medicince with number of items
                    RepositoryManager::getMedicine();
                    RepositoryManager::theMedicine.display();
                    cout<<endl<<" Selling Medicine: "<<endl;
                    double count;
                    cout<< "Enter  number of items to sell  : ";
                    cin>>count;
                    int existingAvailableQuantity=RepositoryManager::theMedicine.getQuantity();
                    int remainigQuantity=RepositoryManager::theMedicine.setQuantity(existingAvailableQuantity-quantity);
                    RepositoryManager::saveMedicine();
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