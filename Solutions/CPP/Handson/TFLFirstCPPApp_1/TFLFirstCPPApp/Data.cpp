#include "Data.h"
void Data::CreateList(int sizeOfArray)
{
    this->sizeOfArray = sizeOfArray;
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> list[i];
    }
}

void Data::SortList()
{

    for (int j = 1; j < sizeOfArray; j++)
    {
        for (int i = 0; i < sizeOfArray - j; i++)
        {
            if (list[i] > list[i + 1])
            {
                swapElement = list[i];
                list[i] = list[i + 1];
                list[i + 1] = swapElement;
            }
        }
    }
}

void Data::SortedData()
{

    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << "\t" << list[i];
    }
}



