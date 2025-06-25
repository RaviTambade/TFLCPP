#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ODBC: Open Database Connectivity (API) for accessing databases
//#include <mysql.h>
//user defined data type
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;


int main() {
     
    int count=34;
    char ch='A';
    float f=3.14f;
    double d=2.718281828459045;
    char str[] = "Hello, World!";
    printf("Integer: %d\n", count);
    printf("Character: %c\n", ch);  
    printf("Float: %.2f\n", f);
    printf("Double: %.15f\n", d);

    printf("String: %s\n", str);
    int str_len = sizeof(str) / sizeof(str[0]);
    int length=strlen(str);
    printf("Length of string: %d\n", length);
    for(int i = 0; i < 5; i++) {
       
        printf("Character at index %d: %c\n", i, str[i]);
    }

    printf("Size of string array: %d\n", str_len);  
   
    Student student;

    student.id = 1; 
    strcpy(student.name, "John Doe");
    student.age = 20;
    student.gpa = 3.75f;
    printf("Student ID: %d\n", student.id);
    printf("Student Name: %s\n", student.name); 

    //Dynamic memory allocation
    // Allocate memory for an array of 5 Student structures
    Student *students = (Student *)malloc(5 * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
    // Initialize the first student
    students[0].id = 1; 
    strcpy(students[0].name, "Sanika Bhor");
    students[0].age = 21;
    students[0].gpa = 3.85f;
   

     // Initialize the Second student
    students[1].id = 2; 
    strcpy(students[1].name, "Sarthak Kadam");
    students[1].age = 22;
    students[1].gpa = 3.85f;
   
    //iterate through the array of students
    for (int i = 0; i < 5; i++) {
        printf("Student %d ID: %d\n", i + 1, students[i].id);
        printf("Student %d Name: %s\n", i + 1, students[i].name);
        printf("Student %d Age: %d\n", i + 1, students[i].age);
        printf("Student %d GPA: %.2f\n", i + 1, students[i].gpa);
    }

    //free the allocated memory
    if(students != NULL) {
        free(students);
    }
   

    return 0;
}