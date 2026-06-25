#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};


int main() {

 int n, i;

printf("Enter number of students: ");
scanf("%d", &n);

// Dynamically allocate memory for n students
struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

 // Input student details
for (i = 0; i < n; i++) {
    printf("\nStudent %d\n", i + 1);

    printf("Enter Roll No: ");
    scanf("%d", &students[i].rollNo);

    printf("Enter Name: ");
    scanf("%s", students[i].name);

    printf("Enter Marks: ");
    scanf("%f", &students[i].marks);
}


// Display student details
printf("\n--- Student Records ---\n");
for (i = 0; i < n; i++) {
    printf("\nRoll No: %d", students[i].rollNo);
    printf("\nName: %s", students[i].name);
    printf("\nMarks: %.2f\n", students[i].marks);
}

free(students);
}


/*
struct Student groups student-related data.
malloc() allocates memory for n students at runtime.
students is a pointer to the first structure in the dynamically allocated array.
free() releases the allocated memory when it's no longer needed.


*/