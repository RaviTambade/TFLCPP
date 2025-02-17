#include <stdio.h> 
int main() 
{ int celsius, faren; printf("Enter the Temperature in Celsius(°C) : ");
scanf("%d", &celsius); 
faren = (celsius * 9) / 5 + 32;
 printf("Temperature in Fahrenheit is(°F) : %d\n", faren); 
 return 0; 
 }