#include <iostream>
using  namespace std;
//Entry point function
int main(int argc, char** argv) {	
	int marks=80;			//int variable
	int * ptrMarks=NULL;	//integer pointer variable   
	ptrMarks= &marks;	
	
	int  ** ptr=NULL;		//integer pointer to pointer variable 
	ptr=&ptrMarks;   		//ptr now holds address of ptrMarks
	
	printf( "\n marks value = %d", marks);
	printf( "\n ptrMarks address = %d", ptrMarks);
	printf( "\n ptrMarks pointing to variable value = %d", *ptrMarks);
	printf( "\n ptr  address = %d", ptr);
	printf( "\n ptr pointing to pointer which pointing to varialbe has value = %d", **ptr);
	return 0;
}
