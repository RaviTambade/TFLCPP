#include <iostream>
using namespace std;

class MathEngine{
    public :
            int addition(int op1, int op2){
                return op1+op2;
            }

            int subtraction(int op1, int op2){
                return op1-op2;
            }

           inline  int multiplication(int op1, int op2);
};


inline int MathEngine::multiplication(int op1, int op2){
        return op1 * op2;
}

inline int add(int op1, int op2){
    return op1+op2;
}

int main(){
    int num1=45;
    int num2=34;
    int result=add(num1, num2);
    cout<<"Result: "<< result<<endl;

    int value1=78;
    int value2=99;

    int data=add(value1, value2);
    cout<<"Result: "<< result<<endl;

    MathEngine engine;
    engine.addition(num1,num2);


}