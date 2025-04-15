#include <iostream>
#include  "marksheet.h"

using  namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void displayTransflower()
{
 		printf("\n Welcome Transflower");
		printf("\n Learn by doing");
		printf("\n 601, Rama Apartment");
		printf("\n Walwekar Nagar");
		printf("\n Pune Satara Road");	
		printf("\n Parvati, Pune 411009");		
}

//Entry point function
int main(int argc, char** argv) {
	
	//Printing data on console windows
	
	printf("\n Welcome to C++");
	std::cout<<"\n  Doing ordinary things extra oridnarily.....";
	
	int count=67;
	
	//Accept input from console
	std::cout<<" Enter new number ";
	std:cin>>count;
	
	count++;
	std::cout<< " result= "<<count;
	
	displayTransflower();
	
	//Object created on stack
	//memory is used belong to Stack
	Marksheet m1;
	Marksheet m2(34,45,27, "Jeevan");
	
	m1.showResult();
	m2.showResult();	
	
	//Object is created on heap
	//Dynamic memory allocation
	
	
	Marksheet * pmarkSheet= new Marksheet(78,67,54, "Shiv");
	pmarkSheet->showResult();
	
	
	
	return 0;
}
