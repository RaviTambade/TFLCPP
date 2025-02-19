#include <stdio.h>
//entry point function body (implementation)
//Recursion:a function calls itself to solve a smaller instance of the problem
//nested function call


//stack overflow
//Factorial of a number
//4!=4 * (4-1)* ((4-1)-1)* (((4-1)-1) -1)
//4!=4 * 3 * 2 * 1
//5! =5 * (5-1)*  ((5-1) -1) * (((5-1) -1)-1) * (((5-1) -1)-1)-1)
//5!=5 * 4 * 3 * 2 * 1
//n!= n* (n-1) *(n-2)*........ *1
//using iteration
/*
    int factorial(int n){
        int result=1;
        for(int i=1;i<=n;i++){
            result=result * i;
        }
        return result;
    }

*/

//using recursion
int factorialUsingRecursion(int n){
    if(n ==0) return 1;                         //Base case
    return n * factorialUsingRecursion(n-1);    //Recursive case
}

int main(){
    printf("Recursion \n");
    printf("\n Enter the number ");
    int number;
    scanf( "%d", &number);
    //int finalResult= factorial(number);
    int finalResult= factorialUsingRecursion(number);
    printf("Factorial of %d = %d", number, finalResult);
}