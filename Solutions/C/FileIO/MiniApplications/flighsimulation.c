#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Flight.h

struct flight
{
    int flightNumber;          // Unique flight number (e.g., 1234)
    char airline[100];         // Airline name (e.g., "Delta Airlines")
    char origin[20];           // Departure airport
    char destination[20];      // Arrival airport
    char departureTime[20];   // Departure time (format: YYYY-MM-DD HH:MM)
    char arrivalTime[20];     // Arrival time (format: YYYY-MM-DD HH:MM)
    char flightStatus[20];    // Flight status (e.g., "On Time", "Delayed")
    int passengerCount;       // Number of passengers
};


//Flight.c
int getChoiceFromUser()
{
    int choice;
    printf("welcomre to flight menu system\n");
    printf("-------------------------\n");
    printf("1.New Flight schdule\n");
    printf("2.Show all Flights\n"); 
    printf("3.exit\n");
    printf("enter your choice ");
    scanf("%d", &choice);
    return choice;
}
void displayFlight(struct flight flight )
{
    printf("/n Flight Details");
    printf ("flight number:%d\n",flight.flightNumber);
    printf("airline:%s\n",flight.airline);
    printf("origin:%s\n",flight.origin);
    printf("destination:%s\n",flight.destination);
    printf("departure time:%s\n",flight.departureTime);
    printf("arrival time:%s\n",flight.arrivalTime);
    printf("flight status:%s\n",flight.flightStatus);
    printf("passenger count:%d\n",flight.passengerCount);

}
struct flight acceptFlightDetails()
{
    struct flight flight;

    printf("enter flight number \n");
    scanf("%d",&flight.flightNumber);
    printf("enter airline \n");
    getchar();
    fgets(flight.airline,sizeof(flight.airline),stdin);
    flight.airline[strcspn(flight.airline,"\n")] = '\0';
    printf ("enter origin\n");
    scanf("%s",flight.origin);
    printf ("enter destination\n");
    scanf("%s",flight.destination);
    printf("enter department time\n");
    scanf("%s",flight .departureTime);
    printf("enter arrival time\n");
    scanf("%s",flight.arrivalTime);
    printf("enter flight status\n");
    scanf("%s",flight.flightStatus);
    printf("enter passenger count\n");
    scanf("%d",&flight.passengerCount);
    return flight;
}
void writeToFlight(const char *pfilename,struct flight flight )
{   
    if (pfilename==NULL)
    {
        printf("error:invalid file name\n");
        return;
    }
    FILE *pfile =fopen(pfilename,"ab");
    if (pfile==NULL)
    {
        printf("not able to open the file\n");
        return;
    }
    fwrite(&flight,sizeof(struct flight),1,pfile );
    fclose (pfile );   
} 
struct flight readFromFlight(const char *pfilename )
{
   struct flight flight;
   FILE *pfile=fopen(pfilename,"rb");
   if (pfile==NULL)
   {
    printf("not open\n");
     return flight;
}else {
    while (fread(&flight, sizeof(struct flight), 1, pfile))
    {
        displayflight(flight);
    }
    fclose(pfile);
    
}
return flight;
}


//main.cpp
int main(){
    int choice;
    const char*pfilename="flight.menu";
    do {
        choice=getChoiceFromUser();
        switch (choice)
        {
        case 1:
            {
                struct flight flight =acceptFlightDetails();
                writetoflight(pfilename,flight);
                displayflight(flight);
            }
        break;
        case 2:
            {
                struct flight flight=readFromFlight(pfilename);
                displayflight(flight);
            }
        break;

        case 3:{
                printf("thank you for using flight menu system");
        }
        break;
        default:
        printf("invalid statement plz try again");
            break;
        }
    }while(choice!=3);
    return 0;
}