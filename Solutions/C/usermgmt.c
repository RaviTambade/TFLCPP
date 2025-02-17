#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Data Structure
struct Student {
    int id;
    char name[100];
    int age;
};

//other functions
 
int getChoiceFromMenu()
{
    int choice;
    printf("******************************");
    printf("\n Options for Students Managment:\n");
    printf("1.Create new User /t ");
    printf("2.Display existing Users/t");
    printf("3.Exit\n");
    printf("******************************");
    printf("\nEnter your choice : ");
    scanf("%d",&choice );
    return choice;
}

void displayStudent( struct Student student){
    printf("\n Student Details\n");
    printf("\n ID: %d\n", student.id);
    printf("\n Name: %s\n", student.name);
    printf("\n Age: %d\n", student.age);
    printf("------------------------------\n");
}

struct Student acceptStudentDetails(){
    struct Student student;
    printf("New Students Details for registration:\n");
    printf("\nEnter student ID: ");
    scanf("%d", &student.id);
    printf("Enter student name: ");
    getchar(); // Clear newline left by scanf
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline
    printf("Enter student age: ");
    scanf("%d", &student.age);
    return student;
}

void writeToFile(const char *pfilename, struct Student stdnt) {
    if (pfilename == NULL) {
        printf("Error: Invalid file name.\n");
        return;
    }
    FILE *pfile = fopen(pfilename, "ab");
    if (pfile == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    fwrite(&stdnt, sizeof(struct Student), 1, pfile);
    fclose(pfile);
}
         
struct Student getFromFile(const char *pfilename) {
    struct Student student;
    FILE *pfile = fopen(pfilename, "rb");
    if (pfile == NULL) {
        printf("Error: Unable to open file.\n");
        return student;
    }
    else{
        while (fread(&student, sizeof(struct Student), 1, pfile)) {
            displayStudent(student);
        }
        fclose(pfile);
    }
    return student;
}

//global function :Entry Point
int main() {
    const char *pfilename = "student.info";
    int choice;
    do {    
        choice=getChoiceFromMenu();
        switch (choice)
        {
            //Insert new user
            case 1:{
                struct Student theStudent=acceptStudentDetails();
                writeToFile(pfilename, theStudent);
                displayStudent(theStudent);
            }
            break;

            //Display all users
            case 2:{
                struct Student theStudent=getFromFile(pfilename);  
                displayStudent(theStudent);
            }       
            break;

            //exit from Application
            case 3: 
                printf ("Thank you for using Student Management System.");
            break;  

            default:
                printf("\ninvalid choice plz try again\n");
                break;
            }
    } 
    while (choice !=3);
    return 0;
}
