#include <stdio.h>

struct Point{
        int x;
        int y;
};

struct Student
{
    int rollNumber;          // Integer
    char name[100];          // Character array (string)
    char gender;             // Single character
    short age;               // Short integer
    long admissionNumber;    // Long integer

    float percentage;        // Floating-point number
    double cgpa;             // Double-precision floating-point

    unsigned int marks;      // Unsigned integer
    int isActive;            // Boolean-like flag (0 = false, 1 = true)
};

struct Policy
{
    int PolicyId;
    char PolicyNumber[20];
    char CustomerName[100];
    char PolicyType[50];      // Health, Life, Motor, etc.
    float PremiumAmount;
    int TermInYears;
    int IsActive;             // 1 = Active, 0 = Inactive
    int IsRenewed;            // 1 = Renewed, 0 = Not Renewed
    char StartDate[11];       // Format: YYYY-MM-DD
    char ExpiryDate[11];      // Format: YYYY-MM-DD
};

struct Color{
    int red;
    int green;
    int blue;
};


int myResult=987;  //global variable

//global function

int main()
{ 

    int result=78;
    int * ptrResult=&result;    //pointer to integer variable

    printf("\n Value of result = %d", result);
    printf("\n address of result = %d", &result);
    printf("\n address of result = %d", ptrResult);
    printf("\n value of variable pointed by  result = %d", *ptrResult);

    char ch='C';            
    char *ptrChar=&ch;        //pointer to character variable

    printf("\n Value of ch = %c", ch);
    printf("\n address of resule = %d", ptrChar);
    printf("\n value of variable pointed by  result = %d", *ptrChar);

    struct Point center;        //declare variable center of type Point structure
    center.x=78;                //initialize x value of center
    center.y=99;                //initiaize y value of center

    struct Point *ptrCenter=&center;    //pointer to structure Point variable
                                        //store address of center  inside pointer variable  ptrCenter



    struct Student student1= {101,"Amit Sharma",'M',20,2026001234L,89.5f,9.12,450,1};

    struct Student *ptrs1=&student1;

    

    printf("Roll Number      : %d\n", student1.rollNumber);
    printf("Name             : %s\n", student1.name);
    printf("Gender           : %c\n", student1.gender);
    printf("Age              : %hd\n", student1.age);
    printf("Admission Number : %ld\n", student1.admissionNumber);
    printf("Percentage       : %.2f\n", student1.percentage);
    printf("CGPA             : %.2lf\n", student1.cgpa);
    printf("Marks            : %u\n", student1.marks);
    printf("Active           : %d\n", student1.isActive);


    struct Policy policy;

    policy.PolicyId = 101;
    strcpy(policy.PolicyNumber, "POL1001");
    strcpy(policy.CustomerName, "Ravi Tambade");
    strcpy(policy.PolicyType, "Health");
    policy.PremiumAmount = 15000.50f;
    policy.TermInYears = 5;
    policy.IsActive = 1;
    policy.IsRenewed = 0;
    strcpy(policy.StartDate, "2026-01-01");
    strcpy(policy.ExpiryDate, "2031-01-01");

    printf("Policy Number : %s\n", policy.PolicyNumber);
    printf("Customer Name : %s\n", policy.CustomerName);
    printf("Policy Type   : %s\n", policy.PolicyType);
    printf("Premium       : %.2f\n", policy.PremiumAmount);
    printf("Active        : %d\n", policy.IsActive);

    struct Policy *ptrPolicy=&policy;
    return 0;
}