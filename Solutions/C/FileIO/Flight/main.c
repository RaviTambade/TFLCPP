#include<stdio.h>
#include"flight.h"

int main()
{
const char *pfilename="flight.txt";
int choice;

do{
    choice=getChoiceFromMenu();
    switch(choice)
    {
        case 1:
        printf("You choose to enter new flight.\n");
        {
            struct Flight F1=acceptFlightDetails();
            writeToFile(pfilename,F1);
        }
        break;

        case 2:
        {
          struct Flight F1=getFromFile(pfilename);
          displayFlightDetails(F1);
        }
        break;

        case 3:
        printf("Exiting the application.\n");
        break;

        default:
        printf("Invalid Choice\n");
        break;
    }

}while(choice!=3);
    return 0;
}