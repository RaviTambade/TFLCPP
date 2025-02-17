# include <stdio.h>
# include <stdbool.h>
#include <stdlib.h>
int runs=670;
void draw (){
    int timecount=6700;
    printf("runs=%d",runs);
}
void diaplay(){
    printf("runs=%d",runs);
}
int main(){
      bool status=false;
      int marks =90;
      char ch='t';
      float result=97.5;

      int* ptr1=&marks;
      int* ptr2=&marks;
      int * ptr=(int *)malloc(sizeof(int));
     if ( ptr==NULL){
        printf("memory allocation ids failed \n");
        return 1;

     } 
    *ptr=30;
    printf("value pointed to a ptr :%d\n",*ptr);
    printf("\n runs=%d",runs);
    printf("\n marks=%d",marks);
    printf("data of ptr1=%d",*ptr1);
    printf("data of ptr2=%d",*ptr2);
    printf("data of ptr=%d",*ptr);
    printf("welcome to transflower");
    free(ptr);


}