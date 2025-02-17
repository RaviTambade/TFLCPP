#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[100];
    int age;
};

void writetofile(const char *pfilename) {
    if (pfilename == NULL) {
        printf("Error: Invalid file name.\n");
        return;
    }

    struct student student;
    char choice;

    do {
        printf("Enter student ID: ");
        scanf("%d", &student.id);

        printf("Enter student name: ");
        getchar(); // Clear newline left by scanf
        fgets(student.name, sizeof(student.name), stdin);
        student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline

        printf("Enter student age: ");
        scanf("%d", &student.age);

        FILE *pfile = fopen(pfilename, "ab");
        if (pfile == NULL) {
            printf("Error: Unable to open file.\n");
            return;
        }

        fwrite(&student, sizeof(struct student), 1, pfile);
        fclose(pfile);

        printf("Do you want to enter another student (y/n)? ");
        getchar(); // Clear input buffer
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
}

void readtofile(const char *pfilename) {
    FILE *pfile = fopen(pfilename, "rb");
    if (pfile == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    struct student Student;
    printf("\nTransflower Student Details:\n");
    while (fread(&Student, sizeof(struct student), 1, pfile)) {
        printf("Student ID: %d\n", Student.id);
        printf("Student Name: %s\n", Student.name);
        printf("Student Age: %d\n", Student.age);
        printf("------------------------------\n");
    }

    fclose(pfile);
}

int main() {
    const char *pfilename = "student.dat";
    writetofile(pfilename);
    readtofile(pfilename);
    return 0;
}
