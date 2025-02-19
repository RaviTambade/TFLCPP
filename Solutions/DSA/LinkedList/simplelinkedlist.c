#include <stdio.h>
//Linked List Implementation
//Steps:
//1.Define the Node Structure
struct  Node {
    int data;               //information
    struct  Node * ptrNext; //pointer to the next node
};

//2.Function to Create a New Node
struct Node * createNode(int value){
    struct Node * ptrNode=(struct Node *)malloc(sizeof(struct Node));
    ptrNode->data=value;
    ptrNode->ptrNext=NULL;
    return ptrNode;
}

//3.Function to insert node at the end of the list

void insertNode(struct Node** ptrHead, int value)
{
    struct Node * ptrNewNode=createNode(value);
    if( *ptrHead ==NULL){

        *ptrHead=ptrNewNode;
        return;
    }
    struct Node *ptrTemp=*ptrHead;
    while(ptrTemp->ptrNext != NULL){
        ptrTemp=ptrTemp->ptrNext;
    }
    ptrTemp->ptrNext=ptrNewNode;
}
//4.Function to print the list

  void printList(struct Node *ptrHead){
    struct Node * ptrTemp=ptrHead;
    while(ptrTemp->ptrNext != NULL){
        printf(" %d  -> ", ptrTemp->data);
        ptrTemp=ptrTemp->ptrNext;
    }
    printf("NULL\n");
  }
//5. Function to delete a Node from existing Linked List
//6. Main function to test the linked List

int main(){
    struct Node * head=NULL;
    insertNode(&head, 76);
    insertNode(&head, 55);
    insertNode(&head, 87);
    insertNode(&head, 86);
    insertNode(&head, 12);

    printList(head);
}


