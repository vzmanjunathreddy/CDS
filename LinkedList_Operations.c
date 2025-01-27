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

   void deleteatheBegening(struct Node **head)
   {
          if(*head==NULL){
            printf("List is empty");
            return;
          }
          struct Node *temp =*head;
          *head=temp->next;
          free(temp);
       
   }

   void deleteathEnd(struct Node **head)
   {
          if(*head==NULL){
            printf("List is empty");
            return;
          }

          struct Node *temp =*head;  

           //there is only one node
          if(temp->next==NULL){
            free(temp);// this guy is deleting memory address reffered by head
            // *head --> Dangling pointer --> a pointer whose memory address is already released 
             *head=NULL;// Null Pointer
          }
         
          while (temp->next->next!=NULL)
          {
            temp=temp->next;
          }
          
          free(temp->next);
          temp->next=NULL;
     
   }

      void deleteNodeatPosition(struct Node **head,int position)
   {
          if(*head==NULL){
            printf("List is empty");
            return;
          }

          struct Node *temp =*head;  

        if(position==0){
            deleteatheBegening(head);
        }

        for(int i=0;i<position-1 && temp!=NULL;i++){
           temp=temp->next;
        }
       
        if(temp->next==NULL || temp==NULL){
            printf("Position is out of range.. \n");
        }
         struct Node *next= temp->next->next;
         free(temp->next);
          temp->next=next;
                   
     
   }

     void TraversetheNodes(struct Node* head){

        struct Node *temp=head;

        while(temp!=NULL){
            printf("Node data is %d \n", temp->data);
            temp=temp->next;
        }
   
     }

   int main(){
  
     struct Node *head=NULL;
     insertNodeatBegeninig(&head,10);
     insertNodeatEnd(&head,12);
     insertNodeatBegeninig(&head,5);
     insertNodeatPostion(&head,7,1);
     TraversetheNodes(head);
     deleteathEnd(&head);
     printf("After deleting the end node traversed data is \n");
     TraversetheNodes(head);
   }



