#include "account.h"
#include<stdio.h>
#include<string.h>
//Account Operation functions
void createAccount(struct Account *account,   int accountNumber,   char *accountHolderName, float accountBalance, char *accountType){
    account->accountNumber=accountNumber;
    strcpy(account->accountHolderName, accountHolderName);
    account->accountBalance=accountBalance;
    strcpy(account->accountType, accountType);
}

void deposit(struct Account *account, float amount){
    account->accountBalance+=amount;
}

void withdraw(struct Account *account, float amount){
    account->accountBalance-=amount;
}

void display(struct Account *account){
    printf("Account Number=%d\n", account->accountNumber);
    printf("Account Holder Name=%s\n", account->accountHolderName);
    printf("Account Balance=%f\n", account->accountBalance);
    printf("Account Type=%s\n", account->accountType);
}