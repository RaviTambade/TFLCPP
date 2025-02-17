#include <stdio.h>
int main(){
    int a=10;
    float b=10.5;
    char c='A';
    double d=10.5;
//printf("a=%d\n", a);
// printf("b=%f\n", b);
// printf("c=%c\n", c);
// printf("d=%lf\n", d);
//atomatically typecasting is done by compiler
//Implicit typecasting
    float e=a;
    int newValue=e;
// printf("e=%f\n", e);
//printf("newValue=%d\n", newValue);
//left value is int = right value is double
    int x=d;
//int y=d/0;
    printf("d=%f\n", d);
    printf("x=%d\n", x); 
//printf("y=%d\n", y);  // it is not possible to divide by zero
   

/*printf("a=%f\n", (float)a);
printf("b=%d\n", (int)b);
printf("c=%d\n", (int)c);
printf("d=%f\n", (float)d);*/
    return 0;
}
