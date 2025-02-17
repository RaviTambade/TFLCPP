
#include<stdio.h>
#include "account.h"

int main(){
    //External Variable definition
    //it is used to import the global variable from another file

    extern struct Account acctSarthak;
    extern struct Account acctSaloni;

    //Create Account and initialize elements

    createAccount(&acctSarthak, 1001, "Sarthak", 10000, "Saving");
    createAccount(&acctSaloni, 1002, "Saloni", 20000, "Current");

    //Display Account
    printf("Account Sarthak\n");
    display(&acctSarthak);
    
    printf("Account Saloni\n");
    display(&acctSaloni);

}

