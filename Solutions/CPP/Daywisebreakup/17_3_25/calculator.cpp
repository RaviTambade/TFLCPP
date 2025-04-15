

//Implement Calculation functionality using 
//Object Oriented way
//Implement Addition, Subtraction, Division, Multiplication
//with two numbers and each operation return result

//Test functionality in main by creating object of 
//Calculator class

#include <iostream>
using namespace std;

class Calculator{

    public:
           int  addition(int op1, int op2){
                int result=op1+op2;
                return result;
            }
            
            int  subraction(int op1, int op2){
                int result=op1-op2;
                return result;
            }

            int  multiplication(int op1, int op2){
                int result=op1*op2;
                return result;
            }
            
            int  division(int op1, int op2){
                int result=op1/op2;
                return result;
            }
};

int main(){
    int option=1;
    int result=0;
    Calculator calc;
    int num1=55;
    int num2=40;
    while(1){
        cout<<"Choose option :"<<endl;
        cout<<"Option 1: Addition"<<endl;
        cout<<"Option 2: Subtraction"<<endl;
        cout<<"Option 3: Multiplication"<<endl;
        cout<<"Option 4: Division"<<endl;
        cout<<"Option 5: Exit"<<endl;

        cin>>option;
        
        switch(option){
            case 1:
                result=calc.addition(num1,num2);
            break;
            case 2:
                result= calc.subraction(num1,num2);
            break;
            case 3:
                result=calc.multiplication(num1,num2);
            break;
            case 4:
                result=calc.division(num1,num2);
            break;
            case 5:
                 return 0;
            break;
        }

        cout<<"Result="<<result<<endl;  
    }
    return 0;
}