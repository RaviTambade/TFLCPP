//Problem definition:
//1.Accept student information from user 
//2.store it in a text file.
//3.Read the student information from the text file 
//4.display it.

//1 1.Accept student information from user 
//a. Define a structure to store student information
//b. Accept student information from user
//c. Display student information

//2. store it in a text file.
//a. Define a function to write student information to a text file

//3. Read the student information from the text file
//a. Define a function to read student information from a text file

#include <stdio.h>

//a. Define a structure to store student information
struct Student{
    char name[100];
    int age;
    int marks;
};

//Reusability
//set of reusable functions to perform operations on student structure


void display(struct Student s){
    printf("Student Information\n");
    printf("Name:%s\n",s.name);
    printf("Age:%d\n",s.age);
    printf("Marks:%d\n",s.marks);
}

void acceptInput(struct Student *s){
    printf("Enter student name:");
    scanf("%s",s->name);
    printf("Enter student age:");
    scanf("%d",&s->age);
    printf("Enter student marks:");
    scanf("%d",&s->marks);
}

void writeStudentToFile(struct Student s){
    FILE * pFile=NULL;
    pFile=fopen("student.txt","w"); //text mode
    if(pFile==NULL){
        printf("file not opened\n");
        return;
    }
    fprintf(pFile,"Name:%s\n",s.name);
    fprintf(pFile,"Age:%d\n",s.age);
    fprintf(pFile,"Marks:%d\n",s.marks);
    fclose(pFile);
}

void readStudentFromFile() {
    FILE * pFile=NULL;
    pFile=fopen("student.txt","r"); //text mode
    if(pFile==NULL){
        printf("file not opened\n");
        return;
    }
    struct Student s;
    char buffer[100];
    while(fgets(buffer,100,pFile)!=NULL){
        printf("%s",buffer);
    }
    fclose(pFile);
}

int main(){

    //struct Student s1;
    //acceptInput(&s1);  //passing address of s1
    //display(s1);    //passing value of s1
    //writeStudentToFile(s1);
    readStudentFromFile();
    return 1;
}