
/*
* 12
Title: Transflower Learning has student's club named 'TAP Club'.
       Students of Second, third and final year of Engineering can be granted membership on request. 
       Similarly one may cancel the membership of club. 
       First node is reserved for president of club and last node is reserved for secretary of club. 
       Write C++ program to maintain club member‘s information using singly linked list. 
       Store student PRN and Name. 
       Write functions to
                    a)Add and delete the members as well as president or even secretary. b)Compute total number of members of club
                    c)Display members
                    d)Display list in reverse order using recursion
                    e) Two linked lists exists for two divisions. Concatenate two lists
*/

//Solution:

//Declare header file
#include <iostream>
#include <stdio.h>
#include<string.h>

using namespace std;

//Declare  structure

struct node {
    int prn;        //student prn number
    char name[20];  //student name
    node* next;     //node pointer
};



//Define Class

class PanClub {
private:
    int num;
    int count;
    char members[30];
    node* head;

public:
    PanClub();
    node * create();
    void display(node *);
    node * concat(node *, node *); //Memeber Functions with arguments
    void reverse(node *);
    node * insert_president(node *);
    void insert_sec(node *);
    void insert_member(node *);
    node* del_president(node *);
    node* del_secretary(node *);
    node* del_member(node*);
};


//Class Implementatiopn

PanClub::PanClub() {

    cout << "\n Constructor is called....";

};

node* PanClub::create() {

    cout << "\n Panclub is created...";

    node* pNode = new node();
    //pNode->name = "RamBhau";

    return pNode;
}



//Entry Point Function
/*
int main()
{
    std::cout << "\n ***********************Hello World!**************************\n";
    int choice = 1;
    PanClub p1, p2, p3;
    node* h1, * h2, * h3;
    h1 = h2 = h3 = NULL;
   
   do {

        cout << "Choose Option from below:\n";
        cout << "\n 1. Enter Data";
        cout << "\n 2. Contace Data";
        cout << "\n 3. Display Data";
        cout << "\n 4. Exit";
        cout << "\n";

        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            cout << "You have selected Enter Data Option";

            PanClub* ptr_panClub1 = new PanClub();
            ptr_panClub1->create();
        }
        break;
        case 2: {
            cout << "You have selected concat Data Option";

        }
              break;
        case 3:
        {
            cout << "You have selected concat Data Option";
        }
        break;

        }
    }
     while (choice != 4);
    cout << "\nTerminating application.....";
}
*/