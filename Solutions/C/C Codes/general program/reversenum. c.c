#include<stdio.h>
int main()
{
    int a1,a2,a3,a4,a5,n;
    long int revnum;
    printf("enter the five number (less than 50000)");
    scanf("%d",&n);
    a5=n%10;
    n=n/10;
    a4=n%10;
    n=n/10;
    a3=n%10;
    n=n/10;
    a2=n%10;
    n=n/10;
    a1=n%10;
revnum=a5*10000+a4*1000+a3*100+a2*10+a1;
printf("the reversed number is %ld\n",revnum);
    return 0; 
}
