#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


//decaration
class Data
{
    //memeber variable
private:
    string list[10], swapElement;
    int sizeOfArray;

    //member function
public:
    void CreateList(int sizeOfArray);
    void SortList();
    void SortedData();

};