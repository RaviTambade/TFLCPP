#include <stdio.h>
#include <stdbool.h>
#include "../include/person.h"
#include "../include/point.h"
#include "../include/line.h"
#include "../include/circle.h"
//Entry Point Function : main
int main()
{
    printf("Hello world !");   

    //Integer Types
    //Primitve Data Types
    short marks=12;      // 2 bytes (16 bits)
    int count=67;       // 4 bytes  (32 bits)
    long result=76567;  //  8 bytes (64 bits)

    char ch='A';
    float pi=3.14f;
    double price=56.765456;
    long double number=3.141592653589793238;

    bool status=false;

    //User defiend types :  structure
    struct Person person1={ "Ravi", 49, 5.6};
    struct Person person2={ "Disha", 19, 4.6};

    struct  Point pt1={12,45};
    struct  Point pt2={112,145};

    struct  Line l1={pt1, pt2};
    struct  Circle c1={pt1, 5};

    printf("Marsk : %d \n", marks);
    printf("PI : %.3f \n",pi);
    printf("Character : %c \n",ch);


    printf( "Name %s \n", person1.name );
    printf("Age : %d \n", person1.age);
    printf( "Height : %.3f\n", person1.height );
  
    printf( "Name %s \n", person2.name );
    printf("Age : %df \n", person2.age);
    printf( "Height :  %.3f \n", person2.height );


}

/*
Build process of C Project

g++ -Iinclude -c ./src/main.c -o ./build/main.o
g++  ./build/main.o  -o ./build/output.exe
*/