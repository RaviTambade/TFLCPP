#include<stdio.h>
int main (){
    int no;
    int sum;
    int digit,temp;
    printf("enter the no");
    scanf("%d",&no);
    while (no<=500)
    {
    sum=0;
    temp=no;
    while (temp>0)
    {
        digit=temp%10;
        sum+=digit*digit*digit;
        temp/=10;
    }
    if (sum==no)
    {
        printf("%d\n",no);
    }
        no++;
    }
    return 0;
}