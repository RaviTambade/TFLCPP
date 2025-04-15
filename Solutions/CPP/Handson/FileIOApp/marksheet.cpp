#include<string.h>
#include <iostream>
using namespace std;
#include "marksheet.h"


//Implementation File

Marksheet::Marksheet()
{
	this->english=0;
	this->marathi=0;
	this->hindi=0;
	strcpy(this->student, "Raj");
	
}


Marksheet::Marksheet(int e, int m ,int h, char nm[])
{
	this->english=e;
	this->marathi=m;
	this->hindi=h;
   	strcpy(this->student, nm);
	
}

void Marksheet::showResult(){
	cout << "\n Student Name:"<<this->student;
	cout << "\n English:"<<this->english;
	cout << "\n Marathi:"<<this->marathi;
	cout << "\n Hindi:"<<this->hindi;
	
}
Marksheet::~Marksheet()
{
}
