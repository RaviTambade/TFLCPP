 #include <stdio.h>
#include "../include/handler.h"
#include "../include/math.h"
//Entry Point Function : main
int main()
{
    printf("Hello world !");      
}

/*
Build process of C Project
g++ -Iinclude -c ./src/handler.c -o ./build/handler.o
g++ -Iinclude -c ./src/math.c -o ./build/math.o
g++ -Iinclude -c ./src/main.c -o ./build/main.o
g++ ./build/handler.o ./build/math.o  ./build/main.o  -o ./build/output.exe


 
