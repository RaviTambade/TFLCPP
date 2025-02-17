
#include <stdio.h>
int main(){

 
    //DSA: Data Structure and Algorithm

    //Different Types of Data Structures:
    //Array, Linked List, Stack, Queue, Tree, Graph

    //Algorithm: Step by step procedure to solve a problem

    //Person:Al-Khwarizmi (persian mathematician 9th century)
    //Al-Khwarizmi: Father of Algebra
    //Different Types of Algorithms:
    //Sorting, Searching, Insertion, Deletion, Updation

    //What is Array: Array is
    //array of integers (inbuilt data type)
    //array of characters (inbuilt data type)
    //array of float
    //array of double
    //array of students (user defined data type)
    //array of employees (user defined data type)

    //Array is a data structure
    //Array is a collection of similar data types
    //Array has contiguous memory locations
    //Array has fixed size

    //Types of Array: 
    //1. Static Array 
    //2. Dynamic Array

    //Static Array
    //static array: array size is fixed
    //static array: memory is allocated at compile time
    //static array: memory is allocated in stack memory
    
    int studentMarks[5] = {76, 56, 89,77, 85};
    int index;
    for(index = 0; index < 5; index++){
        printf("%d\n", studentMarks[index]);
    }
    return 0;
}