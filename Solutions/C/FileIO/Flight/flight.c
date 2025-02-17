#include<stdio.h>
#include"flight.h"

int getChoiceFromMenu()
{
    int choice;
    printf("");
    printf("\n Air Traffice Simulation Application:\n");
    printf("1.Enter new Flight\t ");
    printf("2.Display all Flights\t");
    printf("3.Exit\t");
    printf("");
    printf("\nEnter your choice : ");
    scanf("%d",&choice );
    return choice;
}

void displayFlightDetails( struct Flight flight)
{
    printf("\n");
     printf("The flight details are as follows.\n");
     printf("The flight number is : %d\n",flight.flightNumber);
     printf("The flight company  is : %s\n",flight.airline);
     printf("The flight origin is : %s\n",flight.origin);
     printf("The flight destination is : %s\n",flight.destination);
     printf("The flight departire time is : %d:%d\n",flight.departureTime);
     printf("The flight arrival time is : %d:%d\n",flight.arrivalTime);
     printf("The flight status is : %s\n",flight.flightStatus);
     printf("The flight's passenger detail is : %d\n",flight.passengerCount);
     printf("\n");
}

struct Flight acceptFlightDetails()
{ 
 struct Flight flight;
 printf("Enter the flight details :\n");

 printf("Enter the flight number :");
 scanf("%d",&flight.flightNumber);

 printf("Enter the flight company :");
 scanf("%s",&flight.airline);

 printf("Enter the flight origin :");
 scanf("%s",&flight.origin);

 printf("Enter the flight destination :");
 scanf("%s",&flight.destination);

 printf("Enter the flight departure time :");
 scanf("%d %d",&flight.departureTime);

 printf("Enter the flight arrival time :");
 scanf("%d %d",&flight.arrivalTime);

 printf("Enter the flight status :");
 scanf("%s",&flight.flightStatus);

 printf("Enter the flight passenger count :");
 scanf("%d",&flight.passengerCount);

 return flight;

}

void writeToFile(const char *pfilename, struct Flight flight)
{
  FILE *pfile=fopen(pfilename,"a");
  fwrite(&flight,sizeof(struct Flight),1,pfile);
  fclose(pfile);
}
         
 struct Flight getFromFile(const char *pfilename)
  {
    struct Flight flight;
   FILE *pfile=fopen(pfilename,"r");
   while (fread(&flight,sizeof(struct Flight),1,pfile))
   {
    displayFlightDetails(flight);
   }
   fclose(pfile);
   return flight;
  }

