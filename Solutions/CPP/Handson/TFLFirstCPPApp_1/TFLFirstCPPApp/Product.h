#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


//decaration
class Product
{
    //memeber variable
private:
    string list[10];
    int sizeOfArray;

    //member function
public:
    void CreateList(int sizeOfArray);
    void SortList();
    bool SearchProduct(string dataToSearch);

};