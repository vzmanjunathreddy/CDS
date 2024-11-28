/*

Types of operations in Linked List are 

1. Traversing --> Accessing each element of a linked list
2. Insertion 
3. Deletion
4. Search
5. Sort 
Pointer holding an address of anonther pointer --> double pointer
*/ 
#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;

 
};

// create a newNode

struct Node* createNode(int data){
  struct Node* newNode= (struct Node*)malloc(sizeof(struct  Node));
  newNode->data=data;
  newNode->next=NULL;
  return newNode;
}

void insertNodeatBegeninig(struct Node **head, int data){

    struct Node *newNode=createNode(data);
    newNode->next=*head;
    *head=newNode; 

}

void insertNodeatEnd(struct Node **head, int data){

    struct Node *newNode=createNode(data);

    if(*head==NULL){
        *head=newNode;
         return;
    }
    struct Node* temp =*head;
    while (temp->next!=NULL)
    {
        temp= temp->next; 
    }
    
    temp->next=newNode;

}

void insertNodeatPostion(struct Node **head, int data,int position){

    struct Node *newNode=createNode(data);

    if(position==0){
        insertNodeatBegeninig(head,data);
        return;

    }
     
    struct Node* temp =*head;

    for(int i=0;temp!=NULL && i<position-1;i++){
         temp= temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;
   }

   