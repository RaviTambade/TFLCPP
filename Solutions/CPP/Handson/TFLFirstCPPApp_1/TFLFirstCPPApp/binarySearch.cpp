#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/*
int main()
{
    int a[10], i, j, num, n, mid, temp;
    cout << "enter size of array: ";
    cin>>n;

    cout<<"enter elements in array: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //bubble sort logic
     for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
          
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }


    cout << "enter data to search: ";
    cin >> num;


    i = 0;
    j = n - 1;
    mid = (i + j) / 2;

    while (num != a[mid] && i <= j)
    {
        if (num > a[mid])
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
        mid = (i + j) / 2;
    }
    if (i <= j)
    {
        cout << "\n element is found...........";
    }
    else
    {
        cout << "\nelement is not found........";
    }
    return 0;
}
*/