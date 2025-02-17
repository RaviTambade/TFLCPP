#include<stdio.h>
int main(){
    int n;
    int i=1;
    int fact=1;
    printf("enter the no");
    scanf("%d",&n);
    fact=i=1;
    while (i<=n)
    {
        fact=fact*i;
        i++;
    }
    printf(" factorial value is%d=%d\n",n,fact);
    return 0;
    
}


