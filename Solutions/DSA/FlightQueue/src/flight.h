#ifndef __FLIGHT_H  //This is a preprocessor directive that checks if the macro __FLIGHT_H is not defined.
                    // If it is not defined, the code between #ifndef and #endif will be included in the program.
                    //This avoids errors like redefinition of structures or functions.
#define __FLIGHT_H

struct Flight {
    int flight_id;          // Unique identifier for the flight
    char destination[50];   // Destination airport
} ;

#endif