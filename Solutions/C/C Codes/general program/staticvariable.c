#include <stdio.h>
//If lifetime of human is 100 years 
//Applicaiton is started , run, and terminated in one day ---Application lifetime

//Year is global variable
//date is static variable
//time is local variable in one day when humain being invokes daily function

//Global variable
int studentCount=0;

//User defined functions
void processCount(){
    studentCount++;
    //local variable is initialized every time function is called
    //local variable is  reset to 0
    int count=0;        //local variable
    count++;            //increment count
    printf("count=%d\n", count);
}

void serviceVehicle(){
    studentCount++;
    //static variable is initialized only once  
    //static variable is not reset to 0
    static int numberofVehicles=0; //static variable
     numberofVehicles++;        //increment numberofVehicles
    printf("numberofVehicles=%d\n",  numberofVehicles);
}

void incremenStudentCount(){
    studentCount++;
}


//Entry point function
int main(){
    studentCount++;

    printf("Hello World\n");
    processCount();
    processCount();
    processCount();

    serviceVehicle();
    serviceVehicle();
    serviceVehicle();

    printf("studentCount=%d\n", studentCount);
}