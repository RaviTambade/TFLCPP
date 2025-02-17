#include "SinglyLinkList.h"
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList(int nodes)
{
    int data;
    Node* ptrCurrent;
    ptrHead = NULL;

    cout << "\nEnter data:";
    cin >> data;

    ptrHead = (Node*)malloc(sizeof(Node));
    ptrHead->data = data;
    ptrHead->ptrNext = NULL;
    ptrCurrent = ptrHead;

    for (int i = 2; i <= nodes; i++)
    {
        cout << "\nEnter  data";
        cin >> data;
        ptrCurrent->ptrNext = (Node*)malloc(sizeof(Node));
        ptrCurrent = ptrCurrent->ptrNext;
        ptrCurrent->data = data;
        ptrCurrent->ptrNext = NULL;
    }
    cout << "\n linked list with " << nodes << " nodes created successfully.....";
}

void LinkedList::Print()
{
    Node* ptrCurrent;
    ptrCurrent = ptrHead;
    cout << "\n Printing all data from linked List";
    while (ptrCurrent != NULL)
    {
        cout << "->" << ptrCurrent->data;
        ptrCurrent = ptrCurrent->ptrNext;
    }
}

bool LinkedList::Contains(int data)
{
    bool status = false;
    Node* ptrCurrent = NULL;
    ptrCurrent = ptrHead;
    while (ptrCurrent != NULL)
    {
        if (ptrCurrent->data == data)
        {
            status = true;
            break;
        }
        ptrCurrent = ptrCurrent->ptrNext;
    }
    return status;
}

bool  LinkedList::InsertAtFirst(int data)
{
    bool status = false;
    Node* ptrNode;
    //creating new node 
    ptrNode = (Node*)malloc(sizeof(Node));
    ptrNode->data = data;
    ptrNode->ptrNext = NULL;
    if (ptrHead == NULL)
    {
        ptrHead = ptrNode;
    }
    else
    {
        ptrNode->ptrNext = ptrHead;
        ptrHead = ptrNode;
    }
    status = true;
    return status;
}

bool  LinkedList::InsertAtLast(int data)
{
    bool status = false;
    Node* ptrNode, * ptrCurrent;

    //Creating new node
    ptrNode = (Node*)malloc(sizeof(Node));
    ptrNode->data = data;
    ptrNode->ptrNext = NULL;

    if (ptrHead == NULL)
    {
        ptrHead = ptrNode;
    }
    else
    {
        ptrCurrent = ptrHead;
        while (ptrCurrent->ptrNext != NULL)
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }
        ptrCurrent->ptrNext = ptrNode;
    }
    status = true;
    return status;
}

bool LinkedList::InsertAt(int location, int data)
{
    bool status = false;
    Node* ptrCurrent, * ptrNode = NULL;

    ptrNode = (Node*)malloc(sizeof(Node));
    ptrNode->data = data;
    ptrNode->ptrNext = NULL;

    if (ptrHead == NULL)
    {
        ptrHead = ptrNode;
    }
    else
    {
        ptrCurrent = ptrHead;
        for (int i = 1; i < location - 2; i++)
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }
        ptrNode->ptrNext = ptrCurrent->ptrNext;
        ptrCurrent->ptrNext = ptrNode;
        cout << "data inserted at middle";
    }
    status = true;
    return status;
}

bool LinkedList::RemoveFromFirst()
{
    bool status = false;
    Node* ptrNode;
    int x;
    if (ptrHead == NULL)
    {
        cout << "\n linked list is empty";
    }
    else
    {
        ptrNode = ptrHead;
        ptrHead = ptrHead->ptrNext;
        free(ptrNode);
        cout << "data deleted at bigining";
        status = true;
    }
    return status;
}

bool  LinkedList::RemoveFromLast()
{
    bool status = false;
    Node* ptrNode, * ptrCurrent;
    if (ptrHead == NULL)
    {
        cout << "\n linked list is empty";
    }
    else
    {
        ptrCurrent = ptrHead;
        while (ptrCurrent->ptrNext->ptrNext != NULL)
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }
        ptrNode = ptrCurrent->ptrNext;
        ptrCurrent->ptrNext = NULL;
        free(ptrNode);
        cout << "data deleted at end";
        status = true;
    }
    return status;
}

bool  LinkedList::RemoveAt(int location)
{
    bool status = false;
    Node* ptrNode, * ptrCurrent;

    if (ptrHead == NULL)
    {
        cout << "\n linked list is empty";
    }
    else
    {
        ptrCurrent = ptrHead;
        for (int i = 0; i < location - 1; i++)
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }
        ptrNode = ptrCurrent->ptrNext;
        ptrCurrent->ptrNext = ptrNode->ptrNext;

        free(ptrNode);
        status = true;
        cout << "data deleted at mid";
    }
    return status;
}



/*
int main()
{
    LinkedList i1;
    Node* ptrHead=NULL;
    int ch, no;
    cout << "\n*******menu***********";
    cout << "\n1.creation";
    cout << "\n2.print";
    cout << "\n3.search";
    cout << "\n4.insertion at begining";
    cout << "\n5.insertion at end";
    cout << "\n6.insertion at middle";
    cout << "\n7.deletion at begining";
    cout << "\n8.deletion at end";
    cout << "\n9.deletion at mid";
    do
    {
        cout<<"\n enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout<<"\n enter no of Nodes: ";
            cin >> no;
            ptrHead = i1.creation(no);
            break;
        case 2:
            i1.printing(ptrHead);
            break;
        case 3:
            i1.searching(ptrHead);
            break;
        case 4:
            ptrHead = i1.InsertAtFirst(ptrHead);
            break;
        case 5:
            ptrHead = i1.InsertAtLast(ptrHead);
            break;
        case 6:
            ptrHead = i1.InsertInBetween(ptrHead);
            break;
        case 7:
            ptrHead = i1.RemoveFromFirst(ptrHead);
            break;
        case 8:
            ptrHead = i1.RemoveFromLast(ptrHead);
            break;
        case 9:
            ptrHead = i1.RemoveInbetween(ptrHead);
            break;

        case 10:
            return 0;
        dafault:
            cout<<"\n inavalid choice";
        }
    } while (ch != 10);
    return 0;
}
*/