#include <stdio.h>
//Callback mechanism
//Function that takes a function pointer as an argument
void execute(void (*callback)()) {
    callback();  // Call the passed function
}

// Define functions
void walk() {
    printf("Walking!\n");
}

void run() {
    printf("Running!\n");
}

int main() {
    // Pass function pointers to execute
   // execute(walk);    // Prints "Walking!"
   //  execute(run); // Prints "Running!"
    
    //Declare array of function pointers
    int marks[5];
    void (*ptrFunction[2]) ()={ walk, run};
    
    for(int i=0;i<3;i++){
    	ptrFunction[i]();
	}
    return 0;
}

