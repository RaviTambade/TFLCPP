#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
//a Task
void print_hello() {
    while(true){
        cout << "Hello from a secondary thread 1!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }       
}


void print_Bye() {
        while(true){
            cout << "Bye from a secondary thread 2!" << endl;
           this_thread::sleep_for(chrono::seconds(5));
        }
}


//Characteristics of Sucn Operating Enviornment (System)
//is called as MultiTasking

//Multitasking is acheived using MultiThreading

//Process
// A Program under execution


//Process can contain more than one threads whil in exeuction state
//Each process has primary Thread 
//Primary Thread is responsible to invoking main function

// Within main function , code can allow multiple secondary Threads to 
//be created and perform multiple task exeuction concurrently.


//Thread
//a path of execution

//Program exeuction would contain two threads
//Primary Thread
//Secondary Thread
int main() {

    //Delegation;
    //Outsource
    //assign resposibility of exeuction task to another thread

    cout<<"Primary Thread Exeuction is started."<<endl;
    thread tHello(print_hello);  // Start a new thread
    thread tBye(print_Bye);
    tHello.join();  // Wait for the thread to finish
    tBye.join();
    cout<<"Primary Thread Execution is about to terminate"<<endl;
    return 0;
}
