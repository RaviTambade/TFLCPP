# include <stdio.h>
struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

int main(){
 
    struct Student s1;
    FILE *  fp;

    //accept input from user from console window

    printf("\n Enter Roll Number: ");
    scanf("%d", &s1.rollNo);

    printf("\n Enter Name: ");
    scanf("%s", s1.name);

    printf("\n Enter Marks: ");
    scanf("%f", &s1.marks);

    //Write structure elememt into File 
    fp=fopen("student.dat","w");
    if(fp ==NULL){
        printf("Unable to open file.\n");
        return 1;
    }

    fwrite(&s1, sizeof(struct Student),1, fp);
    fclose(fp);

    //Read from File to struct s1 
    struct Student s2;
    fp=fopen("student.dat","r");
    fread(&s2, sizeof(struct Student),1,fp);
    fclose(fp);

    // Display data read from file
    printf("\nStudent Details Read from File:\n");
    printf("Roll Number : %d\n", s2.rollNo);
    printf("Name        : %s\n", s2.name);
    printf("Marks       : %.2f\n", s2.marks);
    return 0;
}