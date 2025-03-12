//Preprocessor (Macros): 
//               #include
//               #define
//               #ifnedef
//               #endif

#include <stdio.h>
#include <stdbool.h>

//variable declaration
//assigning value to varaibles
//Global variables

//data is defined by variable
bool status=false;
int count=56;   //variable
char ch='T';
//functions : a kind of task
//logic is defined by function
//cabin1


//function signature:


void sayHello(){
    //code block
    printf("Hello Sarthak\n");
    printf("welcome to Transflower\n");
    printf("Learning is self exploring process.\n");
}

//cabin2
void sayNamaste(){
    //code block
    printf("Ram Ram Sarthak\n");
    printf(" Suwagatam to Transflower\n");
    printf("Learning is a self exploring process under the guidance of mentor\n");
    
}

//outparametertype  functionname  (input parameter1,  input parameter 2, input parmebter)

 bool doWork(){
    bool status=true;
    return status;
}

int add(int number1, int number2){
    int result=0;
    //result=number1 + number2;
    return result;
}

void calculate(int radius, float * ptrArea, float * ptrCircumference){
        *ptrArea=(3.14)* radius * radius;
        *ptrCircumference=2 * (3.14) * radius;
}




//entry point function
//main room //reception
//function implementation
//Main is standard function to  initiate execution
int main(){
    //exeuction will start from this line
    //code block :Main function logic implementation
    int sum=45;
    bool isEmployeed=false;
    printf("Hello World!\n"); //function call
    sayHello();  //calling function, invoking function, method call
                 //link function sayHello sothat control will pass to sayHello function block
    sayNamaste();//calling function

    char m= 'M';
}