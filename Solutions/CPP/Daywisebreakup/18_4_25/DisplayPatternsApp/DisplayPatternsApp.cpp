 
#include <iostream>

int main()
{
	int lineCounter = 10;
	for (int i = 0; i<10; i++)
	{ 
		for (int j = 1; j < lineCounter; j++) {
			int num = j % 2;
			if (num == 0)
				printf(" ");
			else
				printf("*");
		}
			
		lineCounter--;
		printf("\n");
		 
	}
} 