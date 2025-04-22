#include <iostream>
#include <fstream>
#include <string>
# include "repomanager.h"

 namespace WellnessForever{
        Medicine RepositoryManager::theMedicine(453,"Crocine","fever",4,5000));
    
        void  RepositoryManager::saveMedicine(){
            ofstream outFile("inventory.dat");
            if (outFile.is_open()) {
                theMedicine.serialize(outFile);
                outFile.close();
                cout << "Object serialized to inventory.dat" << std::endl;
            }
        }

        void    RepositoryManager::getMedicine(){
            ifstream inFile("inventory.dat");
            if (inFile.is_open()) 
            {
                theMedicine.deserialize(inFile);
                inFile.close();
                cout << "Object deserialized from inventory.dat" << std::endl;
            }  
        }
}

