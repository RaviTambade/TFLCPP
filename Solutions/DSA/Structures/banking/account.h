
//State of Account Business Entity
 struct Account{
    int accountNumber;
    char accountHolderName[20];
    float accountBalance;
    char accountType[10];
};


//Behavious of Account Business Entity
void createAccount(struct Account *account, 
                    int accountNumber,
                    char *accountHolderName, 
                    float accountBalance, 
                    char *accountType);
void deposit(struct Account *account, float amount);
void withdraw(struct Account *account, float amount);
void display(struct Account *account);
