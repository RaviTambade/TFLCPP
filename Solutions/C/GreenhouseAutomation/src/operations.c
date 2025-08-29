#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/datetime.h"
#include "../include/climate.h"
#include "../include/operations.h"

struct DateTime * getCurrentDateTime()
{
    time_t currentTime;

    time(&currentTime);
    
    struct tm *ptrLocalTime = localtime(&currentTime);
    struct DateTime * ptrDateTime= ( struct DateTime *) malloc (sizeof( struct DateTime));
    if( ptrDateTime != NULL){
        ptrDateTime->date.day = ptrLocalTime->tm_mday;
        ptrDateTime->date.month = ptrLocalTime->tm_mon + 1;
        ptrDateTime->date.year = ptrLocalTime->tm_year + 1900;
        ptrDateTime->time.hour = ptrLocalTime->tm_hour;
        ptrDateTime->time.minute = ptrLocalTime->tm_min;
        ptrDateTime->time.seconds = ptrLocalTime->tm_sec;
    }
   
    return ptrDateTime;
}

struct Climate * getClimateData()
{

    struct Climate  * ptrCurrentClimate;
    // Accept climate data from the user
    ptrCurrentClimate = (struct Climate *)malloc(sizeof(struct Climate));
    ptrCurrentClimate->ptrDateTime=getCurrentDateTime();

    printf("\n\n Climate Data Input:");
    printf("\nenter temparature: ");
    scanf("%f", &ptrCurrentClimate->temp);

    printf("enter Humadity: ");
    scanf("%d", &ptrCurrentClimate->humadity);

    printf("enter Light Mode o or 1: ");
    scanf("%d", &ptrCurrentClimate->light);

     // climateData->fanstatus = FALSE;
    return ptrCurrentClimate;
}

void displayClimateData(struct Climate * ptrClimate)
{
    if (ptrClimate == NULL)
    {
        printf("\n No climate data found");
    }
    else
    {
        printf("\n\n DISPLYING DATA:");
        printf("\ntemparture: %f", ptrClimate->temp);
        printf("\nhumadity: %d", ptrClimate->humadity);
        printf("\nlight: %d", ptrClimate->light);

        printf("\nDate: %d / %d / %d", ptrClimate->ptrDateTime->date.day,
                                       ptrClimate->ptrDateTime->date.month,
                                       ptrClimate->ptrDateTime->date.year);
        printf("\nTime: %d : %d : %d",ptrClimate->ptrDateTime->time.hour,
                                      ptrClimate->ptrDateTime->time.minute,
                                      ptrClimate->ptrDateTime->time.seconds);
    
        // printf("temparture: %f",temp);
    }
}
 