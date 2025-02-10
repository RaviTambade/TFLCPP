#include <stdio.h>
#include <math.h>
#include "location.h";

//function (Logic to accept input)
void acceptLocationData( struct Location  *ptrLoc){
    printf("\n Place 1 Details:\n");
    printf("\n Please enter logitude of Place 1");
    scanf("%lf", ptrLoc->longitude);
    printf("\n Please enter latitude of Place 1");
    scanf("%lf", ptrLoc->lattitude);
}
float getDisance(struct Location place1, struct Location place2){

    float b=sin(place1.longitude);
    float c= sin(place1.longitude);
    float gDist=place2.lattitude-place1.lattitude;
    float term1= cos(b) + c + cos(gDist);
    float distance= 3963 * (cosec(term1));
    return distance;
}

int main(int argc, char const *argv[])
{
    int count;
    //Get first Location data from user
    printf("\n Welcome to Geolocation Distance Calcualtor");
    struct Location place1;
    struct Location place2;
    //get second Location data from user
    acceptLocationData(&place1);
    //get second Location data from user
    acceptLocationData(&place2);
 
    //Calculate each small equation of main equation
    float distance= getDisance(place1, place2);
    printf( "distance = %d", distance);
   
    //apply formula to calculate distance
    //print distance calcualted on screen to user

}
//How to declare variable
//How assign value to variables
//