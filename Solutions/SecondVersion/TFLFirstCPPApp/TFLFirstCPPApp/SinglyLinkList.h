#pragma once
#include "Node.h"

class LinkedList
{
    private:
        Node* ptrHead;

    public:
        LinkedList(int nodes);
                                        //create linklist with number of nodes
        void  Print();                  //print all nodes of linkedList
        bool  Contains(int data);       //search a specific node
        bool  InsertAtFirst(int data);
        bool  InsertAtLast(int data);
        bool  InsertAt(int location, int data);
        bool  RemoveFromFirst();
        bool  RemoveFromLast();
        bool  RemoveAt(int location);
};
