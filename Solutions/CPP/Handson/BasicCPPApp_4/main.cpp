#include <iostream>
using namespace  std;
//object oriented programming
//Method overloading
//overloading is a kind of static polymorphism
//overloading is a kind of compile time polymorphism
//overloading is taken place within a class
class MathEngine {

public:
	  //Method overloading (function overloading)
	  //constructor overloading
	  //default constructor
	  MathEngine(){
	  	//implemention logic
	  }
	  
	  //parameterized constructor
	  MathEngine(int op1, int op2){
	  	//implementation logic differnt
	  	
	  }
	  
	
	  int add(int num1, int num2){
			return num1 + num2;
	  }
		 
	  int add(int num1, int num2, int num3){
		 	return num1+ num2 + num3;
	  }
};



int main(){
	MathEngine * pMathEngine=new MathEngine();
	int result=pMathEngine->add(56,76);
	cout<<"Result="<<result;
	
	int output=pMathEngine->add(67,87,90);
	cout<<"Output="<<output;
	
}
