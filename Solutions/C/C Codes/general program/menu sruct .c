#include <stdio.h>
#include <stdlib.h>

 void create (int ** ptrarry,int * ptrsize);
 void read (int *ptrarr,int size);
 void update (int *ptrarr,int size);
 int search (int *ptrarr,int size,int theElement);
 void  delete (int **ptrarr,int *size);

int main(){
       
    int *ptrArray=NULL ;
    int option=1 ;
    int size=0;
     printf("welcome to dynamic array\n");

  

    
       while (1)
       {
         printf("1.create\n");
         printf("2.read\n");
         printf("3.update\n");
         printf("4.search\n");
         printf("5.exit\n");
         scanf("%d",&option);

       
       
        switch (option)
        {
          case 1:
              printf("create\n");
              create(&ptrArray,&size );
          break;
          case 2:
              printf("read\n");
              read(ptrArray,size);
          break;
          case 3:
              printf("update\n");

          break;
          case 4:
              printf("search\n");
              int element,result;
              printf("enter your element");
              scanf("%d",&element);
              result=search(ptrArray,size,element);
              if (result==-1){
                printf("element is not found\n");
              }else{
                printf("your element = %d\n",result);
              }
              break;
          case 5:
             printf("exit\n");
             return 0;
          default:
              printf("option is invalid\n") ;       
          }
    
        }
    }
void create(int **ptrarray,int*ptrsize){
int newsize;
printf(" enter the number elements to add");
scanf("%d",&newsize);
*ptrarray=realloc(*ptrarray,sizeof(*ptrsize+newsize)*sizeof(int));
if (*ptrarray==NULL){
    printf("memory allocation failed");
    exit(1);
}
for(int i=*ptrsize;i<*ptrsize+newsize;i++){
    printf("enter a element %d\n",i+1);
    scanf("%d",&(*ptrarray)[i]);
}
*ptrsize+=newsize;
printf("element added.\n");
}

void read (int * ptrarray,int size){
    printf("array element");
    for(int i=0;i<size;i++){
        printf("%d",ptrarray[i]);
    }
    printf("\n");
}
 int search(int *ptrArr, int size, int theElement) {
    for (int i = 0; i < size; i++) {
        if (ptrArr[i] == theElement) {
            return ptrArr[i];  // Return the index of the found element
        }
    }
    return -1;  // Return -1 if the element is not found
}








