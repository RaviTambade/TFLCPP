#include <stdio.h>
int main(){
printf("Mathematical table creation\n");
int number =2;
printf("%d\n", number);
for(int i=1; i<=10;i++){
    int multFactor=i;
    int result=number *multFactor;
    printf("%d * %d = %d  \n", number, multFactor,result);  
}
}