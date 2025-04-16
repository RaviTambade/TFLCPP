// TestPostPreFixing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int marks[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
		std::cout << marks[i] << " ";
	std::cout << std::endl;

	cout << "Postfixing\n";

	// Postfix increment
	//means first use the value and then increment

	int index = 3;
	marks[index++] = 10;



	for (int i = 0; i < 5; i++)
		std::cout << marks[i] << " ";
	std::cout << std::endl;




    std::cout << "Hello World!\n";
}
 