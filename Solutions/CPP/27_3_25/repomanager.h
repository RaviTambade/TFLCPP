#include "account.h"

namespace Banking {
    class RepositoryManager{
        public:
            static Account currentAccount;
            static void  saveAccountDetails();
            static void   getAccountDetails();
    };
}
 