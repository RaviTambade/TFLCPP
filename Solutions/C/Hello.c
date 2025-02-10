#include <stdio.h>
#include "point.h"
#include "student.h"
#include "tea.h"
#include "product.h"

int main(int argc, char const *argv[])
{
    
    /*
    int result=600;
    int anotherResult=result;
    result=result+56;
    anotherResult=anotherResult+2;
    printf(" Result = %d", result);  //656
    printf(" Another Result = %d", anotherResult); //658
    
    */

     int  population=9000;

    //Pointer to integer
    //Pointer is  special type of variable which stored address of some other variable

     int * pPopulation=&population;   //address of variable population

    printf(" Population= %d", population);  //value of variable printed
    printf(" ppopulation= %d", pPopulation); //values of address printed 
    printf( " Actual Value of pPopulation = %d", * pPopulation); // value of variable whoese address given

    struct Point startPoint;
    //assign values to strcture element startPoint
    startPoint.x=45;
    startPoint.y=56;

    struct Student st;
    //assign values to strcture element st
    st.id=34;
    st.age=21;
    strcpy(st.fullName, "Ravi T");
    
    //declare variable and assign value
    struct Student s1={ 34,22,"Nikita S"};

    printf("\n { X=%d, Y=%d}",startPoint.x, startPoint.y);

    printf( "\nStudents Details:");
    printf("\n Name= %s", st.fullName);
    printf("\n Id=%d",st.id);
    printf("\n Age=%d",st.age);

    printf( "\nStudents Details:");
    printf("\n Name= %s", s1.fullName);
    printf("\n Id=%d",s1.id);
    printf("\n Age=%d",s1.age);

    
    struct Product prod;
    //assign values to structure element prod
    prod.id = 101;
    //strcpy  where to copy, what is to be copied
    strcpy(prod.title, "Laptop");
    strcpy(prod.description, "A high-end gaming laptop");
    prod.unitprice = 1500.50;
    prod.stockAvailable = 25;

    printf("\nProduct Details:");
    printf("\n ID = %d", prod.id);
    printf("\n Title = %s", prod.title);
    printf("\n Description = %s", prod.description);
    printf("\n Unit Price = %.2f", prod.unitprice);
    printf("\n Stock Available = %d", prod.stockAvailable);

    //There are lot of reusable , readymade function provided for developers to use
    //printf, scanf, strcpy, strcat, 

    //pointer to structure element

    struct Product * ptrCurrent=& prod;
    printf("\nProduct Details using Pointer:");
    printf("\n ID = %d", ptrCurrent->id);
    printf("\n Title = %s", ptrCurrent->title);
    printf("\n Description = %s",ptrCurrent->description);
    printf("\n Unit Price = %.2f", ptrCurrent->unitprice);
    printf("\n Stock Available = %d", ptrCurrent->stockAvailable);
    
    struct Tea morningTea;
    morningTea.sugar=10;
    morningTea.milk=200;
    morningTea.tea=2;
    morningTea.water=300;

    struct Tea eveningTea;
    morningTea.sugar=20;
    morningTea.milk=400;
    morningTea.tea=4;
    morningTea.water=600;
    return 0;

    struct Tea eventTea;
    morningTea.sugar=400;
    morningTea.milk=1500;
    morningTea.tea=75;
    morningTea.water=5000;
}