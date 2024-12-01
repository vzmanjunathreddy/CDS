// Linked List is a Linear DS 
// Linked List 
/* 
  1. Single Linked List 
        two parts ==> Data and next (address of next node)
  2. Double Linked List
  3. Circular Linked List

  Points to Note :

  Head is the frist Node
  Next=Null means its going to be last node

  How exatly its going to work is 

  1. Initalize 
  2. Allocate Memory 
  3. Assign the data values
  4. Connect the nodes

  */

 #include<stdio.h>
 #include<stdlib.h>

 struct Node {

    int data;
    struct Node *next;
    struct Node *prev;

    
 };

//Traversing the Linked List
printLinkedListData(struct Node *headNode){
  struct Node* tempNode =headNode;

  do{
    printf("Node data is %d \n",tempNode->data);
    tempNode=tempNode->next;
  }
  while(headNode!=tempNode);
}
 int main(){

 // Initialize the Nodes

  struct Node *head;

  struct Node *firstNode=NULL;
  struct Node *secondNode=NULL;
  struct Node *thirdNode=NULL;

//  Allocate the Memory

 firstNode= malloc(sizeof(struct Node));
 secondNode= malloc(sizeof(struct Node));
 thirdNode= malloc(sizeof(struct Node));

 // Assign the values

firstNode->data=10;
secondNode->data=20;
thirdNode->data=30;


//Connect Nodes
firstNode->next=secondNode;
firstNode->prev=thirdNode;

secondNode->next=thirdNode;
secondNode->prev=firstNode;

thirdNode->next=firstNode;
thirdNode->prev=secondNode;

//Now head is referring to first node
head=firstNode;

printLinkedListData(head);

 }

