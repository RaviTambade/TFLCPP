#include <stdio.h>
#include "../include/climate.h"
#include "../include/operations.h"
#define MAX_READING 2
int main()
{
    //struct climateControl cControl[2];  //array of structure elements
    struct Climate *ptrClimateData[2]; //array of struction pointers

    for(int i=0;i<MAX_READING;i++)
    {
        ptrClimateData[i] = getClimateData();
    }

    for (int i = 0; i < MAX_READING; i++)
    {
        displayClimateData(ptrClimateData[i]);
    }
    return 0;
}

// g++ -I include -c ./src/operations.c -o ./build/operations.o
// g++ -I include -c ./src/main.c -o ./build/main.o
// g++ ./build/main.o  ./build/operations.o -o  ./build/output.exe