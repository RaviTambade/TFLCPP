 #incluce "repomanager.h"

        static void  RepoManager::saveAccountDetails(){
            ofstream outFile("accounts.dat");
            if (outFile.is_open()) {
                currentAccount.serialize(outFile);
                outFile.close();
                cout << "Object serialized to people.dat" << std::endl;
            }
        }

        static void    RepoManager::getAccountDetails(){
            ifstream inFile("accounts.dat");
            if (inFile.is_open()) 
            {
                currentAccount.deserialize(inFile);
                inFile.close();
                cout << "Object deserialized from people.dat" << std::endl;
            }  
        }
};
