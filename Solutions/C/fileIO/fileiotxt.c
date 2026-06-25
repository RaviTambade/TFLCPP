#include <stdio.h>

// Structure definition
struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

int main()
{
    struct Student s;
    FILE *fp;

    // Input
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Save to text file
    fp = fopen("studenttxt.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "%d %s %.2f\n", s.rollNo, s.name, s.marks);
    fclose(fp);

    // Read from text file
    fp = fopen("studenttxt.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d %49s %f", &s.rollNo, s.name, &s.marks);
    fclose(fp);

    // Display data
    printf("\nStudent Details:\n");
    printf("Roll Number : %d\n", s.rollNo);
    printf("Name        : %s\n", s.name);
    printf("Marks       : %.2f\n", s.marks);

    return 0;
}