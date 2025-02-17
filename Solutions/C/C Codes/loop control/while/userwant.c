#include <stdio.h>
int main  (){
    int num ;
    int count_positive =0;
    int count_negative =0;
    int count_zero=0;
    char choice;
    do{
    printf ("enterr the number");
    scanf ("%d",&num);
        if (num >0){
            printf("positive  number");
            count_positive++;
        }else if (num <0){
            printf ("negative number");
            count_negative++; //negative_count++; is a concise way to increment the value of negative_count by 1
        }else{
       printf ("countzero");
       count_zero++;
    }
    printf("do you want to continue? y/n: \n");
    scanf (" %c",&choice); //// Note the space before %c to consume any leftover newline character
    }
while(choice=='y'||choice=='Y');
    {
        printf("positive number=%d\n",count_positive);
        printf("negative number =%d\n",count_negative );
        printf("count_zero=%d\n",count_zero);
    }
    return 0;
}
