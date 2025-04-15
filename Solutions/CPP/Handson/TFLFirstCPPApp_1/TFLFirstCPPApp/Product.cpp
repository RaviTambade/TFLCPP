
#include "Product.h"
//implementation

//create list of product
void Product::CreateList(int sizeOfArray)
{
    this->sizeOfArray = sizeOfArray;
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> list[i];
    }
}

//bubble sort logic
//because in binary search first we have to sort all elements of array in asecding order
void Product::SortList()
{
    for (int j = 1; j < sizeOfArray; j++)
    {
        for (int i = 0; i < sizeOfArray - j; i++)
        {
            if (list[i] > list[i + 1])
            {
               string swapElement = list[i];
                list[i] = list[i + 1];
                list[i + 1] = swapElement;
            }
        }
    }
}

//search product logic
bool Product::SearchProduct(string dataToSearch)
{
    bool status = false;
    int firstElement = 0;
    int lastElement = sizeOfArray - 1;
    int midElement = (lastElement + lastElement) / 2;

    while (dataToSearch != list[midElement] && firstElement <= lastElement)
    {
        if (dataToSearch > list[midElement])
        {
            firstElement = midElement + 1;
        }
        else
        {
            lastElement = midElement - 1;
        }
        midElement = (firstElement + lastElement) / 2;
    }

    if (firstElement <= lastElement)
    {
        status = true;
    }
    return status;
}
