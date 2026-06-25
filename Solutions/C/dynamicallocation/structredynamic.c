# include <stdio.h>
# include <string.h>
# include <stdlib.h>



struct Student {
    int rollNo;
    char name[50];
    float marks;
};


int main(){


    // Elements with valuess are pushed to Stack
    
    struct Student s1;          // pushed on stack
    s1.rollNo=2;
    s1.marks=89;
    strcpy(s1.name, "Jayen");

    printf("\n  s1 from Stack\n");
    printf("\n ID= %d ", s1.rollNo);
    printf("\n Name= %s ", s1.name);
    printf("\n Marks= %f ", s1.marks);

    //Heap Dynamic memory allocation on heap

    int numberOfBytes=sizeof(struct Student);
    struct  Student * ptrStudent = (struct  Student *)malloc (numberOfBytes);  //allocate memory on heap
    if(ptrStudent == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    ptrStudent->rollNo=56;
    strcpy(ptrStudent->name,"Aarush");
    ptrStudent->marks=99;

    printf("\n  s1 from Stack\n");
    printf("\n ID= %d ", ptrStudent->rollNo);
    printf("\n Name= %s ", ptrStudent->name);
    printf("\n Marks= %f ", ptrStudent->marks);

    return 0;
}