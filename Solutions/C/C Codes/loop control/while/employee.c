#include<stdio.h>
int main(){
    int hour;
    float overtime;
    int i=1;
    while (i<=10)
    {
       printf("enter the no of hours");
       scanf("%d",&hour);
       if (hour>=40){
                overtime=(hour-40)*120;
           } else {
                overtime=0;
            }  
            printf("%d,%f\n",hour,overtime);
            i++;  

       }
         return 0;
    }
   

