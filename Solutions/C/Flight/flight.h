#ifndef FLIGHT_H
#define FLIGHT_H
struct Flight{
    int flightNumber;         
    char airline[100];       
    char origin[20];    
    char destination[20]; 
    char departureTime[20];   
    char arrivalTime[20];     
    char flightStatus[20];    
    int passengerCount;      
};

int getChoiceFromMenu();
void displayFlightDetails( struct Flight flight);
struct Flight acceptFlightDetails();
void writeToFile(const char *pfilename, struct Flight flight);
struct Flight getFromFile(const char *pfilename);
#endif